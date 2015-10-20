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
vector<int> sta[MAXN];
int pos[MAXN];

int releaseBlocks(int);

int main(){
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d%*c", &N);
    for (int i = 0; i < N; ++i) {
    	sta[i].resize(1, i);
    	pos[i] = i;
    }
    char line[MAXN], s1[10], s2[10];
    int a, b;
    while (cin.getline(line, MAXN), strcmp(line, "quit") != 0) {
    	sscanf(line, "%s%d%s%d", s1, &a, s2, &b);
    	// cout << s1 << " " << a << " " << s2 << " " << b << endl;
    	if (pos[a] == pos[b]) continue;
    	if (s1[0] == 'm') {
    		if (s2[3] == 'o') {
    			int v = releaseBlocks(a);
    			sta[pos[a]].resize(v);
    			v = releaseBlocks(b);
    			sta[pos[b]].resize(v + 1);
    			sta[pos[b]].push_back(a);
    			pos[a] = pos[b];
    		} else {
    			int v = releaseBlocks(a);
    			sta[pos[a]].resize(v);
    			sta[pos[b]].push_back(a);
    			pos[a] = pos[b];
    		}
    	} else {
    		if (s2[3] == 'o') {
    			int v = releaseBlocks(b);
    			sta[pos[b]].resize(v + 1);
    			v = pos[a];
    			int i;
    			for (i = 0; sta[v][i] != a; ++i);
    			int sz = i;
    			for (; i < sta[v].size(); ++i) {
    				sta[pos[b]].push_back(sta[v][i]);    				
    				pos[sta[v][i]] = pos[b];    				
    			}    			
    			sta[v].resize(sz);
    		} else {    			
    			int v = pos[a];
    			int i;
    			for (i = 0; sta[v][i] != a; ++i);
    			int sz = i;
    			for (; i < sta[v].size(); ++i) {
    				sta[pos[b]].push_back(sta[v][i]);    				
    				pos[sta[v][i]] = pos[b];    				
    			}    			
    			sta[v].resize(sz);
    		}    		
    	}    	

    	// for (int i = 0; i < N; ++i) {
	    // 	printf("%d:", i);
	    // 	for (int k = 0; k < sta[i].size(); ++k) {
	    // 		printf(" %d", sta[i][k]);
	    // 	}
	    // 	printf("\n");
	    // }
	    // printf("==================\n");
    }
    for (int i = 0; i < N; ++i) {
    	printf("%d:", i);
    	for (int k = 0; k < sta[i].size(); ++k) {
    		printf(" %d", sta[i][k]);
    	}
    	printf("\n");
    }
    return 0;
}

int releaseBlocks(int a) {
	int p = pos[a];
	int i;
	for (i = sta[p].size() - 1; sta[p][i] != a; --i) {
		pos[sta[p][i]] = sta[p][i];
		sta[sta[p][i]].resize(1, sta[p][i]);
	}
	return i;
}