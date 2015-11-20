#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;
const int MAXN = 16;
const int INF = 0x3f3f3f3f;

int dp[1 << MAXN][MAXN];
int visited[1 << MAXN];
int N;

class KiloManX {
public:
	int leastShots(vector<string> damageChart, vector<int> bossHealth) {
		N = damageChart.size();
		memset(dp, -1, sizeof dp);	
		memset(visited, 0, sizeof visited);	
		for (int i = 0; i < N; ++i) dp[0][i] = 0;
		visited[0] = 1;
		for (int state = 0; state < (1 << N); ++state) {
			if (visited[state]) {
				for (int i = 0; i < N; ++i) {
					if (((state >> i) & 1) == 0) {
						int next = state ^ (1 << i);
						visited[next] = 1;
						int maxDam = 1;
						int minVal = INF;
						for (int k = 0; k < N; ++k) {
							if ((state >> k) & 1) {
								maxDam = max(maxDam, damageChart[k][i] - '0');
								minVal = min(minVal, dp[state][k]);
							}
						}						
						if (minVal == INF) minVal = 0;
						if (dp[next][i] == -1 || dp[next][i] > minVal + (bossHealth[i] + maxDam - 1) / maxDam) {							
							dp[next][i] = minVal + (bossHealth[i] + maxDam - 1) / maxDam;
						}
					}
				}
			}
		}
		int res = INF;
		for (int i = 0; i < N; ++i) {
			res = min(res, dp[(1 << N) - 1][i]);
		}
		return res;
	}
};