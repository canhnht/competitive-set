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

char line[MAXN];

bool successor(char []);

int main(){
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (scanf("%s", line), strcmp(line, "#") != 0) {
    	// int len = strlen(line);
    	// if (next_permutation(line, line + len)) {
    	// 	printf("%s\n", line);
    	// } else {
    	// 	printf("No Successor\n");
    	// }    	
    	if (successor(line)) {
    		printf("%s\n", line);
    	} else {
    		printf("No Successor\n");
    	}
    }
    return 0;
}

bool successor(char st[]) {
	int len = strlen(st);
	int i;
	for (i = len - 1; i > 0; --i) {
		if (st[i] > st[i - 1]) break;
	}
	if (i == 0) return false;
	int lo = i;
	int hi = len - 1;
	while (lo < hi) {
		int mid = (lo + hi + 1) >> 1;
		if (st[mid] <= st[i - 1]) hi = mid - 1;
		else lo = mid;
	}
	swap(st[i - 1], st[lo]);
	for (int k = i; k < (len - 1 + i) / 2; ++k) swap(st[k], st[len - 1 - (k - i)]);
}