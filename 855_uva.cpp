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
const int MAXN = 5e4 + 5;
const int oo = 1e9;

int T, S, A, F;
int ax[MAXN], ay[MAXN];
int resX, resY;

int main(){
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
    	scanf("%d%d%d", &S, &A, &F);
    	int x, y;
    	for (int i = 0; i < F; ++i) {
    		scanf("%d%d", &x, &y);
    		ax[i] = x;
    		ay[i] = y;
    	}
    	sort(ax, ax + F);
    	sort(ay, ay + F);    	
    	--F;
		resX = ax[F / 2];
		resY = ay[F / 2];
    	printf("(Street: %d, Avenue: %d)\n", resX, resY);
    }
    return 0;
}