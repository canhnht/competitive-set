#include <bits/stdc++.h>

using namespace std;

const int MAXN = 55;

class ConvexPolygon {
private:
	int N;
	double a[MAXN][2];
	
	double cross(double p[], double p1[], double p2[]) {
		double v1[2], v2[2];
		for (int i = 0; i < 2; ++i) {	
			v1[i] = p1[i] - p[i];
			v2[i] = p2[i] - p[i];
		}
		return v1[0] * v2[1] - v1[1] * v2[0];
	}
	
public:
	double findArea(vector<int> x, vector<int> y) {
		N = x.size();
		for (int i = 0; i < N; ++i) {
			a[i][0] = x[i];
			a[i][1] = y[i];
		}
		
		double res = 0;
		for (int i = 1; i < N - 1; ++i) {
			res += cross(a[0], a[i], a[i + 1]);
		}	
		return abs(res) / 2;
	}
};