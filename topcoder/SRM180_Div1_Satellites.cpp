#include <bits/stdc++.h>

using namespace std;

const int MAXN = 55;
const double PI = 2 * acos(0.0);
const double EPS = 1e-10;

class Satellites {
private:
	double ORIGIN[3] = {0, 0, 0};
	double EARTH_RADIUS = 6400;
	
	int nRockets, nSats;
	double r[MAXN][3], s[MAXN][3];
	
	void sphere2XYZ(double p[], double radius, double q[]) {
		p[0] = p[0] / 180 * PI;
		p[1] = p[1] / 180 * PI;
		q[2] = radius * sin(p[0]);
		q[1] = radius * cos(p[0]) * sin(p[1]);
		q[0] = radius * cos(p[0]) * cos(p[1]);
	}
	
	double cross3D(double a[], double b[], double c[]) {
		double p1[3], p2[3];
		for (int i = 0; i < 3; ++i) {
			p1[i] = b[i] - a[i];
			p2[i] = c[i] - a[i];
		}
		double v[3];
		v[0] = p1[1] * p2[2] - p2[1] * p1[2];
		v[1] = p1[2] * p2[0] - p2[2] * p1[0];
		v[2] = p1[0] * p2[1] - p2[0] * p1[1];
		return sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
	}
	
	double dot3D(double p1[], double p2[], double p3[]) {
		double v1[3], v2[3];
		for (int i = 0; i < 3; ++i) {
			v1[i] = p2[i] - p1[i];
			v2[i] = p3[i] - p2[i];
		}
		double ret = 0;
		for (int i = 0; i < 3; ++i) ret += v1[i] * v2[i];
		return ret;
	}
	
	double dist3D(double p1[], double p2[]) {
		double v[3];
		for (int i = 0; i < 3; ++i) v[i] = p2[i] - p1[i];
		return sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
	}
	
	double distPointToLine3D(double p[], double p1[], double p2[]) {
		return cross3D(p, p1, p2) / dist3D(p1, p2);
	}
	
	bool equal3D(double p1[], double p2[]) {
		return dist3D(p1, p2) <= EPS;
	}
	
	bool canMonitor(double p1[], double p2[]) {
		if (equal3D(p1, p2)) {
			return true;
		}		
		cout << "dot " << dot3D(ORIGIN, p1, p2) << endl;
		if (dot3D(ORIGIN, p1, p2) > 0) return true;
		if (dot3D(ORIGIN, p2, p1) > 0) return true;
		cout << "dist " << distPointToLine3D(ORIGIN, p1, p2) << endl;
		if (distPointToLine3D(ORIGIN, p1, p2) > EARTH_RADIUS) {
			return true;
		}	
		return false;
	}
	
public:
	vector<int> detectable(vector<string> rockets, vector<string> satellites) {
		nRockets = rockets.size();
		double p[2], h;
		for (int i = 0; i < nRockets; ++i) {
			stringstream ss(rockets[i]);
			ss >> p[0] >> p[1];
			cout << p[0] << " " << p[1] << endl;
			sphere2XYZ(p, EARTH_RADIUS + 400, r[i]);
		}	
		nSats = satellites.size();
		for (int i = 0; i < nSats; ++i) {
			stringstream ss(satellites[i]);
			ss >> p[0] >> p[1] >> h;
			sphere2XYZ(p, EARTH_RADIUS + h, s[i]);
		}
		vector<int> res;
		res.clear();
		for (int i = 0; i < nRockets; ++i) {
			int cnt = 0;
			for (int k = 0; k < nSats; ++k) {
				if (canMonitor(r[i], s[k])) cout << i << " " << k << endl;
				cnt += canMonitor(r[i], s[k]);
			}
			cout << cnt << endl;
			if (cnt >= 3) res.push_back(i);
		}
		return res;
	}
};