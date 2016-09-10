#include <bits/stdc++.h>

using namespace std;

class GoldMine {
public:
	vector<int> getAllocation(vector<string> mines, int miners);
};

const int MAXN = 55;
const int EPS = 1e-7;

int N;
int a[MAXN][10], p[MAXN][10];
int cur[MAXN];

vector<int> GoldMine::getAllocation(vector<string> mines, int miners) {
	N = mines.size();
	for (int i = 0; i < N; ++i) {
		stringstream ss(mines[i]);
		char ch;
		for (int k = 0; k < 6; ++k) {
			ss >> a[i][k] >> ch;
		}
		ss >> a[i][6];
	}	

	for (int i = 0; i < N; ++i) {
		for (int k = 1; k <= 6; ++k) {
			p[i][k - 1] = 0;
			for (int d = 0; d <= 6; ++d) {
				if (k < d) p[i][k - 1] += a[i][d] * 60 * k;
				else if (k == d) p[i][k - 1] += a[i][d] * 50 * k;
				else p[i][k - 1] += a[i][d] * (50 * d - 20 * (k - d));
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int k = 5; k > 0; --k) p[i][k] -= p[i][k - 1];
	}
	/*
	for (int i = 0; i < N; ++i) {
		for (int k = 0; k < 6; ++k) cout << p[i][k] << " ";
		cout << endl;
	}
	*/
	vector<int> res(N);
	memset(cur, 0, sizeof cur);
	while (miners--) {
		int maxP = -1;
		for (int i = 0; i < N; ++i) {
			if (cur[i] == 6) continue;
			if (maxP == -1 || p[maxP][cur[maxP]] + EPS < p[i][cur[i]]) {
				maxP = i;
			}
		}
		res[maxP] += 1;
		++cur[maxP];
	}
	return res;
}