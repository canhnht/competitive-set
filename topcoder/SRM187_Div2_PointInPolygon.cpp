#include <bits/stdc++.h>

using namespace std;

const int MAXN = 55;
const double EPS = 1e-8;

class PointInPolygon {
private:
	int N;
	double a[MAXN][2];
	
	double cross(double p1[], double p2[], double p3[]) {
		double v1[2], v2[2];
		v1[0] = p2[0] - p1[0];
		v1[1] = p2[1] - p1[1];
		
		v2[0] = p3[0] - p1[0];
		v2[1] = p3[1] - p1[1];
		
		return v1[0] * v2[1] - v1[1] * v2[0];
	}
	
	double dot(double p1[], double p2[], double p3[]) {
		double v1[2];
		double v2[2];
		v1[0] = p2[0] - p1[0];
		v1[1] = p2[1] - p1[1];
		
		v2[0] = p3[0] - p1[0];
		v2[1] = p3[1] - p1[1];
		
		return v1[0] * v2[0] + v1[1] * v2[1];
	}
	
	double distPointToLine(double p[], double p1[], double p2[]) {
		double ret = abs(cross(p, p1, p2) / 2);
		return ret / dist(p1, p2);
	}

	double distPointToSegment(double p[], double p1[], double p2[]) {
		if (dot(p, p1, p2) > 0) return dist(p, p1);
		if (dot(p, p2, p1) > 0) return dist(p, p2);
		double ret = abs(cross(p, p1, p2) / 2);
		ret /= dist(p1, p2);
		return ret;
	}
		
	double dist(double p1[], double p2[]) {
		double v[2];
		v[0] = p2[0] - p1[0];
		v[1] = p2[1] - p1[1];
		return sqrt(v[0] * v[0] + v[1] * v[1]);
	}
	
	bool intersect(double a1[], double b1[], double a2[], double b2[]) {
		double c1[3], c2[3];		
		getCoeff(a1, b1, c1);
		getCoeff(a2, b2, c2);
		
		double det = c1[0] * c2[1] - c2[0] * c1[1];
		if (det == 0) return false;
		double dx = c1[1] * c2[2] - c2[1] * c1[2];
		double dy = c1[2] * c2[0] - c2[2] * c1[0];
		double p[2];
		p[0] = dx / det;
		p[1] = dy / det;
		return pointInSegment(p, a1, b1) && pointInSegment(p, a2, b2);
	}
	
	bool pointInSegment(double p[], double p1[], double p2[]) {
		return p[0] >= min(p1[0], p2[0]) && p[0] <= max(p1[0], p2[0]) && p[1] >= min(p1[1], p2[1]) && p[1] <= max(p1[1], p2[1]);
	}
	
	void getCoeff(double p1[], double p2[], double c[]) {
		c[0] = p2[1] - p1[1];
		c[1] = p1[0] - p2[0];
		c[2] = -c[0] * p1[0] - c[1] * p1[1];
	}
	
public:
	string testPoint(vector<string> v, int x, int y) {
		double test[2];
		test[0] = x;
		test[1] = y;
		N = v.size();
		for (int i = 0;i < v.size(); ++i) {
			stringstream ss(v[i]);
			ss >> a[i][0] >> a[i][1];			
		}
		srand(time(NULL));
		double p[2];
		p[0] = rand() % 10000 + 10000;
		p[1] = rand() % 10000 + 10000;
		a[N][0] = a[0][0];
		a[N][1] = a[0][1];
		int res = 0;
		for (int i = 0; i < N; ++i) {
			if (distPointToSegment(test, a[i], a[i + 1]) <= EPS) {
				return "BOUNDARY";
			}
			if (intersect(test, p, a[i], a[i + 1])) ++res;
		}
		if (res & 1) return "INTERIOR";
		else return "EXTERIOR";
	}
};