#include <bits/stdc++.h>

using namespace std;

class PolygonTraversal2 {
public:
	int count(int N, vector<int> p);
};

const int MAXN = 20;

int nPoint;
bool vis[MAXN];
int res, start, sz;

void recursion(int, int);

int PolygonTraversal2::count(int N, vector<int> p) {
	if (p.size() == 2) return 0;
	nPoint = N;
	memset(vis, 0, sizeof vis);
	for (int i = 0; i < p.size(); ++i) vis[p[i]] = true;	
	res = 0;
	start = p[0];
	sz = p.size();
	recursion(0, p[p.size() - 1]);
	return res;
}

void recursion(int id, int prev) {
	if (id == nPoint - sz) {
		int dist = (prev - start + nPoint) % nPoint;
		if (dist != 1 && dist != nPoint - 1) ++res;
		return;
	}
	int lo, hi;
	if (prev == 1) lo = nPoint;
	else lo = prev - 1;
	while (lo >= 1 && !vis[lo]) --lo;
	if (lo == 0) {
		lo = nPoint;
		while (lo >= 1 && !vis[lo]) --lo;
	}
	if (prev == nPoint) hi = 1;
	else hi = prev + 1;
	while (hi <= nPoint && !vis[hi]) ++hi;
	if (hi > nPoint) {
		hi = 1;
		while (hi <= nPoint && !vis[hi]) ++hi;
	}
//	cout << id << " " << lo << " " << hi << endl;
	int i = hi;
	while (i != lo) {
		if (!vis[i]) {
			vis[i] = true;
			recursion(id + 1, i);
			vis[i] = false;
		}
		if (i == nPoint) i = 1;
		else ++i;
	}
}