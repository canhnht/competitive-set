#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstring>

using namespace std;
const int MAXN = 100;

vector<string> grid;
int N;
int visited[MAXN], mark;
int cnt[MAXN];

class TeamBuilder {
public:
	vector<int> specialLocations(vector<string> paths) {
		vector<int> res(2, 0);
		N = paths.size();
		grid = paths;
		mark = 0;
		memset(visited, 0, sizeof visited);
		memset(cnt, 0, sizeof cnt);
		for (int i = 0; i < N; ++i) {
			if (bfs(i) == N) {
				++res[0];
			}
		}		
		for (int i = 0; i < N; ++i) res[1] += cnt[i] == N;
		return res;
	}
	
private:
	int bfs(int u) {
		queue<int> qu;		
		++mark;
		qu.push(u);
		visited[u] = mark;
		++cnt[u];
		int ret = 1;
		while (!qu.empty()) {
			int cur = qu.front();
			qu.pop();
			for (int i = 0; i < N; ++i) {
				if (visited[i] != mark && grid[cur][i] == '1') {
					visited[i] = mark;
					qu.push(i);
					++cnt[i];
					++ret;
				}
			}
		}
		return ret;
	}
};