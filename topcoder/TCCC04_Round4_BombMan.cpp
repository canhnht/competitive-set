#include <bits/stdc++.h>

using namespace std;

class BombMan {
public:
	int shortestPath(vector<string> maze, int bombs);
};

typedef pair<int, int> pii;

const int MAXN = 55;
const int oo = 1e9;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

struct Data {
	int x, y, bomb;
	int dist;
	
	Data(int _x, int _y, int _bomb, int _dist) {
		x = _x;
		y = _y;
		bomb = _bomb;
		dist = _dist;
	}
};

class classcomp {
public:
	bool operator()(const Data& lhs, const Data &rhs) {
		return lhs.dist > rhs.dist;
	}
};

string grid[MAXN];
int N, M, nBomb;
int dist[MAXN][MAXN][105];
priority_queue<Data, vector<Data>, classcomp> pq;
pii from, to;

int dijkstra();
bool ok(int, int);

int BombMan::shortestPath(vector<string> maze, int bombs) {
	N = maze.size();
	M = maze[0].length();
	nBomb = bombs;
	for (int i = 0; i < N; ++i) grid[i] = maze[i];
	for (int i = 0; i < N; ++i) {
		for (int k = 0; k < M; ++k) {
			if (grid[i][k] == 'B') {
				from = make_pair(i, k);
			} else if (grid[i][k] == 'E') {
				to = make_pair(i, k);
			}
		}
	}
	return dijkstra();
}

int dijkstra() {
	for (int i = 0; i < N; ++i) {
		for (int k = 0; k < M; ++k) {
			for (int p = 0; p <= nBomb; ++p) {	
				dist[i][k][p] = +oo;
			}
		}	
	}
	dist[from.first][from.second][nBomb] = 0;
	pq.push(Data(from.first, from.second, nBomb, 0));
	while (!pq.empty()) {
		Data cur = pq.top();
		pq.pop();
		if (cur.dist > dist[cur.x][cur.y][cur.bomb]) continue; 
		if (cur.x == to.first && cur.y == to.second) return cur.dist;
//		cout << cur.x << " " << cur.y << " " << cur.bomb << " " << cur.dist << endl;
		for (int d = 0; d < 4; ++d) {
			if (ok(cur.x + dx[d], cur.y + dy[d])) {
				if (grid[cur.x + dx[d]][cur.y + dy[d]] == '#') {
					if (cur.bomb > 0 && dist[cur.x + dx[d]][cur.y + dy[d]][cur.bomb - 1] > cur.dist + 3) {
						dist[cur.x + dx[d]][cur.y + dy[d]][cur.bomb - 1] = cur.dist + 3;
						pq.push(Data(cur.x + dx[d], cur.y + dy[d], cur.bomb - 1, cur.dist + 3));
					}
				} else {
					if (dist[cur.x + dx[d]][cur.y + dy[d]][cur.bomb] > cur.dist + 1) {
						dist[cur.x + dx[d]][cur.y + dy[d]][cur.bomb] = cur.dist + 1;
						pq.push(Data(cur.x + dx[d], cur.y + dy[d], cur.bomb, cur.dist + 1));
					}
				}
			}
		}
	}
	return -1;
}

bool ok(int x, int y) {
	return (x >= 0 && x < N && y >= 0 && y < M);
}