#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50;
const double EPS = 1e-7;
const double PI = 2 * acos(0.0);

class PuckShot {
private:
	double puck[2];
	double res[2];
	double a[MAXN][2];
	int N;
	
	void getRange(double y, double x1, double x2, double r[]) {
		r[0] = atan2(y - puck[1], x2 - puck[0]) * 180 / PI;
		r[1] = atan2(y - puck[1], x1 - puck[0]) * 180 / PI;
	}
	
	bool cmp(double p1[], double p2[]) {
		return p1[1] > p2[1];
	}
	
public:
	double caromAngle(int puckCoord, vector<int> xCoords, vector<int> yCoords) {
		puck[0] = puckCoord;
		puck[1] = 0;
		getRange(1733, 4500 - 183/2.0, 4500 + 183/2.0, res);	
		
		N = xCoords.size();
		for (int i = 0; i < N; ++i) {
			getRange(yCoords[i], xCoords[i] - 25, xCoords[i] + 25, a[i]);
			xCoords[i] = 6000 - xCoords[i];
			getRange(yCoords[i], xCoords[i] - 25, xCoords[i] + 25, a[i + N]);
		} 
		
		N = N * 2;
		for (int i = 0; i < N; ++i) {
			for (int k = i + 1; k < N; ++k) {
				if (cmp(a[k], a[i])) {
					swap(a[i][0], a[k][0]);
					swap(a[i][1], a[k][1]);
				}
			}
		}
		for (int i = 0; i < N; ++i) {
			if (a[i][1] < res[1]) break;
			res[1] = min(res[1], a[i][0]);
		}
		if (res[1] < res[0]) return -1;
		return res[1];
	}
};