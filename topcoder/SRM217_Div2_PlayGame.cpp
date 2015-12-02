#include <bits/stdc++.h>

using namespace std;

class PlayGame {
public:
	int saveCreatures(vector<int>, vector<int>);
};

int PlayGame::saveCreatures(vector<int> you, vector<int> com) {
	sort(you.begin(), you.end());
	sort(com.begin(), com.end());
	int k = com.size() - 1;
	int res = 0;
	for (int i = you.size() - 1; i >= 0; --i) {
		while (k >= 0 && you[i] <= com[k]) --k;
		if (k >= 0) res += you[i];
		--k;
	}
	return res;
}