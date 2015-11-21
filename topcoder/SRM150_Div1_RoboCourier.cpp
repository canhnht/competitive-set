#include <bits/stdc++.h>

using namespace std;

class RoboCourier {
public:
	int timeToDeliver(vector<string> path);
};

typedef pair<int, int> pii;

const int MAXN = 1e3 + 5;
const int dx[] = {-1, 0, 1, 1, 0, -1};
const int dy[] = {1, 1, 0, -1, -1, 0};
const int oo = 1e9;

struct Data {
	int u, dist;
	int dir;
	bool p2;
	
	Data(int _u, int _dist, int _dir, bool _p2) {
		u = _u;
		dist = _dist;
		dir = _dir;
		p2 = _p2;
	}
};

class classcomp {
public:
	bool operator()(const Data& lhs, const Data& rhs) const {
		return lhs.dist > rhs.dist;
	}
};

map<pii, int> idx;
int cnt;
vector<pii> adj[MAXN];
int dist[MAXN][10][2];
priority_queue<Data, vector<Data>, classcomp> pq;
int dest;

void buildGraph(vector<string>);
int dijkstra();

int RoboCourier::timeToDeliver(vector<string> path) {
	buildGraph(path);
	return dijkstra();
}

int dijkstra() {
	for (int i = 0; i < MAXN; ++i) {
		for (int d = 0; d < 6; ++d) {
			dist[i][d][0] =  dist[i][d][1] = +oo;
		}
	}
	while (!pq.empty()) pq.pop();
	pq.push(Data(0, 0, 6, 0));
	dist[0][6][0] = 0;
	while (!pq.empty()) {
		Data cur = pq.top();
		pq.pop();
		if (cur.dist > dist[cur.u][cur.dir][cur.p2]) continue;
		if (cur.u == dest) return cur.dist + (cur.p2 ? 2 : 0);
//		cout << "currr " << cur.x << " " << cur.y << endl;
		for (int i = 0; i < adj[cur.u].size(); ++i) {
				int v = adj[cur.u][i].first;
				int d = adj[cur.u][i].second;
				int w;
				if (d == cur.dir) w = 2;
				else {
					int rot = (d - cur.dir + 6) % 6;
					rot = min(rot, 6 - rot);
					w = rot * 3 + 4;					
					if (cur.p2) w += 2;
				}
//				cout << "www " << w << endl;
				if (cur.dist + w < dist[v][d][w == 2]) {
					dist[v][d][w == 2] = cur.dist + w;
					pq.push(Data(v, cur.dist + w, d, w == 2));
				}
			}
	}
	return -1;
}

void buildGraph(vector<string> path) {
	int dir = 0;
	pii p = make_pair(MAXN / 2, MAXN / 2);
	cnt = 0;
	idx.clear();
	idx[p] = cnt++;
	for (int i = 0; i < MAXN; ++i) adj[i].clear();
	for (int i = 0; i < path.size(); ++i) {
		for (int k = 0; k < path[i].length(); ++k) {
			if (path[i][k] == 'F') {
				int u = idx[p];
				p.first += dx[dir];
				p.second += dy[dir];
				if (!idx.count(p)) idx[p] = cnt++;
				int v = idx[p];
				adj[u].push_back(make_pair(v, dir));
				adj[v].push_back(make_pair(u, (dir + 3) % 6));
			} else if (path[i][k] == 'L') {
				dir = (dir - 1 + 6) % 6;
			} else if (path[i][k] == 'R') {
				dir = (dir + 1) % 6;
			}
		}
	}
	dest = idx[p];
}