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

map<int, int> order;
map<int, int> cnt;

int main(){
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int x, id = 0;
    cnt.clear();
    order.clear();
    while (scanf("%d", &x) == 1) {
    	if (cnt.count(x)) cnt[x] += 1;
    	else {
    		cnt[x] = 1;
    		order[id++] = x;
    	}
    }

    for (map<int, int>::iterator it = order.begin(); it != order.end(); ++it) {
    	printf("%d %d\n", it->second, cnt[it->second]);
    }
    return 0;
}