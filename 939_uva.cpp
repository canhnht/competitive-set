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

int N;
char name[MAXN], status[MAXN];
map<string, int> mapper;
string person[MAXN];
string a[MAXN];
vector<int> adj[MAXN];
vector<pair<string, string> > res;
bool vis[MAXN];

bool cmp(const vector<int> &v1, const vector<int> &v2) {
	return v1.size() < v2.size();
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) adj[i].clear();
    for (int i = 0; i < N; ++i) a[i] = "";
    int cnt = 0;
	mapper.clear();
    while (N--) {
    	scanf("%s%s", name, status);
    	string temp(name);
    	int id;
    	if (!mapper.count(temp)) {
    		person[cnt] = temp;
    		mapper[temp] = cnt++;    		
    	}
    	id = mapper[temp];
    	if (strcmp(status, "dominant") == 0 || strcmp(status, "recessive") == 0 || strcmp(status, "non-existent") == 0) 
    		a[id] = string(status);
    	else {
    		string temp1 = string(status);
    		int id1;
    		if (!mapper.count(temp1)) {
    			person[cnt] = temp1;
    			mapper[temp1] = cnt++;
    		}
    		id1 = mapper[temp1];
    		adj[id1].push_back(id);
    	}
    }
    // for (int i = 0; i < cnt; ++i) cout << person[i] << endl;
    res.clear();
    memset(vis, 0, sizeof vis);
    while (res.size() < cnt) {
    	for (int i = 0; i < cnt; ++i) {
    		if (vis[i]) continue;    		
			if (adj[i].size() == 0) {
				res.push_back(make_pair(person[i], a[i]));
				vis[i] = true;
			} else {
				if (!a[adj[i][0]].empty() && !a[adj[i][1]].empty()) {
					string s1 = a[adj[i][0]];
					string s2 = a[adj[i][1]];
                    bool haveGene = false;
                    if (s1.compare("non-existent") != 0 && s2.compare("non-existent") != 0) {
                        haveGene = true;
                    } else if (s1.compare("dominant") == 0 || s2.compare("dominant") == 0) {
                        haveGene = true;
                    }

					if (!haveGene) {
						a[i] = "non-existent";
					} else {
						if (s1.compare("dominant") == 0 && s2.compare("dominant") == 0 ||
                            s1.compare("dominant") == 0 && s2.compare("recessive") == 0 ||
                            s1.compare("recessive") == 0 && s2.compare("dominant") == 0) {
							a[i] = "dominant";
						} else {
							a[i] = "recessive";
						}
					}
					res.push_back(make_pair(person[i], a[i]));
					vis[i] = true;
				}
			}
	    }
    }        
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); ++i) printf("%s %s\n", res[i].first.c_str(), res[i].second.c_str());
    return 0;
}