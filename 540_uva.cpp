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
const int oo = 1e9;
const int MAXN = 1e6 + 5;
const int MAXT = 1e3 + 5;

int nTeam;
int team[MAXN];
queue<int> qu[MAXT];
queue<int> quTeam;

int main(){
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int nTest = 0;
    while (scanf("%d", &nTeam), nTeam) {
    	printf("Scenario #%d\n", ++nTest);
    	for (int i = 0; i < nTeam; ++i) {
    		while (!qu[i].empty()) qu[i].pop();
    		int c;
    		scanf("%d", &c);
    		int x;
    		while (c--) {
    			scanf("%d", &x);
    			team[x] = i;
    		}
    	}
    	char cmd[10];
    	int x;
    	while (!quTeam.empty()) quTeam.pop();    	
    	while (scanf("%s", cmd), cmd[0] != 'S') {
    		if (cmd[0] == 'E') {
    			scanf("%d", &x);
    			if (qu[team[x]].empty()) quTeam.push(team[x]);
    			qu[team[x]].push(x);
    		} else {    			
    			printf("%d\n", qu[quTeam.front()].front());
    			qu[quTeam.front()].pop();
    			if (qu[quTeam.front()].empty()) quTeam.pop();
    		}
    	}
    	printf("\n");
    }
    return 0;
}