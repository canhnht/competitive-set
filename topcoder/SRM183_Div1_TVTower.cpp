#include <bits/stdc++.h>

using namespace std;

const int MAXN = 55;
const double oo = 1e30;
const double EPS = 1e-8;

class TVTower {
private:
	int N;
	double a[MAXN][2];
	double res;
	
	double radius(double p[]) {
		double ret = 0;
		for (int i = 0; i < N; ++i) {
			ret = max(ret, dist(a[i], p));
		}
		return ret;
	}
	
	double dist(double p1[], double p2[]) {
		double v[2];
		v[0] = p2[0] - p1[0];
		v[1] = p2[1] - p1[1];
		return sqrt(v[0] * v[0] + v[1] * v[1]);
	}
	
	void getCoeff(double p[], double v[], double c[]) {
		c[0] = v[0];
		c[1] = v[1];
		c[2] = -c[0] * p[0] - c[1] * p[1];	
	}
	
	void getIntersection(double c1[], double c2[], double p[]) {
		double det = c1[0] * c2[1] - c2[0] * c1[1];
		if (det == 0) {
			p[0] = p[1] = oo;
			return;
		}
		double dx = c1[1] * c2[2] - c2[1] * c1[2];
		double dy = c1[2] * c2[0] - c2[2] * c1[0];
		p[0] = dx / det;
		p[1] = dy / det;
	}
	
public:
	double minRadius(vector<int> x, vector<int> y) {
		N = x.size();		
		if (N == 1) return 0;
		for (int i = 0; i < N; ++i) {
			a[i][0] = x[i];
			a[i][1] = y[i];
		}
		double p[2], q[2];
		double c1[3], c2[3];
		double v1[2], v2[2];
		res = +oo;
		for (int i = 0; i < N; ++i) {
			for (int k = i + 1; k < N; ++k) {
				p[0] = (a[i][0] + a[k][0]) / 2;
				p[1] = (a[i][1] + a[k][1]) / 2;
				res = min(res, radius(p));
				for (int t = k + 1; t < N; ++t) {
					q[0] = (a[k][0] + a[t][0]) / 2;
					q[1] = (a[k][1] + a[t][1]) / 2;
					
					v1[0] = a[i][0] - a[k][0];
					v1[1] = a[i][1] - a[k][1];
					v2[0] = a[t][0] - a[k][0];
					v2[1] = a[t][1] - a[k][1];

					getCoeff(p, v1, c1);
					getCoeff(q, v2, c2);
//					cout << "c1 " << c1[0] << " " << c1[1] << " " << c1[2] << endl;
//					cout << "c2 " << c2[0] << " " << c2[1] << " " << c2[2] << endl;
					getIntersection(c1, c2, q);
//					cout << "intersection " << q[0] << " " << q[1] << endl;
					
					if (abs(q[0] - oo) > EPS) {
						res = min(res, radius(q));
					}			
//					cout << "res " << res << endl;
				}
			}
		}	
		return res;
	}
};