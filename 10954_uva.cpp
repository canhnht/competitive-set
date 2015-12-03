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

int N;
priority_queue<int, vector<int>, greater<int> > pq;

int main(){
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (scanf("%d", &N), N) {
    	while (!pq.empty()) pq.pop();
    	int x;
    	for (int i = 0; i < N; ++i) {
    		scanf("%d", &x);
    		pq.push(x);
    	}
    	int res = 0;
    	for (int i = 0; i < N - 1; ++i) {
    		int p1 = pq.top(); pq.pop();
    		int p2 = pq.top(); pq.pop();
    		res += p1 + p2;
    		pq.push(p1 + p2);
    	}
    	printf("%d\n", res);
    }
    return 0;
}