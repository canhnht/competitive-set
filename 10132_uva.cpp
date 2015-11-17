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
const int MAXN = 1e3 + 5;
const int oo = 1e9;

int T;
map<string, int> mapper, cnt;
vector<string> a;
bool used[MAXN];

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
    	a.clear();
    	int len = 0;
    	while (cin.getline(line, MAXN) && strlen(line) != 0) {
    		string temp(line);
    		a.push_back(temp);
    		len += temp.length();
    		if (mapper.count(temp)) mapper[temp] += 1;
    		else mapper[temp] = 1;
    	}
    	len = len / (a.size() / 2);
    	// cout << "=========" << endl;
    	// for (int i = 0; i < a.size(); ++i) cout << a[i] << endl;
    	// cout << "=========" << endl;
    	// cout << "len " << len << endl;
    	bool res = false;
    	for (int i = 0; !res && i < a.size(); ++i) {
    		for (int k = 0; !res && k < a.size(); ++k) {
    			if (i == k) continue;
    			if (a[i].length() + a[k].length() != len) continue;
    			// for (map<string, int>::iterator it = mapper.begin(); it != mapper.end(); ++it) {
    			// 	cout << it->first << " " << it->second << endl;
    			// }
    			cnt = map<string, int>(mapper);
    			string file = a[i] + a[k];
    			cnt[a[i]] -= 1;
    			cnt[a[k]] -= 1;
    			for (int p = 0; p < a.size(); ++p) {
    				used[p] = false;
    			}
    			used[i] = used[k] = true;
    			for (int p = 0; p < a.size(); ++p) {
    				if (!used[p]) {
    					if (a[p].length() < file.length() && file.substr(0, a[p].length()).compare(a[p]) == 0) {
    						string temp = file.substr(a[p].length());
    						cnt[a[p]] -= 1;
    						if (cnt.count(temp) && cnt[temp] > 0) {
    							cnt[temp] -= 1;
    							used[p] = true;
    							for (int m = 0; m < a.size(); ++m) {
    								if (!used[m] && a[m].compare(temp) == 0) {
    									used[m] = true;
    									break;
    								}
    							}
    						} else {
    							cnt[a[p]] += 1;
    						}
    					}
    				}
    			}
    			bool ok = true;
    			for (int p = 0; p < a.size(); ++p) {
    				if (!used[p]) {
    					ok = false;
    					break;
    				}
    			}
    			if (ok) {
    				res = true;
    				printf("%s\n", file.c_str());    				
    			}
    		}
    	}
    	if (T) printf("\n");
    }
    return 0;
}