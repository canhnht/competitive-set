#include <bits/stdc++.h>

using namespace std;

class DungeonEscape {
public:
	int exitTime(vector<string> up, vector<string> down, vector<string> east, vector<string> west, int startLevel, int startEast);
};

typedef pair<int, int> pii;
typedef pair<int, pii> pip;

const int MAXN = 55;
const int oo = 1e9;

int N, M;
priority_queue<pip, vector<pip>, greater<pip> > pq;
int dist[MAXN][MAXN];

int DungeonEscape::exitTime(vector<string> up, vector<string> down, vector<string> east, vector<string> west, int startLevel, int startEast) {
	N = up.size();
	M = up[0].size();
	while (!pq.empty()) pq.pop();
	pq.push(make_pair(0, make_pair(startLevel, startEast)));
	for (int i = 0; i < N; ++i) {
		for (int k = 0; k < M; ++k) {
			dist[i][k] = +oo;
		}
	}
	dist[startLevel][startEast] = 0;
	cout << N << " " << M << endl;
	while (!pq.empty()) {
		pip cur = pq.top();
		pq.pop();
		if (cur.first > dist[cur.second.first][cur.second.second]) continue;
		int cx, cy;
		cx = cur.second.first;
		cy = cur.second.second;
		if (cx - 1 >= 0 && up[cx][cy] != 'x') {
			if (cur.first + up[cx][cy] - '0' < (N - cx + 1) * M && dist[cx - 1][cy] > cur.first + up[cx][cy] - '0') {
				dist[cx - 1][cy] = cur.first + up[cx][cy] - '0';
				pq.push(make_pair(dist[cx - 1][cy], make_pair(cx - 1, cy)));
			}
		}
		if (cx + 1 < N && down[cx][cy] != 'x') {
			if (cur.first + down[cx][cy] - '0' < (N - cx - 1) * M && dist[cx + 1][cy] > cur.first + down[cx][cy] - '0') {
				dist[cx + 1][cy] = cur.first + down[cx][cy] - '0';
				pq.push(make_pair(dist[cx + 1][cy], make_pair(cx + 1, cy)));
			}
		}
		if (cy - 1 >= 0 && west[cx][cy] != 'x') {
			if (cur.first + west[cx][cy] - '0' < (N - cx) * M && dist[cx][cy - 1] > cur.first + west[cx][cy] - '0') {
				dist[cx][cy - 1] = cur.first + west[cx][cy] - '0';
				pq.push(make_pair(dist[cx][cy - 1], make_pair(cx, cy - 1)));
			}
		}
		if (cy + 1 < M && east[cx][cy] != 'x') {
			if (cur.first + east[cx][cy] - '0' < (N - cx) * M && dist[cx][cy + 1] > cur.first + east[cx][cy] - '0') {
				dist[cx][cy + 1] = cur.first + east[cx][cy] - '0';
				pq.push(make_pair(dist[cx][cy + 1], make_pair(cx, cy + 1)));
			}
		}
	}
	int res = +oo;
	for (int i = 0; i < M; ++i) {
		if (up[0][i] != 'x') res = min(res, dist[0][i] + up[0][i] - '0');
	}
	return (res == +oo ? -1 : res);
}