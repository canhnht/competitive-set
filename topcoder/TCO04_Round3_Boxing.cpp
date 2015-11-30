#include <bits/stdc++.h>

using namespace std;

class Boxing {
public:
	int maxCredit(vector<int> a, vector<int> b, vector<int> c, vector<int> d, vector<int> e);
};

typedef pair<int, int> pii;

const int MAXN = 1e3 + 5;

pii t[MAXN];
int N;
bool used[5];

void addToT(vector<int> &v, int);

int Boxing::maxCredit(vector<int> a, vector<int> b, vector<int> c, vector<int> d, vector<int> e) {
	N = 0;
	addToT(a, 0);
	addToT(b, 1);
	addToT(c, 2);
	addToT(d, 3);
	addToT(e, 4);
	sort(t, t + N);
	int res = 0;
	for (int i = 0; i < N; ++i) {
		memset(used, 0, sizeof used);
		int cnt = 0;
		int k = i;
		used[t[i].second] = true;
		++cnt;
		while (k + 1 < N && cnt < 3 && t[k + 1].first - t[i].first <= 1000) {
			++k;
			if (!used[t[k].second]) {
				used[t[k].second] = true;
				++cnt;
			}
		}
		if (cnt >= 3) {
			++res;
			i = k;			
			while (i + 1 < N && t[i + 1].first == t[i].first) ++i;
		}		
	}
	return res;
}

void addToT(vector<int> &v, int type) {
	for (int i = 0; i < v.size(); ++i) {
		t[N++] = make_pair(v[i], type);
	}
}