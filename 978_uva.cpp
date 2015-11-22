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

int N, B, SG, SB;
int g[MAXN], b[MAXN];
int tg[MAXN], tb[MAXN];

int main(){
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &N);
    while (N--) {
    	scanf("%d%d%d", &B, &SG, &SB);
    	int x;
    	memset(g, 0, sizeof g);
    	memset(b, 0, sizeof b);
    	for (int i = 0; i < SG; ++i) {
    		scanf("%d", &x);
    		++g[x];
    	}
    	for (int i = 0; i < SB; ++i) {
    		scanf("%d", &x);
    		++b[x];
    	}
    	while (SG && SB) {
    		memset(tb, 0, sizeof tb);
    		memset(tg, 0, sizeof tg);
    		// for (int i = MAXN - 1; i >= 0; --i) {
    		// 	for (int k = 0; k < g[i]; ++k) {
    		// 		printf("%d ", i);
    		// 	}
    		// }    		
    		// printf("\n");
    		// for (int i = MAXN - 1; i >= 0; --i) {
    		// 	for (int k = 0; k < b[i]; ++k) {
    		// 		printf("%d ", i);
    		// 	}
    		// }
    		// printf("\n");
    		// printf("============\n");
    		int cnt = 0;
    		for (int i = MAXN - 1, k = MAXN - 1; i >= 1 && cnt < B; ) {
    			int tempG, tempB;
    			tempG = tempB = 0;
    			if (g[i] > 0) {
    				while (k >= 1 && b[k] == 0) --k;
    				if (k >= 1) {
    					tempG = g[i] - min(g[i], B - cnt);
    					tempB = b[k] - min(b[k], B - cnt);
    					g[i] = min(g[i], B - cnt);
    					b[k] = min(b[k], B - cnt);
    					cnt += min(g[i], b[k]);
    					if (i == k) {
    						if (g[i] == b[k]) {
    							g[i] = b[k] = 0;    							
    						} else if (g[i] > b[k]) {
    							g[i] -= b[k];
    							b[k] = 0;
    						} else if (g[i] < b[k]) {
    							b[k] -= g[i];
    							g[i] = 0;
    						}
    					} else if (i > k) {
    						if (g[i] == b[k]) {
    							b[k] = 0;
    							tg[i - k] += g[i];
    							g[i] = 0;
    						} else if (g[i] > b[k]) {
    							g[i] -= b[k];
    							tg[i - k] += b[k];
    							b[k] = 0;
    						} else if (g[i] < b[k]) {
    							tg[i - k] += g[i];
    							b[k] -= g[i];
    							g[i] = 0;
    						}
    					} else if (i < k) {
    						if (g[i] == b[k]) {
    							tb[k - i] += b[k];
    							g[i] = b[k] = 0;
    						} else if (g[i] > b[k]) {
    							g[i] -= b[k];
    							tb[k - i] += b[k];
    							b[k] = 0;
    						} else if (g[i] < b[k]) {
    							tb[k - i] += g[i];
    							b[k] -= g[i];
    							g[i] = 0;
    						}
    					}
    				} else break;
    			}
    			g[i] += tempG;
    			b[k] += tempB;
    			if (g[i] == 0) --i;
    		}
    		for (int i = 0; i < MAXN; ++i) {
    			tg[i] += g[i];
    			tb[i] += b[i];
    		}
    		SG = SB = 0;
    		for (int i = 0; i < MAXN; ++i) {
    			SG += tg[i];
    			SB += tb[i];
    			g[i] = tg[i];
    			b[i] = tb[i];
    		}
    		// cout << SG << " " << SB << endl;
    	}
    	// cout << "res " << SG << " " << SB << endl;
    	if (SG == SB) printf("green and blue died\n");
    	else if (SG > SB) {
    		printf("green wins\n");
    		for (int i = MAXN - 1; i >= 0; --i) {
    			for (int k = 0; k < g[i]; ++k) {
    				printf("%d\n", i);
    			}
    		}
    	} else {
    		printf("blue wins\n");
    		for (int i = MAXN - 1; i >= 0; --i) {
    			for (int k = 0; k < b[i]; ++k) {
    				printf("%d\n", i);
    			}
    		}
    	}
    	if (N) printf("\n");
    }
    return 0;
}