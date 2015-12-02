#include <bits/stdc++.h>

using namespace std;

class FanFailure {
public:
	vector<int> getRange(vector<int>, int);
};

vector<int> FanFailure::getRange(vector<int> cap, int minCooling) {
	sort(cap.begin(), cap.end());
	int N = cap.size();
	vector<int> res(2);
	int i, sum;
	sum = 0;
	for (i = N - 1; i >= 0 && sum < minCooling; --i) {
		sum += cap[i];
	}
	res[0] = i + 1;
	sum = 0;
	for (i = 0; i < N && sum < minCooling; ++i) {
		sum += cap[i];
	}
	res[1] = N - i;
	return res;
}