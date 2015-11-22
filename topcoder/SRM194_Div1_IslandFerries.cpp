#include <bits/stdc++.h>

using namespace std;

class IslandFerries {
public:
	vector<int> costs(vector<string> legs, vector<string> prices);
};

typedef pair<int, int> pii;
typedef pair<int, pii> pip;

const int MAXF = 11;
const int MAXI = 55;
const int oo = 1e9;

int F, I;
int dist[MAXI][1 << MAXF];
vector<pii> adj[MAXI];
int cost[MAXI][MAXF];
priority_queue<pip, vector<pip>, greater<pip> > pq;

vector<int> IslandFerries::costs(vector<string> legs, vector<string> prices) {
	F = legs.size();
	I = prices.size();
	for (int i = 0; i < I; ++i) adj[i].clear();
	for (int i = 0; i < F; ++i) {
		stringstream ss(legs[i]);
		int u, v;
		char c;
		while (ss >> u >> c >> v) {
			adj[u].push_back(make_pair(v, i));
		}
	}
	for (int i = 0; i < I; ++i) {
		stringstream ss(prices[i]);
		for (int k = 0; k < F; ++k) {
			ss >> cost[i][k];
		}
	}
	for (int i = 0; i < I; ++i) {
		for (int k = 0; k < (1 << F); ++k) {
			dist[i][k] = +oo;
		}
	}
	while (!pq.empty()) pq.pop();
	for (int i = 0; i < (1 << F); ++i) {
		int cnt = 0, sum = 0;
		for (int k = 0; k < F; ++k) {
			if ((i >> k) & 1) {
				++cnt;
				sum += cost[0][k];
			}
		}
		if (cnt <= 3) {
			dist[0][i] = sum;
			pq.push(make_pair(sum, make_pair(0, i)));
		}
	}
	cout << pq.size() << endl;
	while (!pq.empty()) {
		pip cur = pq.top();
		pq.pop();
		int cx, cy;
		cx = cur.second.first;
		cy = cur.second.second;
		if (cur.first > dist[cx][cy]) continue;
//		cout << cur.first << " " << cx << " " << cy << endl;
		int cnt = 0;
		for (int i = 0; i < F; ++i) {
			cnt += ((cy >> i) & 1);
		}
		if (cnt < 3) {
			for (int i = 0; i < F; ++i) {
				if (((cy >> i) & 1) == 0) {
					int temp = cy | (1 << i);
					if (cur.first + cost[cx][i] < dist[cx][temp]) {
						dist[cx][temp] = cur.first + cost[cx][i];
						pq.push(make_pair(dist[cx][temp], make_pair(cx, temp)));
					}
				}
			}
		}
		for (int i = 0; i < adj[cx].size(); ++i) {
			int u = adj[cx][i].first;
			int f = adj[cx][i].second;
			if ((cy >> f) & 1) {
				int temp = cy ^ (1 << f);
				if (cur.first < dist[u][temp]) {
					dist[u][temp] = cur.first;
					pq.push(make_pair(dist[u][temp], make_pair(u, temp)));
				}
			}
		}
	}
	vector<int> res(I - 1, +oo);
	for (int i = 1; i < I; ++i) {
		for (int k = 0; k < (1 << F); ++k) {
			res[i - 1] = min(res[i - 1], dist[i][k]);
		}
		if (res[i - 1] == +oo) res[i - 1] = -1;
	}
	return res;
}