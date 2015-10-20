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

int N, W, H;
int BIT[MAXN][MAXN];

void update(int, int, int);
int get(int, int);

int main(){
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (scanf("%d%d%d", &W, &H, &N), W || H || N) {
    	memset(BIT, 0, sizeof BIT);
    	int x1, y1, x2, y2;
    	for (int i = 0; i < N; ++i) {
    		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    		if (x1 > x2) swap(x1, x2);
    		if (y1 > y2) swap(y1, y2);
    		update(x1, y1, 1);
    		update(x2 + 1, y1, -1);
    		update(x1, y2 + 1, -1);
    		update(x2 + 1, y2 + 1, 1);
    	}
    	int res = 0;
    	for (int i = 1; i <= W; ++i) {
    		for (int k = 1; k <= H; ++k) {
    			// cout << i << " " << k << " " << get(i, k) << endl;
    			res += get(i, k) == 0;
    		}
    	}
    	if (res == 0) printf("There is no empty spots.\n");
    	else if (res == 1) printf("There is one empty spot.\n");
    	else printf("There are %d empty spots.\n", res);
    }
    return 0;
}

void update(int x0, int y0, int v) {
	for (int x = x0; x <= W; x += x & -x) {
		for (int y = y0; y <= H; y += y & -y) {
			BIT[x][y] += v;
		}
	}
}

int get(int x0, int y0) {
	int ret = 0;
	for (int x = x0; x; x -= x & -x) {
		for (int y = y0; y; y -= y & -y) {
			ret += BIT[x][y];
		}
	}
	return ret;
}