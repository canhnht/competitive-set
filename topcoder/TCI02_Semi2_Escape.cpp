#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <queue>
#include <sstream>

using namespace std;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int grid[505][505];
int dist[505][505];
int inqu[505][505];

class Escape {
public:
	int lowest(vector<string> harmful, vector<string> deadly) {
		memset(grid, 0, sizeof grid);
		for (int i = 0; i < harmful.size(); ++i) {
			istringstream input(harmful[i]);
			int x1, y1, x2, y2;
			input >> x1 >> y1 >> x2 >> y2;
			int mn, mx;
			mn = min(x1, x2);
			mx = max(x1, x2);
			x1 = mn;
			x2 = mx;
			mn = min(y1, y2);
			mx = max(y1, y2);
			y1 = mn;
			y2 = mx;
			for (int x = x1; x <= x2; ++x) {
				for (int y = y1; y <= y2; ++y) {
					grid[x][y] = 1;
				}
			}
		}
		for (int i = 0; i < deadly.size(); ++i) {
			istringstream input(deadly[i]);
			int x1, y1, x2, y2;
			input >> x1 >> y1 >> x2 >> y2;
			int mn, mx;
			mn = min(x1, x2);
			mx = max(x1, x2);
			x1 = mn;
			x2 = mx;
			mn = min(y1, y2);
			mx = max(y1, y2);
			y1 = mn;
			y2 = mx;
			for (int x = x1; x <= x2; ++x) {
				for (int y = y1; y <= y2; ++y) {
					grid[x][y] = 2;
				}
			}
		}
		memset(dist, -1, sizeof dist);
		return bfs();
	}
	
private:
	int bfs() {
		queue<pair<int, int> > qu;
		dist[0][0] = 0;
		qu.push(make_pair(0, 0));
		memset(inqu, 0, sizeof inqu);
		inqu[0][0] = 1;
		while (!qu.empty()) {
			pair<int, int> cur = qu.front();
			qu.pop();
			inqu[cur.first][cur.second] = 0;
			for (int d = 0; d < 4; ++d) {
				int xp, yp;
				xp = cur.first + dx[d];
				yp = cur.second + dy[d];				
				if (ok(xp, yp) && grid[xp][yp] != 2) {
					if (dist[xp][yp] == -1 || dist[xp][yp] > dist[cur.first][cur.second] + grid[xp][yp]) {
						dist[xp][yp] = dist[cur.first][cur.second] + grid[xp][yp];
						if (!inqu[xp][yp]) {
							inqu[xp][yp] = 1;
							qu.push(make_pair(xp, yp));
						}
					}
				}
			}
		}	
		return dist[500][500];	
	}
	
	int ok(int x, int y) {
		return x >= 0 && x <= 500 && y >= 0 && y <= 500;
	}
};