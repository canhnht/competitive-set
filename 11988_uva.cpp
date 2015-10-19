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
const int MAXN = 1e5 + 5;
const int oo = 1e9;

char line[MAXN];
list<char> res;
int dir;

int main(){
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (scanf("%s", line) == 1) {
    	res.clear();
    	dir = 1;
    	for (int i = 0; line[i]; ++i) {
    		if (line[i] == '[') {
    			dir = 0;
    		} else if (line[i] == ']') {
    			dir = 1;
    		} else {
    			if (dir) {    				
    				while (line[i] && line[i] != '[' && line[i] != ']') {
    					res.push_back(line[i]);
    					++i;
    				}    	    				
    			}
    			else {
    				int k = i;
    				while (line[i] && line[i] != '[' && line[i] != ']') {    					
    					++i;
    				}    	
    				for (int p = i - 1; p >= k; --p) res.push_front(line[p]);    				
    			}
    			--i;
    		}
    	}
    	while (!res.empty()) {
    		printf("%c", res.front());
    		res.pop_front();
    	}
    	printf("\n");
    }
    return 0;
}