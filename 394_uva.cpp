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

struct Array {
	char name[15];
	int base, size;
	int D;
	pii dim[15];
	int C[15];
};

int N, R;
Array a[MAXN];

int main(){
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &N, &R);
    for (int i = 0; i < N; ++i) {
    	scanf("%s%d%d%d", a[i].name, &a[i].base, &a[i].size, &a[i].D);
    	for (int k = 1; k <= a[i].D; ++k) {
    		scanf("%d%d", &a[i].dim[k].first, &a[i].dim[k].second);
    	}
    }
    for (int i = 0; i < N; ++i) {
    	a[i].C[a[i].D] = a[i].size;
    	a[i].C[0] = a[i].base - a[i].C[a[i].D] * a[i].dim[a[i].D].first;
    	for (int k = a[i].D - 1; k >= 1; --k) {
    		a[i].C[k] = a[i].C[k + 1] * (a[i].dim[k + 1].second - a[i].dim[k + 1].first + 1);
    		a[i].C[0] -= a[i].C[k] * a[i].dim[k].first;
    	}    	    	
    }
    char st[15];
    int d[15];
    for (int i = 0; i < R; ++i) {
    	scanf("%s", st);
    	int k;
    	for (k = 0; k < N; ++k) {
    		if (strcmp(a[k].name, st) == 0) {
    			break;
    		}
    	}
		for (int p = 1; p <= a[k].D; ++p) {
			scanf("%d", d + p);
		}
    	printf("%s[%d", st, d[1]);    	
    	for (int p = 2; p <= a[k].D; ++p) {
    		printf(", %d", d[p]);
    	}
    	printf("] = ");
    	int res = a[k].C[0];
    	for (int p = 1; p <= a[k].D; ++p) res += a[k].C[p] * d[p];
    	printf("%d\n", res);
    }
    return 0;
}