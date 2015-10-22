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

int N;
int cnt[MAXN];

int main(){
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (scanf("%d", &N) == 1) {
    	int x;
    	memset(cnt, 0, sizeof cnt);
    	for (int i = 0; i < N; ++i) {
    		scanf("%d", &x);
    		++cnt[x];
    	}
    	if (N & 1) {
    		int temp = (N + 1) / 2;
    		int i;
    		for (i = 0; temp > cnt[i]; ++i) {
    			temp -= cnt[i];
    		}
    		printf("%d %d %d\n", i, cnt[i], 1);
    	} else {
    		int temp = N / 2;
    		int i1, i2;
    		for (i1 = 0; temp > cnt[i1]; ++i1) {
    			temp -= cnt[i1];
    		}
    		temp = N / 2 + 1;
    		for (i2 = 0; temp > cnt[i2]; ++i2) {
    			temp -= cnt[i2];
    		}
    		if (i1 == i2) {
    			printf("%d %d %d\n", i1, cnt[i1], 1);
    		} else {
    			printf("%d %d %d\n", i1, cnt[i1] + cnt[i2], i2 - i1 + 1);
    		}
    	}
    }
    return 0;
}