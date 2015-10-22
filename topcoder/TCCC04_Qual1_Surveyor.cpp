#include <bits/stdc++.h>

using namespace std;

const int MAXN = 55;

class Surveyor {
private:
	int a[MAXN][2], p[2], cnt;
	
	int cross(int p1[], int p2[], int p3[]) {
		int v1[2], v2[2];
		v1[0] = p2[0] - p1[0];
		v1[1] = p2[1] - p1[1];
		
		v2[0] = p3[0] - p1[0];
		v2[1] = p3[1] - p1[1];
		
		return v1[0] * v2[1] - v2[0] * v1[1];
	}
	
public:
	int area(string dir, vector<int> len) {
		p[0] = p[1] = 0;
		a[0][0] = p[0];
		a[0][1] = p[1];
		cnt = 1;
		for (int i = 0; i < dir.size(); ++i) {
			if (dir[i] == 'S') {
				p[1] -= len[i];
			} else if (dir[i] == 'N') {
				p[1] += len[i];
			} else if (dir[i] == 'W') {
				p[0] -= len[i];
			} else {
				p[0] += len[i];
			}
			a[cnt][0] = p[0];
			a[cnt][1] = p[1];
			++cnt;
		}
		int res = 0;
		for (int i = 1; i < cnt - 1; ++i) {
			res += cross(a[0], a[i], a[i + 1]);
		}
		return abs(res / 2);
	}
};