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

int P, C;
queue<int> qu, temp;

int main(){
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int nTest = 0;
    while (scanf("%d%d", &P, &C), P || C) {
    	printf("Case %d:\n", ++nTest);
    	while (!qu.empty()) qu.pop();
    	for (int i = 1; i <= min(C, P); ++i) {
    		qu.push(i);
    	}
    	char cmd[3];
    	int x;    	
    	while (C--) {
    		scanf("%s", cmd);
    		if (cmd[0] == 'N') {
    			printf("%d\n", qu.front());
    			qu.push(qu.front());
    			qu.pop();
    		} else {
    			scanf("%d", &x);
    			while (!qu.empty()) {
    				temp.push(qu.front());
    				qu.pop();
    			}
				qu.push(x);
				while (!temp.empty()) {
					if (temp.front() != x) qu.push(temp.front());
					temp.pop();
				}    			
    		}
    	}
    }
}