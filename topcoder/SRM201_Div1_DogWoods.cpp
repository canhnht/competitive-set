#include <bits/stdc++.h>

using namespace std;

class DogWoods {
public:
	double howFar(vector<int> x, vector<int> y, vector<int> diameter, int startX, int startY);
};

const int MAXN = 55;
const double EPS = 1e-8;
const double PI = 2 * acos(0.0);
const double foo = 1e30;

int N;
double circles[MAXN][3];

bool isIntersect2Circles(double[], double[]);
double dist(double p1[], double p2[]);
void intersection2Circles(double[], double[], double[], double[]);
void intersectionCircleLine(double[], double[], double[], double[]);
double normalize(double);

double DogWoods::howFar(vector<int> x, vector<int> y, vector<int> diameter, int startX, int startY) {
	N = x.size();
	for (int i = 0; i < N; ++i) {
		circles[i][0] = x[i];
		circles[i][1] = y[i];
		circles[i][2] = diameter[i] / 2.0;
	}
	double cur[2];
	cur[0] = startX;
	cur[1] = startY;
	if (hypot(cur[0], cur[1]) <= 10) return 0;
	double limit[3];
	limit[0] = limit[1] = 0;
	limit[2] = 10;
	double res = 0;
	while (true) {
		double temp[3];
		temp[0] = 0;
		temp[1] = 0;
		temp[2] = hypot(cur[0], cur[1]);
		double maxP[2], angle = +foo;		
		maxP[0] = maxP[1] = 0;		
		int id = -1;
		for (int i = 0; i < N; ++i) {
			if (isIntersect2Circles(temp, circles[i])) {
				double p1[2], p2[2];
				intersection2Circles(temp, circles[i], p1, p2);
//				cout << "intersection " << p1[0] << " " << p1[1] << " --- " << p2[0] << " " << p2[1] << endl;
				double angle1 = normalize(atan2(cur[1], cur[0]) - atan2(p1[1], p1[0]));
				double angle2 = normalize(atan2(cur[1], cur[0]) - atan2(p2[1], p2[0]));
//				cout << "angle " << (angle1 / PI * 180) << " " << (angle2 / PI * 180)  << endl;
				if (angle1 < angle) {
					angle = angle1;
					maxP[0] = p1[0];
					maxP[1] = p1[1];					
					id = i;
				}
				if (angle2 < angle) {
					angle = angle2;
					maxP[0] = p2[0];
					maxP[1] = p2[1];
					id = i;
				}
			}
		}
		if (id == -1) return -1;
//		cout << "min angle " << (angle / PI * 180) << endl;
		res += angle * temp[2];
//		cout << "res " << res << endl;
		if (isIntersect2Circles(limit, circles[id])) {
//			cout << "go" << endl;
			double p1[2], p2[2];
			intersection2Circles(limit, circles[id], p1, p2);
			for (int i = 0; i < 2; ++i) {
				p1[i] -= circles[id][i];
				p2[i] -= circles[id][i];
			}
			double angle1, angle2;
			angle1 = normalize(atan2(p1[1], p1[0]) - atan2(maxP[1] - circles[id][1], maxP[0] - circles[id][0]));
			angle2 = normalize(atan2(p2[1], p2[0]) - atan2(maxP[1] - circles[id][1], maxP[0] - circles[id][0]));
//			cout << "angle " << (angle1 / PI * 180) << " -- " << (angle2 / PI * 180) << endl;
			angle1 = min(angle1, angle2);
//			cout << "angle1111 " << (angle1 / PI * 180) << endl;
			res += angle1 * circles[id][2];
			break;
		} else {
			double dist = sqrt(circles[id][0] * circles[id][0] + circles[id][1] * circles[id][1]) - circles[id][2];
			cur[0] = dist * circles[id][0] / sqrt(circles[id][0] * circles[id][0] + circles[id][1] * circles[id][1]);
			cur[1] = dist * circles[id][1] / sqrt(circles[id][0] * circles[id][0] + circles[id][1] * circles[id][1]);
			res += normalize(atan2(cur[1] - circles[id][1], cur[0] - circles[id][0]) - atan2(maxP[1] - circles[id][1], maxP[0] - circles[id][0])) * circles[id][2];
//			cout << "currrr " << id << " -- " << cur[0] << " " << cur[1] << endl;
		}
	}
	return res;
}

double dist(double p1[], double p2[]) {
    double ret = 0;
    for (int i = 0; i < 2; ++i) ret += (p1[i] - p2[i]) * (p1[i] - p2[i]);
    return sqrt(ret);
}

bool isIntersect2Circles(double c1[], double c2[]) {
	return dist(c1, c2) + EPS < c1[2] + c2[2] && dist(c1, c2) >= fabs(c1[2] - c2[2]);
}

void intersection2Circles(double c1[], double c2[], double p1[], double p2[]) {
	double line[3];	// radical line
	line[0] = 2 * (c2[0] - c1[0]);
	line[1] = 2 * (c2[1] - c1[1]);
	line[2] = (c2[2] * c2[2] - c1[2] * c1[2]) - (c2[1] * c2[1] - c1[1] * c1[1]) - (c2[0] * c2[0] - c1[0] * c1[0]);
		
	// intersections between line and c1
	intersectionCircleLine(c1, line, p1, p2);
}

double normalize(double x) {
	if (x < 0) return x + 2 * PI;
	return x;
}

void intersectionCircleLine(double c1[], double line[], double p1[], double p2[]) {
	double p[2];
	p[0] = c1[0] - line[0] * line[2] / (line[0] * line[0] + line[1] * line[1]);
	p[1] = c1[1] - line[1] * line[2] / (line[0] * line[0] + line[1] * line[1]);
	double temp = line[0] * c1[0] + line[1] * c1[1] + line[2];
	double d = c1[2] * c1[2] - temp * temp / (line[0] * line[0] + line[1] * line[1]);
	double mult = sqrt(d / (line[0] * line[0] + line[1] * line[1]));	
	p1[0] = p[0] + mult * line[1];
	p1[1] = p[1] - mult * line[0];
	
	p2[0] = p[0] - mult * line[1];
	p2[1] = p[1] + mult * line[0];
}