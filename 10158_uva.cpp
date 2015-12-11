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
const int MAXN = 1e4 + 5;
const int oo = 1e9;

int n;
int d[MAXN];
int enemy[MAXN];

int root(int);
int unite(int, int);

int main(){
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) d[i] = enemy[i] = -1;
    int c, x, y;
    while (scanf("%d%d%d", &c, &x, &y), c) {
        // cout << "input " << x << " " << y << " -- ";
    	int rx = root(x);
    	int ry = root(y);
    	// cout << c << " " << rx << " " << ry << endl;
    	if (c == 1) {	// set friends    		
    		if (enemy[x] == ry || enemy[y] == rx) {
    			printf("-1\n");
    		} else {
    			if (rx != ry) {
    				unite(rx, ry);
    			}
    		}
    	} else if (c == 2) {	// set enemies
    		if (rx == ry) {
    			printf("-1\n");
    		} else {
    			if (enemy[ry] == -1) enemy[ry] = rx;
    			else if (rx != enemy[ry]) enemy[ry] = unite(rx, enemy[ry]);
    			if (enemy[rx] == -1) enemy[rx] = ry;
    			else if (ry != enemy[rx]) enemy[rx] = unite(ry, enemy[rx]);
    		}
    	} else if (c == 3) {	// are friends
    		printf("%d\n", rx == ry);
    	} else {	// are enemies
    		// cout << "case4 " << rx << " " << ry << " -- " << (enemy[rx] == ry) << " " << enemy[ry] << endl;
            printf("%d\n", enemy[rx] == ry);
    	}
    }
    return 0;
}

int root(int u) {    
	if (d[u] < 0) return u;
	return d[u] = root(d[u]);
}

int unite(int u, int v) {
	if (u == v) return u;
	if (d[u] < d[v]) {
		d[u] += d[v];
		d[v] = u;
		return u;
	} else {
		d[v] += d[u];
		d[u] = v;
		return v;
	}
}