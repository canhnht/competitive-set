#include <bits/stdc++.h>

using namespace std;

class TCSocks {
public:
	int earnMoney(vector<int> money, vector<string> c, vector<string> t, vector<string> com);
};

typedef pair<int, int> pii;

const int MAXN = 12;
const int MAXS = 1 << MAXN;
const int MAXT = 150;

int N;
int w[MAXN][MAXN], tt[MAXN][MAXN];
int profit[MAXN][MAXT];
bool vis[MAXN];
int res;

vector<int> paths[MAXN];

void recursion(int, int, int);

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
			p = p >> profit[i][k];
			profit[i][k] = p;
		}
	}
	res = 0;
	memset(vis, 0, sizeof vis);
	vis[0] = true;
	recursion(0, 0, 0);
	return res;
}

void recursion(int u, int ct, int cp) {
	res = max(res, cp - w[u][0]);
	for (int i = 0; i < N; ++i) {
		if (!vis[i]) {
			vis[i] = true;
			recursion(i, ct + tt[u][i], cp - w[u][i] + profit[i][ct + tt[u][i]]);
			vis[i] = false;
		}
	}
}