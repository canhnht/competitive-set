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
const int MAXN = 1e5 + 5;
const int oo = 1e9;

int c, n;
pii it[MAXN << 3];
int lazy[MAXN << 3];
int res;

int get(int, int, int, int, int, int);
void update(int, int, int, int, int, int);
void push(int);
void pull(int);

int main(){
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &c);
    while (c--) {
    	scanf("%d", &n);
    	memset(it, 0, sizeof it);
    	memset(lazy, -1, sizeof lazy);
    	int l, r, h;
    	res = 0;
    	while (n--) {
    		scanf("%d%d%d", &l, &r, &h);
    		int temp = get(1, 0, 99999, l, r - 1, h);
    		// cout << "temp " << temp << endl;
    		res += temp;
    		update(1, 0, 99999, l, r - 1, h);
    	}
    	printf("%d\n", res);
    }
    return 0;
}

void push(int node) {
	if (lazy[node] != -1) {
		if (lazy[node] > it[node].second) {
			it[node].first = it[node].second = lazy[node];
		} else if (lazy[node] > it[node].first) {
			it[node].first = lazy[node];
		}
		lazy[node << 1] = max(lazy[node << 1], lazy[node]);
		lazy[node << 1 | 1] = max(lazy[node << 1 | 1], lazy[node]);
		lazy[node] = -1;
	}
}

void pull(int node) {
	it[node].first = min(it[node << 1].first, it[node << 1 | 1].first);
	it[node].second = max(it[node << 1].second, it[node << 1 | 1].second);
}

int get(int node, int lo, int hi, int x, int y, int h) {
	// cout << "push " << lo << " " << hi << " = " << lazy[node] << endl;
	push(node);
	if (y < lo || hi < x) return 0;
	if (x <= lo && hi <= y) {
		// cout << "node " << lo << " " << hi << " = " << it[node].first << " - " << it[node].second << endl;
		if (h >= it[node].second) return hi - lo + 1;
		if (h < it[node].first) return 0;
	}
	int mid = (lo + hi) >> 1;
	int g1 = get(node << 1, lo, mid, x, y, h);
	int g2 = get(node << 1 | 1, mid + 1, hi, x, y, h);
	pull(node);
	// cout << "get " << lo << " " << hi << " = " << g1 << " - " << g2 << endl;
	return g1 + g2;
}

void update(int node, int lo, int hi, int x, int y, int h) {
	push(node);
	if (hi < x || y < lo) return;
	if (x <= lo && hi <= y) {
		lazy[node] = max(lazy[node], h);		
		push(node);
		return;
	}
	int mid = (lo + hi) >> 1;
	update(node << 1, lo, mid, x, y, h);
	update(node << 1 | 1, mid + 1, hi, x, y, h);
	pull(node);
	// cout << "update " << lo << " " << hi << " = " << it[node].first << " " << it[node].second << endl;
}
