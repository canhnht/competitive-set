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

int n;
pii query[MAXN];

bool isStack();
bool isQueue();
bool isPriorityQueue();

int main(){
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (scanf("%d", &n) == 1) {
    	for (int i = 0; i < n; ++i) scanf("%d%d", &query[i].first, &query[i].second);
    	int res = 0;
    	if (isStack()) res += 1;
    	if (isQueue()) res += 2;
    	if (isPriorityQueue()) res += 4;
    	if (res == 0) printf("impossible\n");
    	else if (res == 1) printf("stack\n");
    	else if (res == 2) printf("queue\n");
    	else if (res == 4) printf("priority queue\n");
    	else printf("not sure\n");
    }
    return 0;
}

bool isStack() {
	stack<int> sta;
	while (!sta.empty()) sta.pop();
	for (int i = 0; i < n; ++i) {
		if (query[i].first == 1) {
			sta.push(query[i].second);
		} else {
			int x;
			if (!sta.empty()) {
				x = sta.top();
				sta.pop();
				if (x != query[i].second) return false;
			} else return false;			
		}
	}
	return true;
}

bool isQueue() {
	queue<int> qu;
	while (!qu.empty()) qu.pop();
	for (int i = 0; i < n; ++i) {
		if (query[i].first == 1) {
			qu.push(query[i].second);
		} else {
			int x;
			if (!qu.empty()) {
				x = qu.front();
				qu.pop();
				if (x != query[i].second) return false;
			} else return false;			
		}
	}
	return true;	
}

bool isPriorityQueue() {
	priority_queue<int, vector<int> > pq1;	
	while (!pq1.empty()) pq1.pop();
	for (int i = 0; i < n; ++i) {
		if (query[i].first == 1) {
			pq1.push(query[i].second);			
		} else {
			int x;
			if (!pq1.empty()) {
				x = pq1.top();
				pq1.pop();
				if (x != query[i].second) return false;
			} else return false;
		}			
	}
	return true;	
}