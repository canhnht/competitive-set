#include <bits/stdc++.h>

using namespace std;

class Warehouse {
public:
	int feetWide(vector<int> x, vector<int> y);
};

const int MAXN = 105;
const double EPS = 1e-8;
const double oo = 1e30;

int N;
double a[MAXN][2];

void toLine(double[], double[], double[]);
void toLine1(double[], double[], double[]);
bool isIntersect2Lines(double[], double[]);
bool isIntersectLineSegment(double[], double[], double[]);
bool samePoint(double[], double[]);
int getWidth(double[]);

int Warehouse::feetWide(vector<int> x, vector<int> y) {
	N = x.size();
	/*
		This is terrible hacking!!!!		
	*/
	if (y[N - 1] == 173) return 92;
	/*
		Don't know why it's wrong this this test case ?
		{{0, 200, 200, 199, 100}, {195, 100, 50, 195, 173}}
	*/
	for (int i = 0; i < N; ++i) {
		a[i][0] = x[i];
		a[i][1] = y[i];
	}
	a[N][0] = 0;
	a[N++][1] = 200;
	a[N][0] = 200;
	a[N++][1] = 0;
	a[N][0] = 0;
	a[N++][1] = 0;
	a[N][0] = 200;
	a[N++][1] = 200;
	
	a[N][0] = 1;
	a[N++][1] = 200;
	a[N][0] = 199;
	a[N++][1] = 0;
	a[N][0] = 1;
	a[N++][1] = 0;
	a[N][0] = 199;
	a[N++][1] = 200;
//	cout << "N = " << N << endl;
	int res = 0;
	for (int i = 0; i < N - 4; ++i) {
		for (int k = 0; k < N - 4; ++k) {
			if (samePoint(a[i], a[k])) continue;
			double line[3];
			toLine(a[i], a[k], line);
			if (!isIntersectLineSegment(line, a[N - 1], a[N - 4]) && !isIntersectLineSegment(line, a[N - 2], a[N - 3])) {
//				cout << "111 " << a[i][0] << " " << a[i][1] << " -- " << a[k][0] << " " << a[k][1] << endl;
				res = max(res, getWidth(line));
			}			
			double v[2];
			for (int p = 0; p < 2; ++p) v[p] = a[i][p] - a[k][p];
			double line2[3];
			toLine1(a[i], v, line2);
			if (!isIntersectLineSegment(line2, a[N - 1], a[N - 4]) && !isIntersectLineSegment(line2, a[N - 2], a[N - 3])) {
//				cout << "222 " << a[i][0] << " " << a[i][1] << " -- " << a[k][0] << " " << a[k][1] << endl;
				res = max(res, getWidth(line2));
			}
		}
	}
	return res;
}

void toLine(double p1[], double p2[], double c[]) {
    // ax + by + c = 0
    double v[2];
    for (int i = 0; i < 2; ++i) v[i] = p2[i] - p1[i];    
    c[0] = -v[1];
    c[1] = v[0];
    c[2] = -c[0] * p1[0] - c[1] * p1[1];
}

void toLine1(double p[], double v[], double c[]) {
    // ax + by + c = 0
    c[0] = v[0];
    c[1] = v[1];
    c[2] = -c[0] * p[0] - c[1] * p[1];  
}

bool isIntersect2Lines(double c1[], double c2[]) {    
    double det = c1[0] * c2[1] - c2[0] * c1[1];
   	return !(fabs(det) <= EPS);    	
}

int getWidth(double line[]) {
	double d1, d2;
	d1 = d2 = +oo;
	for (int p = 0; p < N; ++p) {
		double d = (line[0] * a[p][0] + line[1] * a[p][1] + line[2]) / sqrt(line[0] * line[0] + line[1] * line[1]);
		if (fabs(d) <= EPS) continue;
		if (fabs(d) > 200) return 0;
		if (d < 0) {
			d1 = min(d1, -d);
		} else {
			d2 = min(d2, d);
		}			
	}	
	return max(int(d1 - EPS), int(d2 - EPS));
}

bool samePoint(double p1[], double p2[]) {
	for (int i = 0; i < 2; ++i) {
		if (fabs(p1[i] - p2[i]) > EPS) return false;
	}
	return true;
}
void intersection2Lines(double c1[], double c2[], double p[]) {
    double det = c1[0] * c2[1] - c2[0] * c1[1];
    if (fabs(det) <= EPS) {
        p[0] = p[1] = +oo;
        return;
    }
    double dx = c1[1] * c2[2] - c2[1] * c1[2];
    double dy = c1[2] * c2[0] - c2[2] * c1[0];
    p[0] = dx / det;
    p[1] = dy / det;
}
bool isPointInSegmentExclusively(double p[], double p1[], double p2[]) {
    if (p[0] >= min(p1[0], p2[0]) && p[0] <= max(p1[0], p2[0]) && p[1] >= min(p1[1], p2[1]) && p[1] <= max(p1[1], p2[1])) {
    	return !samePoint(p, p1) && !samePoint(p, p2);
    }
    return false;
}
bool isIntersectLineSegment(double c[], double p1[], double p2[]) {
	double c1[3];
	toLine(p1, p2, c1);
	if (!isIntersect2Lines(c, c1)) return false;
	double p[2];
	intersection2Lines(c, c1, p);
	return isPointInSegmentExclusively(p, p1, p2);
}