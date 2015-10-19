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
const int MAXL = 1e4 + 5;
const int oo = 1e9;

int N, K, M;
char name[MAXN][MAXL];
char line[MAXL];
int value[MAXN];
int res;

int main(){
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &N);
    while (N--) {
    	scanf("%d", &K);
    	for (int i = 0; i < K; ++i) scanf("%s%d", name[i], value + i);
    	scanf("%d%*c", &M);
    	res = 0;
    	while (M--) {
    		cin.getline(line, MAXL);    		
    		int len = strlen(line);
    		for (int i = 0; i < K; ++i) {
    			int temp = strlen(name[i]);
    			for (int k = 0; k + temp <= len; ++k) {
    				bool cmp = true;
    				for (int p = 0; p < temp; ++p) {
    					if (name[i][p] != line[k + p]) {
    						cmp = false;
    						break;
    					}
    				}
    				if (cmp) res += value[i];
    			}
    		}
    	}
    	printf("%.2lf$\n", res / 100.0);
    }
    return 0;
}