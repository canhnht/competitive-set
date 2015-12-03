#include <bits/stdc++.h>

using namespace std;

class Apothecary {
public:
	vector<int> balance(int W);
};

vector<int> Apothecary::balance(int W) {
	vector<int> res(0);
	int temp = W;
	while (temp) {
		res.push_back(temp % 3);
		temp /= 3;
	}
	for (int i = 0; i < res.size(); ++i) {
		if (res[i] == 2) {
			res[i] = -1;
			if (i == res.size() - 1) res.push_back(1);
			else res[i + 1] += 1;
		} else if (res[i] == 3) {
			res[i] = 0;
			if (i == res.size() - 1) res.push_back(1);
			else res[i + 1] += 1;
		}
	}
	temp = 1;
	for (int i = 0; i < res.size(); ++i) {
		res[i] = temp * res[i];
		temp *= 3;
	}
	for (int i = res.size() - 1; i >= 0; --i) {
		if (res[i] == 0) res.erase(res.begin() + i);
	}
	sort(res.begin(), res.end());
	return res;
}