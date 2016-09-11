#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<int, pii> ppi;

const double PI = acos(0) * 2;
const double EPS = 1e-8;
const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int oo = 1e9;

const int PERMS[6][3] = {
	{0, 1, 2},
	{0, 2, 1},
	{1, 0, 2},
	{1, 2, 0},
	{2, 0, 1},
	{2, 1, 0}
};

bool isAvailable(int, int[], int[]);
bool canWin(int[], int[]);

int main() {
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  int A, B, C, X, Y;
  while (scanf("%d%d%d%d%d", &A, &B, &C, &X, &Y), A || B || C || X || Y) {
  	int princess[3] = {A, B, C};
  	int prince[3] = {X, Y, 0};
  	int res = -1;
  	for (int i = 1; i <= 52; ++i) {
  		if (isAvailable(i, princess, prince)) {
  			prince[2] = i;
  			if (canWin(princess, prince)) {
  				res = i;
  				break;
  			}
  		}
  	}
  	printf("%d\n", res);
  }

#ifndef ONLINE_JUDGE
  printf("\nTime elapsed: %dms", int(1000 * clock() / CLOCKS_PER_SEC));
#endif
}

bool isAvailable(int card, int c1[], int c2[]) {
	for (int i = 0; i < 3; ++i) {
		if (card == c1[i]) return false;
		if (card == c2[i]) return false;
	}
	return true;
} 

bool canWin(int princess[], int prince[]) {
	int win = 0;
	for (int p = 0; p < 6; ++p) {
		int cnt = 0;
		for (int i = 0; i < 3; ++i) {
			cnt += princess[i] < prince[PERMS[p][i]];
		}
		win += cnt >= 2;
	}
	return win == 6;
}