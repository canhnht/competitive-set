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
const int MAXN = 1e2 + 5;
const int oo = 1e9;

int t, n, m;
int a[MAXN][MAXN];
int cnt[1 << 10];

int main(){
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &t);
    while (t--) {
    	scanf("%d%d", &n, &m);
    	for (int i = 0; i < n; ++i) {
    		for (int k = 0; k < m; ++k) {
    			scanf("%d", &a[i][k]);
    		}
    	}
    	bool res = true;
    	memset(cnt, 0, sizeof cnt);
    	for (int k = 0; k < m; ++k) {
    		int p = 0;
    		for (int i = 0; i < n; ++i) p += a[i][k];
    		if (p != 2) {
    			res = false;
    			break;
    		}
    		int state = 0;
    		for (int i = 0; i < n; ++i) {
    			if (a[i][k]) state |= (1 << i);
    		}
    		++cnt[state];
    	}
    	for (int i = 1; i < (1 << n); ++i) {
    		if (cnt[i] > 1) {
    			res = false;
    			break;
    		}
    	}
    	if (res) printf("Yes\n");
    	else printf("No\n");
    }
    return 0;
}