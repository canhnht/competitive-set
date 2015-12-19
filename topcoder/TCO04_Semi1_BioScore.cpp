#include <bits/stdc++.h>

using namespace std;

class BioScore {
public:
	double maxAvg(vector<string> seqs);
};

typedef pair<int, pair<int, int> > pip;

double cnt[4][4];
int idx[300];
double score[4][4];

double BioScore::maxAvg(vector<string> seqs) {
	idx['A'] = 0;
	idx['C'] = 1;
	idx['T'] = 2;
	idx['G'] = 3;
	memset(cnt, 0, sizeof cnt);
	for (int i = 0; i < seqs.size(); ++i) {
		for (int k = i + 1; k < seqs.size(); ++k) {
			for (int p = 0; p < seqs[i].size(); ++p) {
				cnt[idx[(int)seqs[i][p]]][idx[(int)seqs[k][p]]] += 1;
			}
		}
	}
	vector<double> c(0);
	for (int i = 0; i < 4; ++i) {
		for (int k = i + 1; k < 4; ++k) {
			cnt[i][k] += cnt[k][i];
			c.push_back(cnt[i][k]);
		}
	}
	sort(c.rbegin(), c.rend());
//	for (int i = 0; i < c.size(); ++i) cout << c[i] << endl;
//	cout << "----------" << endl;
	double res = -1e9;
	for (int s1 = 1; s1 <= 10; ++s1) {
		for (int s2 = 1; s2 <= 10; ++s2) {
			for (int s3 = 1; s3 <= 10; ++s3) {
				for (int s4 = 1; s4 <= 10; ++s4) {
					if ((s1 + s2 + s3 + s4) & 1) continue;
//					cout << (s1 + s2 + s3 + s4) << endl;
					double temp = 0;
					temp = cnt[0][0] * s1 + cnt[1][1] * s2 + cnt[2][2] * s3 + cnt[3][3] * s4;
//					cout << "temp " << temp << endl;
					temp += (c[0] + c[1]) * 10;
					temp -= (c[3] + c[4] + c[5]) * 10;
					temp += c[2] * (10 -(s1 + s2 + s3 + s4) / 2);
//					cout << "calc temp " << temp << endl;
					res = max(res, temp);
				}
			}
		}
	}
	int n = seqs.size();
	return res / (n * (n - 1) / 2);
}