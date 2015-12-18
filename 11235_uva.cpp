//This is getting accepted!
#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
typedef pair<int, int> pii;
typedef pair<int, pii> pip;

const double PI = acos(0) * 2;
const ll MOD = 1000000007;
const int MAXN = 1e5 + 5;
const int oo = 1e9;
const int MAXS = 20;

int n, q, nc;
int a[MAXN];
pip c[MAXN];
int rmq[MAXN][MAXS];

void buildRMQ();
int get(int, int);
int posC(int);

int main(){
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (scanf("%d", &n), n) {
    	scanf("%d", &q);
    	for (int i = 0; i < n; ++i) scanf("%d", a + i);
    	nc = 0;
    	for (int i = 0; i < n; ++i) {
    		c[nc] = make_pair(a[i], make_pair(0, 0));
    		int k = i;
    		while (k + 1 < n && a[k + 1] == a[k]) {    			
    			++k;
    		}
    		c[nc].second = make_pair(i, k);
    		++nc;
    		i = k;
    	}
    	buildRMQ();
    	int x, y;
    	while (q--) {
    		scanf("%d%d", &x, &y);
    		--x;
    		--y;
    		int cx = posC(x);
    		int cy = posC(y);
    		// cout << "cc " << cx << " " << cy << endl;
    		if (cx == cy) printf("%d\n", y - x + 1);
    		else {
    			int res = c[cx].second.second - x + 1;
    			res = max(res, y - c[cy].second.first + 1);
    			if (cx + 1 <= cy - 1) res = max(res, get(cx + 1, cy - 1));
    			printf("%d\n", res);
    		}
    	}
    }
    return 0;
}

void buildRMQ() {
	for (int i = nc - 1; i >= 0; --i) {
		rmq[i][0] = c[i].second.second - c[i].second.first + 1;
		int k;
		for (k = 1; i + (1 << (k - 1)) < nc; ++k) {
			rmq[i][k] = rmq[i][k - 1];
			rmq[i][k] = max(rmq[i][k], rmq[i + (1 << (k - 1))][k - 1]);
		}
		for (; k < MAXS; ++k) rmq[i][k] = rmq[i][k - 1];
	}
}

int get(int lo, int hi) {
	int len = hi - lo + 1;
	int p2 = 0;
	while ((1 << (p2 + 1)) <= len) ++p2;
	return max(rmq[lo][p2], rmq[hi - (1 << p2) + 1][p2]);
}

int posC(int p) {
	int lo, hi;
	lo = 0;
	hi = nc - 1;
	while (lo < hi) {
		int mid = (lo + hi) >> 1;
		if (c[mid].second.second < p) lo = mid + 1;
		else hi = mid;
	}
	return lo;
}