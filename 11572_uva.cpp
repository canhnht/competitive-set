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

int T, N;
vector<int> a;
map<int, int> mapper;
int res;

int main(){
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
    	scanf("%d", &N);
    	a.clear();
    	mapper.clear();
    	int x, start = 0;
    	res = 0;
    	for (int i = 0; i < N; ++i) {
    		scanf("%d", &x);
    		a.push_back(x);
    		if (mapper.count(x)) {
    			int pos = mapper[x];
    			for (; start <= pos; ++start) {
    				mapper.erase(a[start]);
    			}
    		}
    		mapper[x] = i;
    		res = max(res, (int)mapper.size());
    	}
    	printf("%d\n", res);
    }
    return 0;
}