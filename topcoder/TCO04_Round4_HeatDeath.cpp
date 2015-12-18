#include <bits/stdc++.h>

using namespace std;

class HeatDeath {
public:
	int maxTime(vector<int> energy);
};

const int MAXN = 105;

int N;

int HeatDeath::maxTime(vector<int> energy) {
	N = energy.size();
	int res = 0;
	while (1) {
		sort(energy.rbegin(), energy.rend());
		if (energy[0] - energy[N - 1] <= 1) break;
		bool ok = true;
		for (int i = 0; i + 1 < N; ++i) {
			if (energy[i] - energy[i + 1] >= 2) {
				energy[i] -= 1;
				energy[i + 1] += 1;
				++res;
				ok = false;
			}
		}
		if (ok) {
			for (int i = 2; i < N; ++i) {
				if (energy[0] - energy[i] == 2) {
					energy[0] -= 1;
					energy[i] += 1;
					++res;
					break;
				}
			}
		}
	}
	return res;
}