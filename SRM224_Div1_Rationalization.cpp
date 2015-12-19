#include <bits/stdc++.h>

using namespace std;

class Rationalization {
public:
	int minTweaks(vector<int> w, vector<string> s, int d);
};

const int MAXN = 25;

int nW, nS, want;
int a[MAXN][MAXN];
int ww[MAXN], idw[MAXN];
int res;

int minDec(int);
int calc();
void recursion(int, int);

int Rationalization::minTweaks(vector<int> w, vector<string> s, int d) {
	nW = w.size();
	nS = s.size();
	want = d;
	for (int i = 0; i < nS; ++i) {
		for (int k = 0; k < nW; ++k) a[i][k] = s[i][k] - '0';
	}
	for (int i = 0; i < nW; ++i) ww[i] = w[i];
	res = 1e9;
	recursion(0, 0);
	if (res == int(1e9)) return -1;
	return res;
}

void recursion(int id, int cnt) {
	if (id == nW) {
//		cout << "cnt " << cnt << endl;
		res = min(res, cnt + calc());
		return;
	}
	recursion(id + 1, cnt);
	if (ww[id] < 9) {
		++ww[id];
		recursion(id + 1, cnt + 1);
		--ww[id];
	}
	if (ww[id] > 1) {
		--ww[id];
		recursion(id + 1, cnt + 1);
		++ww[id];
	}
}

bool cmp(int x, int y) {
	return ww[x] > ww[y];
}

int calc() {
	for (int i = 0; i < nW; ++i) idw[i] = i;
	sort(idw, idw + nW, cmp);
	int cur = 0;
	for (int i = 0; i < nW; ++i) {
		cur += a[want][i] * ww[i];
	}
//	cout << "cur " << cur << endl;
	int temp = minDec(cur);
	int ret = 1e9;
	if (temp != -1) ret = min(ret, temp);
	int cnt = 0;
	for (int i = 0; i < nW; ++i) {
		if (a[want][idw[i]] < 9) {
			cur += ww[idw[i]];
//			cout << "cur " << cur << endl;
			temp = minDec(cur);
//			cout << "temp " << temp << endl;
			++cnt;
			if (temp != -1) ret = min(ret, cnt + temp);
		}
	}
//	cout << "calc " << ret << endl;
	return ret;
}

int minDec(int cur) {
	int ret = 0;
	for (int i = 0; i < nS; ++i) {
		if (i == want) continue;
		int sum = 0;
		for (int k = 0; k < nW; ++k) {
			sum += a[i][k] * ww[k];
		}
//		cout << i << " " << sum << endl;
		for (int k = 0; sum >= cur && k < nW; ++k) {
			if (a[i][idw[k]] > 1) {
				sum -= ww[idw[k]];
				++ret;
			}
		}
//		cout << "---" << ret << " " << sum << endl;
		if (sum >= cur) return -1;
	}
	return ret;
}