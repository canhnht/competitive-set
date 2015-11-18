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

int T, N;
map<string, int> mapper;

int main(){
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d%*c", &T);
    char line[MAXN];
    cin.getline(line, MAXN);
    while (T--) {
    	mapper.clear();
    	N = 0;
    	while (cin.getline(line, MAXN) && strlen(line) != 0) {
    		++N;
    		mapper[string(line)] += 1;
    	}
    	for (map<string, int>::iterator it = mapper.begin(); it != mapper.end(); ++it) {
    		printf("%s %.4lf\n", it->first.c_str(), it->second * 100.0 / N);
    	}
    	if (T) printf("\n");
    }
    return 0;
}