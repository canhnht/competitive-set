#include <bits/stdc++.h>

using namespace std;

class Unblur {
public:
	vector<string> original(vector<string> blurred);
};

const int MAXN = 105;
const int dx[] = {0, 0, 0, -1, -1, -1, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

int R, C;
int a[MAXN][MAXN];

bool inside(int, int);

vector<string> Unblur::original(vector<string> blurred) {
	R = blurred.size();
	C = blurred[0].size();
	memset(a, -1, sizeof a);
	for (int i = 0; i < R; ++i) a[i][0] = a[i][C - 1] = 0;
	for (int i = 0; i < C; ++i) a[0][i] = a[R - 1][i] = 0;
	for (int d = 0; d <= R - 1 + C - 1; ++d) {
		for (int i = 0; i < R; ++i) {
			int k = d - i;
			if (k >= 0 && k < C) {
				int v = blurred[i][k] - '0';
				for (int t = 0; t < 9; ++t) {
					if (inside(i + dx[t], k + dy[t]) && a[i + dx[t]][k + dy[t]] != -1) {
						v -= a[i + dx[t]][k + dy[t]];
					}
				}
				for (int t = 0; t < 9; ++t) {
					if (inside(i + dx[t], k + dy[t]) && a[i + dx[t]][k + dy[t]] == -1) {
						a[i + dx[t]][k + dy[t]] = v;
						break;
					}
				}
			}
		}
	}
	vector<string> res(R, string(C, ' '));
	for (int i = 0; i < R; ++i) {
		for (int k = 0; k < C; ++k) {
			if (a[i][k] == 0) res[i][k] = '.';
			else res[i][k] = '#';
		}
	}
	return res;
}

bool inside(int x, int y) {
	return (x >= 0 && x < R && y >= 0 && y < C);
}