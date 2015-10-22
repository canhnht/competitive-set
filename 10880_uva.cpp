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
const int MAXN = 1e6 + 5;
const int oo = 1e9;

int N;
int C, R;
int res[MAXN], cnt;

int main(){
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
    	printf("Case #%d:", i);
    	scanf("%d%d", &C, &R);
    	if (C == R) {
    		printf(" 0\n");
    	} else {
    		C -= R;
    		cnt = 0;
    		for (int k = 1; k <= sqrt(C); ++k) {
    			if (C % k == 0) {
    				if (k > R) {
    					res[cnt++] = k;
    				}
    				if (k != C / k && C / k > R) {
    					res[cnt++] = C / k;
    				}
    			}
    		}
    		sort(res, res + cnt);
    		for (int i = 0; i < cnt; ++i) printf(" %d", res[i]);
    		printf("\n");
    	}
    }
    return 0;
}