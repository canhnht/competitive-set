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

vector<pair<string, string> > books, desk;
set<string> out, borrow;
string line;

int main(){
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    books.clear();
    while (getline(cin, line), line.compare("END") != 0) {    	
    	string title, author;    	
    	int pos;
    	for (pos = 1; pos < line.length(); ++pos) {
    		if (line[pos] == '"') break;
    	}
    	title = line.substr(1, pos - 1);
    	// title = title.trim();
    	author = line.substr(pos + 5);
    	// author = author.trim();
    	books.push_back(make_pair(author, title));    	
    }
    sort(books.begin(), books.end());
    // for (int i = 0; i < books.size(); ++i) cout << books[i].first << " -- " << books[i].second << endl;
    // avail.clear();
    // for (int i = 0; i < books.size(); ++i) avail.insert(books.second);   
    out.clear();
    borrow.clear();
    while (getline(cin, line), line.compare("END") != 0) {
    	string cmd = line.substr(0, 6);    	
    	// cout << cmd << " -- " << title << endl;
    	if (cmd.compare("BORROW") == 0) {    		
    		string title = line.substr(8, line.length() - 9);    	
    		out.erase(title);
    		borrow.insert(title);
    		// avail.erase(title);
    	} else if (cmd.compare("RETURN") == 0) {
    		string title = line.substr(8, line.length() - 9);    	
    		out.insert(title);
    		borrow.erase(title);
    		// avail.insert(title);
    	} else {
    		desk.clear();
    		// cout << books.size() << endl;
    		for (int i = 0; i < books.size(); ++i) {
    			if (out.count(books[i].second)) {
    				// cout << books[i].second << endl;
    				desk.push_back(books[i]);
    			}
    		}    	
    		// cout << desk.size() << endl;
    		sort(desk.begin(), desk.end());    		
    		for (int i = 0; i < desk.size(); ++i) {
    			for (int k = 0; k < books.size(); ++k) {
    				if (books[k].second.compare(desk[i].second) == 0) {
    					int p;
    					for (p = k - 1; p >= 0; --p) {
    						if (!out.count(books[p].second) && !borrow.count(books[p].second)) break;
    					}
    					if (p >= 0) printf("Put \"%s\" after \"%s\"\n", desk[i].second.c_str(), books[p].second.c_str());
    					else printf("Put \"%s\" first\n", desk[i].second.c_str());
    					break;
    				}
    			}
    			out.erase(desk[i].second);
    		}
    		printf("END\n");
    	}
    }
    return 0;
}