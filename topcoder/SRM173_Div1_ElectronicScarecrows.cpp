#include <bits/stdc++.h>

using namespace std;

class ElectronicScarecrows {
public:
	double largestArea(vector<int> x, vector<int> y, int n);
};

// ===============================

typedef pair<double, double> pdd;

const int MAXN = 55;
const double EPS = 1e-8;

double a[MAXN][2];
double dp[MAXN][MAXN];
int N;

double cross(double [], double [], double []);
double dist(double [], double []);
int convex(double [][2]);
	
bool cmp(pdd p1, pdd p2) {
	double t1[2], t2[2];
	t1[0] = p1.first;
	t1[1] = p1.second;
	
	t2[0] = p2.first;
	t2[1] = p2.second;
	
	if (fabs(cross(a[0], t1, t2)) <= EPS) return dist(a[0], t1) < dist(a[0], t2);
	return cross(a[0], t1, t2) > 0;
}
	
double ElectronicScarecrows::largestArea(vector<int> x, vector<int> y, int n) {
/*
	x = vector<int>(39, 1);
	x.push_back(2);
	y.clear();
	for (int i = 0; i < 40; ++i) {
		y.push_back(i);
	}
	n = 3;	
*/
	
	N = x.size();
	for (int i = 0; i < N; ++i) {
		a[i][0] = x[i];
		a[i][1] = y[i];
	}
	N = convex(a);
//	cout << N << " " << n << endl;
//	for (int i = 0; i < N; ++i) cout << a[i][0] << " " << a[i][1] << endl;
	double res = 0;
	if (n >= N) {
		for (int i = 1; i + 1 < N; ++i) {
			res += fabs(cross(a[0], a[i], a[i + 1]) / 2);
		}
		return res;
	}
	for (int start = 0; start < N; ++start) {
		memset(dp, 0, sizeof dp);
		int id[MAXN];
		for (int i = 1; i < N; ++i) {
			id[i - 1] = (start + i) % N;
		}
		for (int i = 3; i <= n; ++i) {
			for (int k = 1; k < N - 1; ++k) {
				for (int p = k - 1; p >= 0; --p) {
					dp[i][k] = max(dp[i][k], dp[i - 1][p] + fabs(cross(a[start], a[id[p]], a[id[k]])) / 2);
				}
//				cout << i << " " << k << " " << dp[i][k] << endl;
				res = max(res, dp[i][k]);
			}
		}
	}
	return res;
}

double cross(double p[], double p1[], double p2[]) {
	double v1[2], v2[2];
	for (int i = 0; i < 2; ++i) {
		v1[i] = p1[i] - p[i];
		v2[i] = p2[i] - p[i];
	}
	return v1[0] * v2[1] - v2[0] * v1[1];
}

int convex(double b[][2]) {
	int p = 0;
	for (int i = 1; i < N; ++i) {
		if (b[i][1] < b[p][1] || (b[i][1] == b[p][1] && b[i][0] < b[p][0])) {
			p = i;
		}
	}
	swap(b[0][0], b[p][0]);
	swap(b[0][1], b[p][1]);
//	for (int i = 0; i < N; ++i) cout << b[i][0] << " " << b[i][1] << endl;
	auto aa = (pdd*)b;
	sort(aa + 1, aa + N, cmp);
	b[N][0] = b[0][0];
	b[N][1] = b[0][1];
	++N;
//	for (int i = 0; i < N; ++i) cout << b[i][0] << " " << b[i][1] << endl;
	int M = 2;
	for (int i = 2; i < N; ++i) {
		bool ok = true;
		while (M >= 2 && cross(b[M - 2], b[M - 1], b[i]) <= 0) {
			if (fabs(cross(b[M - 2], b[M - 1], b[i])) <= EPS) {
				ok = false;
				if (dist(b[M - 2], b[M - 1]) < dist(b[M - 2], b[i])) {
					b[M - 1][0] = b[i][0];
					b[M - 1][1] = b[i][1];
				}
				break;
			}
			--M;
		}
		if (ok) {
			b[M][0] = b[i][0];
			b[M][1] = b[i][1];
			++M;
		}
	}
	return M;
}

double dist(double p1[], double p2[]) {
	double ret = 0;
	for (int i = 0; i < 2; ++i) ret += (p1[i] - p2[i]) * (p1[i] - p2[i]);
	return sqrt(ret);
}