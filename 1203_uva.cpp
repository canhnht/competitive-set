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

struct Data {
	int id;
	int period;
	int t;

	Data(int _id, int _period) {
		id = _id;
		period = _period;
		t = period;
	}

	bool operator<(const Data &d) const {
		if (t != d.t) return t > d.t;
		return id > d.id;
	}
};

priority_queue<Data, vector<Data> > pq;
int K;

int main(){
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    char st[10];
    while (scanf("%s", st), strcmp(st, "#") != 0) {
    	int id, period;
    	scanf("%d%d", &id, &period);
    	pq.push(Data(id, period));
    }
    scanf("%d", &K);
    for (int i = 0; i < K; ++i) {
    	Data cur = pq.top();
    	pq.pop();
    	printf("%d\n", cur.id);
    	cur.t += cur.period;
    	pq.push(cur);
    }
    return 0;
}