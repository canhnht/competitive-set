#include <bits/stdc++.h>

using namespace std;

class TCSocks {
public:
	int earnMoney(vector<int> money, vector<string> c, vector<string> t, vector<string> com);
};

typedef pair<int, int> pii;

const int MAXN = 15;
const int MAXS = 1 << MAXN;
const int MAXT = 200;

int N;
int w[MAXN][MAXN], tt[MAXN][MAXN];
int profit[MAXN][MAXT];
pii dp[MAXS][MAXN];

vector<int> paths[MAXN];

int TCSocks::earnMoney(vector<int> money, vector<string> c, vector<string> t, vector<string> com) {
	N = money.size();
	for (int i = 0; i < c.size(); ++i) {
		stringstream ss(c[i]);
		for (int k = 0; k < N; ++k) {
			ss >> w[i][k];
		}
	}	
	for (int i = 0; i < t.size(); ++i) {
		stringstream ss(t[i]);
		for (int k = 0; k < N; ++k) {
			ss >> tt[i][k];
		}
	}	
	memset(profit, 0, sizeof profit);
	for (int i = 0; i < com.size(); ++i) {
		stringstream ss(com[i]);
		int x, prev = 0, cnt = 0;
		while (ss >> x) {
			cnt += tt[prev][x];
			profit[x][cnt] += 1;
			prev = x;
		}
	}
	for (int i = 0; i < N; ++i) {
		int p = money[i];
		for (int k = 0; k < MAXT; ++k) {
			p >>= profit[i][k];
			profit[i][k] = p;
		}
	}
	memset(dp, -1, sizeof dp);
	dp[1][0] = make_pair(0, 0);
	int res = 0;
	for (int i = 2; i < (1 << N); ++i) {
		for (int k = 0; k < N; ++k) {
			if ((i >> k) & 1) {
				int prev = i ^ (1 << k);
				if (prev > 0) {
					for (int p = 0; p < N; ++p) {
						if ((prev >> p) & 1 && dp[prev][p].first > -1) {
							if (dp[i][k].first < dp[prev][p].first - w[p][k] + profit[k][dp[prev][p].second + tt[p][k]]) {
								dp[i][k].first = dp[prev][p].first - w[p][k] + profit[k][dp[prev][p].second + tt[p][k]];
								dp[i][k].second = dp[prev][p].second + tt[p][k];
							} else if (dp[i][k].first == dp[prev][p].first - w[p][k] + profit[k][dp[prev][p].second + tt[p][k]] && dp[i][k].second > dp[prev][p].second + tt[p][k]) {
								dp[i][k].second = dp[prev][p].second + tt[p][k];
							}
						}
					}
				}
//				cout << i << " " << k << " " << (dp[i][k].first - w[k][0]) << endl;
				res = max(res, dp[i][k].first - w[k][0]);
			}
		}
	}
	return res;
}