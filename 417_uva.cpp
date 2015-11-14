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

map<string, int> mapper;

int main(){
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    mapper.clear();
    int cnt = 0;

	// length 1    	
	string temp(1, '.');    
    for (char c1 = 'a'; c1 <= 'z'; ++c1) {    	    	
    	temp[0] = c1;    	
    	mapper[temp] = ++cnt;
    }

    // length 2
    temp = string(2, '.');
    for (char c1 = 'a'; c1 <= 'z'; ++c1) {    	
    	for (char c2 = c1 + 1; c2 <= 'z'; ++c2) {
    		temp[0] = c1;
    		temp[1] = c2;
    		mapper[temp] = ++cnt;
    	}
    }

    // length 3
    temp = string(3, '.');
    for (char c1 = 'a'; c1 <= 'z'; ++c1) {    	
    	for (char c2 = c1 + 1; c2 <= 'z'; ++c2) {
    		for (char c3 = c2 + 1; c3 <= 'z'; ++c3) {
    			temp[0] = c1;
    			temp[1] = c2;
    			temp[2] = c3;
    			mapper[temp] = ++cnt;
    		}
    	}
    }

    // length 4
    temp = string(4, '.');
    for (char c1 = 'a'; c1 <= 'z'; ++c1) {    	
    	for (char c2 = c1 + 1; c2 <= 'z'; ++c2) {
    		for (char c3 = c2 + 1; c3 <= 'z'; ++c3) {
    			for (char c4 = c3 + 1; c4 <= 'z'; ++c4) {
    				temp[0] = c1;
    				temp[1] = c2;
    				temp[2] = c3;
    				temp[3] = c4;
    				mapper[temp] = ++cnt;
    			}
    		}
    	}
    }

    // length 5
    temp = string(5, '.');
    for (char c1 = 'a'; c1 <= 'z'; ++c1) {    	
    	for (char c2 = c1 + 1; c2 <= 'z'; ++c2) {
    		for (char c3 = c2 + 1; c3 <= 'z'; ++c3) {
    			for (char c4 = c3 + 1; c4 <= 'z'; ++c4) {
    				for (char c5 = c4 + 1; c5 <= 'z'; ++c5) {
    					temp[0] = c1;
	    				temp[1] = c2;
	    				temp[2] = c3;
	    				temp[3] = c4;
	    				temp[4] = c5;
	    				mapper[temp] = ++cnt;
    				}
    			}
    		}
    	}
    }
 	
    char st[10];
    while (scanf("%s", st) == 1) {
    	temp = string(st);
    	if (mapper.count(temp)) printf("%d\n", mapper[temp]);
    	else printf("0\n");
    }

    return 0;
}