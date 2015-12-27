//This is getting accepted!
#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
typedef pair<int, int> pii;
typedef pair<int, pii> ppi;

const double PI = acos(0) * 2;
const ll MOD = 1000000007;
const int MAXN = 5e2 + 5;
const int oo = 1e9;

int N, Q;
int a[MAXN][MAXN];
pii it[MAXN * MAXN * 8];

void build(int, int, int, int, int);
void pull(int);
void update(int, int, int, int, int, int, int, int);
pii get(int, int, int, int, int, int, int, int, int);
int inside(int, int, int, int, int, int);

int main(){
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
    	for (int k = 0; k < N; ++k) {
    		scanf("%d", &a[i][k]);
    	}
    }
    build(0, 0, 0, N - 1, N - 1);
    scanf("%d", &Q);
    char cmd[5];
    int x1, y1, x2, y2, x, y, v;
    while (Q--) {
    	scanf("%s", cmd);
    	if (cmd[0] == 'q') {
    		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    		--x1;
    		--y1;
    		--x2;
    		--y2;
    		pii res = get(0, 0, 0, N - 1, N - 1, x1, y1, x2, y2);
    		printf("%d %d\n", res.second, res.first);
    	} else {
    		scanf("%d%d%d", &x, &y, &v);
    		--x;
    		--y;
    		update(0, 0, 0, N - 1, N - 1, x, y, v);    		
    	}
    }
    return 0;
}

void build(int node, int x1, int y1, int x2, int y2) {
	if (x1 > x2 || y1 > y2) {
		it[node] = make_pair(+oo, -oo);
		return;
	}

	if (x1 == x2 && y1 == y2) {
		it[node] = make_pair(a[x1][y1], a[x1][y1]);
		return;
	}
	int mx = (x1 + x2) >> 1;
	int my = (y1 + y2) >> 1;
	int child = node * 4;
	build(child + 1, x1, y1, mx, my);
	build(child + 2, x1, my + 1, mx, y2);
	build(child + 3, mx + 1, y1, x2, my);
	build(child + 4, mx + 1, my + 1, x2, y2);
	pull(node);
}

void pull(int node) {
	it[node].first = +oo;
	it[node].second = -oo;
	int child = node * 4;
	for (int i = 1; i <= 4; ++i) {
		it[node].first = min(it[node].first, it[child + i].first);
		it[node].second = max(it[node].second, it[child + i].second);
	}
}

void update(int node, int x1, int y1, int x2, int y2, int x, int y, int v) {
	if (x < x1 || x > x2 || y < y1 || y > y2) return;
	if (x1 == x2 && y1 == y2) {
		it[node] = make_pair(v, v);
		return;
	}
	int mx = (x1 + x2) >> 1;
	int my = (y1 + y2) >> 1;
	int child = node * 4;
	update(child + 1, x1, y1, mx, my, x, y, v);
	update(child + 2, x1, my + 1, mx, y2, x, y, v);
	update(child + 3, mx + 1, y1, x2, my, x, y, v);
	update(child + 4, mx + 1, my + 1, x2, y2, x, y, v);
	pull(node);
}

pii get(int node, int x1, int y1, int x2, int y2, int xl, int yl, int xh, int yh) {
	if (xh < x1 || x2 < xl || yh < y1 || y2 < yl) return make_pair(+oo, -oo);
	if (inside(x1, y1, xl, yl, xh, yh) && inside(x2, y2, xl, yl, xh, yh)) return it[node];
	int mx = (x1 + x2) >> 1;
	int my = (y1 + y2) >> 1;
	int child = node * 4;
	pii v[4];
	v[0] = get(child + 1, x1, y1, mx, my, xl, yl, xh, yh);
	v[1] = get(child + 2, x1, my + 1, mx, y2, xl, yl, xh, yh);
	v[2] = get(child + 3, mx + 1, y1, x2, my, xl, yl, xh, yh);
	v[3] = get(child + 4, mx + 1, my + 1, x2, y2, xl, yl, xh, yh);
	pii ret = make_pair(+oo, -oo);
	for (int i = 0; i < 4; ++i) {
		ret.first = min(ret.first, v[i].first);
		ret.second = max(ret.second, v[i].second);
	}
	return ret;
}

int inside(int x, int y, int x1, int y1, int x2, int y2) {
	return (x1 <= x && x <= x2 && y1 <= y && y <= y2);
}