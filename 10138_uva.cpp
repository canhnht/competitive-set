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

struct Data {
	string name, type;
	int time[4], pos;

	Data(string _name, string _type) {
		name = _name;
		type = _type;
	}
};

bool cmp(Data d1, Data d2) {
	for (int i = 0; i < 4; ++i) {
		if (d1.time[i] < d2.time[i]) return true;
		if (d1.time[i] > d2.time[i]) return false;
	}
	return false;
}

int T;
int rate[30];
vector<Data> a;
map<string, pii> mapper;
char line[MAXN], name[30], type[10];
int month, day, hour, minute, pos;
map<string, double> res;

// TODO: Why this solution is WRONG @@

int main(){
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
    	for (int i = 0; i < 24; ++i) scanf("%d", rate + i);
    	cin.getline(line, MAXN);
    	while (cin.getline(line, MAXN) && strlen(line) != 0) {
    		sscanf(line, "%s %d:%d:%d:%d %s %d", name, &month, &day, &hour, &minute, type, &pos);
    		// cout << name << " " << hour << " " << type << " " << pos << endl;
    		Data temp = Data(string(name), string(type));
    		temp.time[0] = month;
    		temp.time[1] = day;
    		temp.time[2] = hour;
    		temp.time[3] = minute;
    		temp.pos = pos;
    		a.push_back(temp);
    	}
    	// cout << a.size() << endl;
    	sort(a.begin(), a.end(), cmp);
    	mapper.clear();
    	res.clear();
    	for (int i = 0; i < a.size(); ++i) {
    		// cout << a[i].type << endl;
    		if (a[i].type[1] == 'n') {	// enter
    			// cout << a[i].name << " " << a[i].time[2] << " " << a[i].pos << endl;
    			mapper[a[i].name] = make_pair(a[i].time[2], a[i].pos);
    		} else {	// exit
    			if (mapper.count(a[i].name)) {
    				// cout << a[i].name << " " << mapper[a[i].name].first << " " << mapper[a[i].name].second << endl;
    				if (!res.count(a[i].name)) res[a[i].name] = 0;
    				res[a[i].name] += rate[mapper[a[i].name].first] * abs(mapper[a[i].name].second - a[i].pos) / 100.0 + 1;
    				mapper.erase(a[i].name);
    			}
    		}
    	}
    	for (map<string, double>::iterator it = res.begin(); it != res.end(); ++it) {
    		printf("%s $%.2lf\n", it->first.c_str(), it->second + 2);
    	}
    	
    	if (T) printf("\n");
    }
    return 0;
}