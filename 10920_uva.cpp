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

int SZ;
ll P;

int main(){
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (scanf("%d%lld", &SZ, &P), SZ || P) {
    	int v = int(sqrt(P - 1));
    	if (v % 2 == 0) --v;
    	// cout << "v = " << v << endl;
    	int x = (SZ - v - 2) / 2 + 1;
    	int y = x;
    	// cout << x << " " << y << endl;    	    	
    	if (v < 0) {
    		printf("Line = %d, column = %d.\n", (SZ + 1) / 2, (SZ + 1) / 2);
    		continue;
    	}
    	ll temp = (ll)v * v + 1;
    	v += 2;
    	// cout << v << endl;
    	if (P >= temp && P <= temp + v - 2) {
    		x += v - 1;
    		y += temp + v - 2 - P;
    	}
    	temp += v - 1;
    	if (P >= temp && P <= temp + v - 2) {
    		x += temp + v - 2 - P;    		
    	}
    	temp += v - 1;
    	if (P >= temp && P <= temp + v - 2) {
    		y += P - temp + 1;
    	}
    	temp += v - 1;
    	if (P >= temp && P <= temp + v - 2) {
    		x += P - temp + 1;
    		y += v - 1;
    	}
    	printf("Line = %d, column = %d.\n", x, y);
    }
    return 0;
}
