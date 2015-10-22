#include <bits/stdc++.h>

using namespace std;

const int MAXN = 15;
const double PI = 2 * acos(0.0);

class Travel {
private:
	int N;
	double a[MAXN][3];
	double d[MAXN][MAXN];
	
	void sphereToXYZ(double p[], int dist, double q[]) {
		p[0] = p[0] / 180 * PI;
		p[1] = p[1] / 180 * PI;
		q[0] = dist * cos(p[0]) * cos(p[1]);
		q[1] = dist * cos(p[0]) * sin(p[1]);
		q[2] = dist * sin(p[0]);
	}
	
	double dist3D(double v[]) {
		double ret = 0;
		for (int i = 0; i < 3; ++i) ret += v[i] * v[i];
		return sqrt(ret);
	}
	
	double distCurve3D(double p1[], double p2[], int radius) {
		double dot = 0;
		for (int i = 0; i < 3; ++i) dot += p1[i] * p2[i];
		double angle = acos(dot / dist3D(p1) / dist3D(p2));
		return angle * radius;		
	}
	
	double calc(int order[]) {
		double ret = 0;
		for (int i = 1; i < N; ++i) {
			ret += d[order[i - 1]][order[i]];
		}
		ret += d[order[N - 1]][order[0]];
		return ret;
	}
	
public:
	int shortest(vector<string> city, int radius) {
		N = city.size();
		double p[2];
		for (int i = 0; i < N; ++i) {
			stringstream ss(city[i]);
			ss >> p[0] >> p[1];
			sphereToXYZ(p, radius, a[i]);
		}
		for (int i = 0; i < N; ++i) {
			for (int k = 0; k < N; ++k) {
				d[i][k] = distCurve3D(a[i], a[k], radius);
			}
		}
		int id[N];
		for (int i = 0; i < N; ++i) id[i] = i;
		double res = 1e30;
		do {
			res = min(res, calc(id));
		} while (next_permutation(id + 1, id + N));
//		cout << res << endl;
		return res + 0.5;
	}
};