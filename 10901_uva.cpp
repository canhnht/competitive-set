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
const int MAXN = 1e4 + 5;
const int oo = 1e9;

int nTest;
int N, T, M;
queue<pii> qu[2];
stack<pii> sta;
int res[MAXN];

int main(){
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &nTest);
    while (nTest--) {
    	scanf("%d%d%d", &N, &T, &M);
    	for (int i = 0; i < 2; ++i) {
    		while (!qu[i].empty()) qu[i].pop();
    	}
    	int t;
    	char side[10];
    	for (int i = 0; i < M; ++i) {
    		scanf("%d%s", &t, side);
    		if (side[0] == 'l') {
    			qu[0].push(make_pair(i, t));
    		} else {
    			qu[1].push(make_pair(i, t));
    		}
    	}
    	int cur = 0;
    	int tt = 0;
    	while (!qu[0].empty() || !qu[1].empty()) {
    		int other = cur ^ 1;
    		// cout << "side " << cur << endl;
    		// while (!sta.empty()) sta.pop();
    		for (int i = 0; !qu[cur].empty() && i < N; ++i) {
    			pii temp = qu[cur].front();
    			if (temp.second <= tt) {
    				sta.push(temp);
    				qu[cur].pop();
    			} else break;
    		}
    		// cout << "sta " << sta.size() << endl;
    		if (sta.empty()) {
    			if (qu[cur].empty() || !qu[other].empty() && qu[cur].front().second > qu[other].front().second) {
					cur = other;
					tt = max(qu[other].front().second, tt) + T;
    			} else {
    				tt = qu[cur].front().second;
    			}
    		} else {    			
    			tt += T;
    			while (!sta.empty()) {
    				res[sta.top().first] = tt;
    				sta.pop();
    			}    			
    			cur = other;
    		}
    	}
    	for (int i = 0; i < M; ++i) printf("%d\n", res[i]);
    	// printf("%d", res[M - 1]);
    	if (nTest) printf("\n");
    }
	return 0;
}