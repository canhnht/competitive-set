#include <bits/stdc++.h>

using namespace std;

class Tether {
public:
	int deadTrees(int rope, int radius, vector<int> x, vector<int> y);
};

const int MAXN = 55;

int N;
double a[MAXN][2];
double R, len;

bool isDead(double[]);
double dist(double[], double[]);
double dot(double[], double[], double[]);

int Tether::deadTrees(int rope, int radius, vector<int> x, vector<int> y) {
	R = radius;
	len = rope;
	N = x.size();
	for (int i = 0; i < N; ++i) {
		a[i][0] = x[i];
		a[i][1] = y[i];
	}
	int res = 0;
	for (int i = 0; i < N; ++i) {
		res += isDead(a[i]);
	}
	return res;
}

bool isDead(double p[]) {
	double goat[2];
	goat[0] = 0;
	goat[1] = -R;
	if (p[1] <= -R) {
//		cout << "case 1 " << dist(goat, p) << endl;
		return dist(goat, p) <= len;
	}
	double d1 = sqrt(p[0] * p[0] + p[1] * p[1] - R * R);
	double origin[2] = {0, 0};
	double angle = acos(dot(origin, p, goat) / (dist(origin, goat) * dist(origin, p))) - acos(R / dist(origin, p));
//	cout << "case 2 " << d1 << " " << angle << endl;
	return d1 + angle * R <= len;
}

double dist(double p1[], double p2[]) {
	double ret = 0;
	for (int i = 0; i < 2; ++i) ret += (p2[i] - p1[i]) * (p2[i] - p1[i]);
	return sqrt(ret);
}

double dot(double p[], double p1[], double p2[]) {
	double v1[2], v2[2];
	for (int i = 0; i < 2; ++i) {
		v1[i] = p1[i] - p[i];
		v2[i] = p2[i] - p[i];
	}
	return v1[0] * v2[0] + v1[1] * v2[1];
}