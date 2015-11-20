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

int T, N, M;
set<int> a[MAXN];
int res[100];

int main(){
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
    	printf("Case %d:", t);
    	scanf("%d", &N);
    	for (int i = 0; i < MAXN; ++i) a[i].clear();
    	for (int i = 0; i < N; ++i) {
    		scanf("%d", &M);
    		int x;
    		for (int k = 0; k < M; ++k) {
    			scanf("%d", &x);
    			a[x].insert(i);
    		}
    	}
    	for (int i = 0; i < N; ++i) res[i] = 0;
    	for (int i = 0; i < MAXN; ++i) {
    		if (a[i].size() == 1) {
    			res[*a[i].begin()] += 1;
    		}
    	}
    	int sum = 0;
    	for (int i = 0; i < N; ++i) sum += res[i];
    	if (sum > 0) {
    		for (int i = 0; i < N; ++i) {
	    		printf(" %.6lf%%", res[i] * 100.0 / sum);
	    	}
    	}
    	printf("\n");
    }
    return 0;
}