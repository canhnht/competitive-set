#include <bits/stdc++.h>

using namespace std;

class TheNumberGameDiv2 {
public:
	int minimumMoves(int A, int B);
};

string sa, sb;

int TheNumberGameDiv2::minimumMoves(int A, int B) {
	sa = "";
	while (A) {
		sa += char('0' + A % 10);
		A /= 10;
	}
	for (int i = 0; i < sa.length() / 2; ++i) swap(sa[i], sa[sa.length() - 1 - i]);
	sb = "";
	while (B) {
		sb += char('0' + B % 10);
		B /= 10;
	}
	string rb = sb;
	for (int i = 0; i < sb.length() / 2; ++i) swap(sb[i], sb[sb.length() - 1 - i]);
	bool isPalind = true;
	for (int i = 0; i < sb.length() / 2; ++i) isPalind &= sb[i] == sb[sb.length() - 1 - i];
	int res = 1e9;
	for (int i = 0; i + sb.length() <= sa.length(); ++i) {
		if (sa.substr(i, sb.length()).compare(sb) == 0) {
			int temp = sa.length() - i - sb.length() + i;
			if (i > 0) temp += 2 - isPalind;
			res = min(res, temp);
		} else if (sa.substr(i, sb.length()).compare(rb) == 0) {
			int temp = sa.length() - i - sb.length() + i + 1;
			res = min(res, temp);
		}
	}
	if (res == int(1e9)) res = -1;
	return res;
}