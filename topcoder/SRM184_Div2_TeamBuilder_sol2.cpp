#include <bits/stdc++.h>

using namespace std;

class TeamBuilder {
public:
	vector<int> specialLocations(vector<string> paths);
};

const int MAXN = 55;

int N;
bool a[MAXN][MAXN];

vector<int> TeamBuilder::specialLocations(vector<string> paths) {
	N = paths.size();
	for (int i = 0; i < N; ++i) {
		for (int k = 0; k < N; ++k) {
			a[i][k] = paths[i][k] == '1';
		}
	}
	for (int k = 0; k < N; ++k) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				a[i][j] = a[i][j] || (a[i][k] && a[k][j]);
			}
		}
	}
	vector<int> res(2, 0);
	for (int i = 0; i < N; ++i) {
		bool ok = true;
		for (int k = 0; k < N; ++k) {
			if (i != k)
				ok = ok && a[i][k];
		}
		res[0] += ok;
		ok = true;
		for (int k = 0; k < N; ++k) {
			if (i != k)
				ok = ok && a[k][i];
		}
		res[1] += ok;
	}
	return res;
}