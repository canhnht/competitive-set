//This is getting accepted!
#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define toggleBit(S, j) (S ^= (1 << j))

typedef pair<int, int> pii;
typedef pair<int, pii> ppi;

const double PI = acos(0) * 2;
const ll MOD = 1000000007;
const int MAXN = 17;
const int oo = 1e9;

int N;
int a[1 << MAXN];
int pot[1 << MAXN];

int main(){
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (scanf("%d", &N) == 1) {
    	for (int i = 0; i < (1 << N); ++i) {
    		scanf("%d", a + i);
    	}    	
    	for (int i = 0; i < (1 << N); ++i) {    		
    		pot[i] = 0;
    		for (int k = 0; k < N; ++k) {
    			int temp = i;
    			pot[i] += a[toggleBit(temp, k)];
    		}    		
    	}

    	// for (int i = 0; i < (1 << N); ++i) cout << pot[i] << endl;

    	int res = 0;
    	for (int i = 0; i < (1 << N); ++i) {    		    		
    		for (int k = 0; k < N; ++k) {
    			int temp = i;
    			res = max(res, pot[i] + pot[toggleBit(temp, k)]);
    		}    		
    	}
    	printf("%d\n", res);
    }
    return 0;
}