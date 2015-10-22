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

set<string> ignore;
char line[MAXN];
string title[MAXN];
int nTitle;
vector<pair<string, pii> > kwic;

int main(){
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ignore.clear();   
    while (scanf("%s", line), strcmp(line, "::") != 0) {
    	ignore.insert(string(line));
    }
    cin.ignore();
    kwic.clear();
    nTitle = 0;
    while (cin.getline(line, MAXN)) {
    	title[nTitle++] = string(line);
 		for (int i = 0; i < title[nTitle - 1].length(); ++i) {
 			title[nTitle - 1][i] = tolower(title[nTitle - 1][i]);
 		}   	
 		string st = title[nTitle - 1];
 		for (int i = 0; i < st.length(); ++i) {
 			int k = i;
 			while (k < st.length() && st[k] != ' ') ++k;
 			string word = st.substr(i, k - i); 			
 			if (!ignore.count(word)) {
 				for (int p = 0; p < word.length(); ++p) word[p] = toupper(word[p]);
 				kwic.push_back(make_pair(word, make_pair(nTitle - 1, i)));
 			}
 			i = k;
 		}
    }
    sort(kwic.begin(), kwic.end());
    for (int i = 0; i < kwic.size(); ++i) {
    	cout << title[kwic[i].second.first].substr(0, kwic[i].second.second)
    		 << kwic[i].first
    		 << title[kwic[i].second.first].substr(kwic[i].second.second + kwic[i].first.length()) << endl;
    }
    return 0;
}