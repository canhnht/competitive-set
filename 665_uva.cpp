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

int M;
int N, K;
vector<int> weight[MAXN][2];
char result[MAXN][2];

int findFalseCoin(bool);

int main(){
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &M);
    while (M--) {
    	scanf("%d%d", &N, &K);
    	int P;
    	for (int i = 0; i < K; ++i) {
    		scanf("%d", &P);
    		for (int k = 0; k < 2; ++k) {
    			weight[i][k].resize(P);
    			for (int p = 0; p < P; ++p) {
    				scanf("%d", &weight[i][k][p]);
    			}
    		}
    		scanf("%s", result[i]);
    	}
    	int res1 = findFalseCoin(true);
    	int res2 = findFalseCoin(false);
    	// cout << res1 << " " << res2 << endl;
    	if (res1 && res2 && res1 != res2 || !res1 && !res2) {
    		printf("0\n");
    	} else {
    		printf("%d\n", (res1 ? res1 : res2));
    	}
		if (M > 0) printf("\n");    	
    }
    return 0;
}

int findFalseCoin(bool smaller) {
	int mark[MAXN];
	/*		
		0: false
		1: true
	*/
	memset(mark, 0, sizeof mark);
	for (int i = 0; i < K; ++i) {
		if (result[i][0] == '=') {
			for (int k = 0; k < 2; ++k) {
				for (int p = 0; p < weight[i][k].size(); ++p) {
					mark[weight[i][k][p]] = 1;
				}
			}
		} else if (result[i][0] == '<') {
			int cnt1, cnt2;
			cnt1 = cnt2 = 0;
			for (int p = 0; p < weight[i][0].size(); ++p) {
				if (mark[weight[i][0][p]] == 1) {
					continue;
				}
				++cnt1;
				mark[weight[i][0][p]] = !smaller;
			}
			for (int p = 0; p < weight[i][1].size(); ++p) {				
				if (mark[weight[i][1][p]] == 1) {
					continue;
				}
				++cnt2;
				mark[weight[i][1][p]] = smaller;
			}
			if (smaller && cnt1 == 0) return 0;
			else if (!smaller && cnt2 == 0) return 0;
		} else if (result[i][0] == '>') {
			int cnt1, cnt2;
			cnt1 = cnt2 = 0;
			for (int p = 0; p < weight[i][1].size(); ++p) {
				if (mark[weight[i][1][p]] == 1) {
					continue;
				}
				++cnt1;
				mark[weight[i][1][p]] = !smaller;
			}
			for (int p = 0; p < weight[i][0].size(); ++p) {				
				if (mark[weight[i][0][p]] == 1) {
					continue;
				}
				++cnt2;
				mark[weight[i][0][p]] = smaller;
			}
			if (smaller && cnt1 == 0) return 0;
			else if (!smaller && cnt2 == 0) return 0;
		} 
	}
	int ret = 0;
	for (int i = 1; i <= N; ++i) {
		// printf("mark %d\n", mark[i]);
		if (mark[i] == 0) {
			if (ret > 0) return 0;
			ret = i;
		}
	}
	return ret;
}