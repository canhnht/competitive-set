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
int a[5];
map<string, int> mapper;

int main(){
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (scanf("%d", &n), n) {
    	mapper.clear();
    	for (int i = 0; i < n; ++i) {
    		for (int k = 0; k < 5; ++k) scanf("%d", a + k);
    		sort(a, a + 5);
    		string temp = "";
    		for (int k = 0; k < 5; ++k) {
    			temp += char('0' + a[k] % 10);
    			temp += char('0' + a[k] / 10 % 10);
    			temp += char('0' + a[k] / 100);
    		}
    		if (mapper.count(temp)) mapper[temp] += 1;
    		else mapper[temp] = 1;
    	}
    	int maxV = 0, cnt = 0;
    	for (map<string, int>::iterator it = mapper.begin(); it != mapper.end(); ++it) {
    		if (maxV == it->second) {
    			++cnt;
    		} else if (maxV < it->second) {
    			maxV = it->second;
    			cnt = 1;
    		}
    	}
    	int res = maxV * cnt;
    	printf("%d\n", res);
    }
    return 0;
}