#include <bits/stdc++.h>

using namespace std;

class RockStar {
public:
	int getNumSongs(int ff, int fs, int sf, int ss) {
		int res = 0;
		if (ff + fs > 0) {
			res = ff;
			if (fs > sf) res += 2 * sf + 1;
			else res += 2 * fs;
			if (fs > 0) res += ss;
		} else {
			res = ss + min(sf, 1);
		}
		return res;
	}
};