#include <bits/stdc++.h>

using namespace std;

class Symmetry {
public:
	int countLines(vector<string> points);
};

typedef long long ll;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> ppl;

const int MAXN = 200 + 5;
const double EPS = 1e-8;

int N;
double a[MAXN][2], b[MAXN][2];
double res[MAXN * MAXN][3];
int cnt;

void reflect(double[], double[], double[]);
bool sameLine(double[], double[]);
bool isSymmetry(double[]);

int Symmetry::countLines(vector<string> points) {
	N = 0;
	for (int i = 0;	i < points.size(); ++i) {
		stringstream ss(points[i]);
		double x, y;
		while (ss >> x >> y) {
			a[N][0] = x;
			a[N][1] = y;
			++N;
		}
	}
	
//	cout << "N = " << N << endl;
//	for (int i = 0; i < N; ++i) cout << a[i][0] << " " << a[i][1] << endl;
	
	auto temp = (pdd*)a;
	sort(temp, temp + N);
	cnt = 0;
	for (int i = 0; i < N; ++i) {
		for (int k = i + 1; k < N; ++k) {
//			cout << "iii = " << a[i][0] << " " << a[i][1] << endl;
//			cout << "kkk = " << a[k][0] << " " << a[k][1] << endl;
			double line[3];
			line[0] = a[k][0] - a[i][0];
			line[1] = a[k][1] - a[i][1];
			double m[2];
			m[0] = (a[i][0] + a[k][0]) / 2;
			m[1] = (a[i][1] + a[k][1]) / 2;
			line[2] = -line[0] * m[0] - line[1] * m[1];
//			cout << line[0] << " " << line[1] << " " << line[2] << endl;			
			if (isSymmetry(line)) {
				bool add = true;
				for (int p = 0; p < cnt; ++p) {
					if (sameLine(res[p], line)) {
						add = false;
						break;
					}
				}
				if (add) {
//					cout << "added" << endl;
					res[cnt][0] = line[0];
					res[cnt][1] = line[1];
					res[cnt][2] = line[2];
					++cnt;
				}
			}
			swap(line[0], line[1]);
			line[0] = -line[0];
			line[2] = -line[0] * m[0] - line[1] * m[1];
			if (isSymmetry(line)) {
				bool add = true;
				for (int p = 0; p < cnt; ++p) {
					if (sameLine(res[p], line)) {
						add = false;
						break;
					}
				}
				if (add) {
//					cout << "added" << endl;
					res[cnt][0] = line[0];
					res[cnt][1] = line[1];
					res[cnt][2] = line[2];
					++cnt;
				}
			}
		}
	}
	return cnt;
}

void reflect(double line[], double p[], double q[]) {
	double temp[3];
	temp[0] = line[1];
	temp[1] = -line[0];
	temp[2] = -temp[0] * p[0] - temp[1] * p[1];
	
	double d = line[0] * temp[1] - temp[0] * line[1];
	double dx = line[1] * temp[2] - temp[1] * line[2];
	double dy = line[2] * temp[0] - temp[2] * line[0];
	dx /= d;
	dy /= d;
	q[0] = 2 * dx - p[0];
	q[1] = 2 * dy - p[1];
}

bool sameLine(double l1[], double l2[]) {
	double d = l1[0] * l2[1] - l2[0] * l1[1];
	if (fabs(d) <= EPS) {
		if (fabs(l1[2] * l2[1] - l1[1] * l2[2]) <= EPS) {
			return true;
		}
	}
	return false;
}

bool isSymmetry(double line[]) {
	for (int p = 0; p < N; ++p) {
				reflect(line, a[p], b[p]);
			}
			auto temp = (pdd*)b;
			sort(temp, temp + N);
			bool ok = true;
			for (int p = 0; p < N; ++p) {
				if (fabs(b[p][0] - a[p][0]) > EPS || fabs(b[p][1] - a[p][1]) > EPS) {
					ok = false;
					break;
				}
			}
	return ok;
}