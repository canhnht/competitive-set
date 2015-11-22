//This is getting accepted!
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
typedef pair<int, int> pii;
typedef pair<int, pii> ppi;

const double PI = acos(0) * 2;
const ll MOD = 1000000007;
const int MAXN = 3e4 + 5;
const int oo = 1e9;

int T, M, N;
int a[MAXN];
multiset<int> ms;

int main(){
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
    	scanf("%d%d", &M, &N);
    	for (int i = 0; i < M; ++i) scanf("%d", a + i);
    	ms.clear();    	
    	ms.insert(a[0]);
    	multiset<int>::iterator it = ms.begin();
    	int start = 1, u;
    	for (int i = 0; i < N; ++i) {
    		scanf("%d", &u);
    		for (; start < u; ++start) {
    			ms.insert(a[start]);
    			if (i <= start && *it > a[start]) --it;
    		}
    		if (i) ++it;
    		if (i < u) {
    			printf("%d\n", *it);
    		} else {
    			printf("%d\n", *ms.rbegin());
    		}
    	}
    	if (T) printf("\n");
    }
    return 0;
}