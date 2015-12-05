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

int m, n;
vector<pii> res[MAXN];
pii row[MAXN];

int main(){
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (cin >> m >> n) {    	    	
    	for (int i = 1; i <= n; ++i) res[i].clear();
    	for (int k = 1; k <= m; ++k) {
    		int r;
    		scanf("%d", &r);
    		for (int i = 0; i < r; ++i) scanf("%d", &row[i].first);
    		for (int i = 0; i < r; ++i) scanf("%d", &row[i].second);
    		for (int i = 0; i < r; ++i) res[row[i].first].push_back(make_pair(k, row[i].second));
    	}
    	printf("%d %d\n", n, m);
    	for (int i = 1; i <= n; ++i) {
    		printf("%d", (int)res[i].size());
    		sort(res[i].begin(), res[i].end());
    		for (int k = 0; k < res[i].size(); ++k) printf(" %d", res[i][k].first);
    		printf("\n");
    		for (int k = 0; k + 1 < res[i].size(); ++k) printf("%d ", res[i][k].second);
    		if (res[i].size() > 0)
    			printf("%d", res[i][res[i].size() - 1].second);
    		printf("\n");
    	}
    }
}