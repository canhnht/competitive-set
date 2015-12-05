#include <bits/stdc++.h>

using namespace std;

class Crossroads {
public:
	vector<int> getOut(vector<int> a);
};

const int MAXN = 105;

int N;
bool res[MAXN];

vector<int> Crossroads::getOut(vector<int> a) {
	N = a.size();
	memset(res, 1, sizeof res);
	for (int i = 0; i < N; ++i) {
			for (int k = i + 1; k < N; ++k) {
				if (a[i] < a[k]) {
					if (a[i] >= 180 - a[k]) res[k] = false;
					else {
						res[i] = false;
					}
				}
			}
	}
	vector<int> b;
	b.clear();
	for (int i = 0; i < N; ++i) {
		if (res[i]) b.push_back(i);
	}
	return b;
}