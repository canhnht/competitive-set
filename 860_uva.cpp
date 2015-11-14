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
const int MAXN = 1e6 + 5;
const int oo = 1e9;
const char ENDTEXT[] = "****END_OF_TEXT****";
const char ENDFILE[] = "****END_OF_INPUT****";
const string marks = ",.:;!?\"() \t\n";

char line[MAXN];
map<string, int> cnt;
int n;

bool validChar(char);

int main(){
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif    
    while (scanf("%s", line), strcmp(line, ENDFILE) != 0) {
    	n = 0;
    	cnt.clear();    		
    	while (strcmp(line, ENDTEXT) != 0) {    		
    		string word;    		
    		for (int i = 0; line[i]; ++i) {
    			if (validChar(line[i])) {
    				++n;
    				int k = i;
    				word = "";
    				word += tolower(line[i]);
    				while (line[k + 1] && validChar(line[k + 1])) {    					
    					word += tolower(line[++k]);
    				}    			
    				if (cnt.count(word)) cnt[word] += 1;
    				else cnt[word] = 1;
    				i = k;
    			}
    		}
    		scanf("%s", line);
    	}    	
    	double et, erel;
    	et = 0;
    	for (map<string, int>::iterator it = cnt.begin(); it != cnt.end(); ++it) {
    		// cout << it->first << " " << it->second << endl;
    		et += it->second * (log10(n) - log10(it->second));
    	}
    	et /= n;    	
    	erel = et / log10(n) * 100;
    	printf("%d %.1lf %.0lf\n", n, et, erel);
    }
    return 0;
}

bool validChar(char ch) {
	for (int i = 0; i < marks.length(); ++i) {
		if (marks[i] == ch) return false;
	}
	return true;
}