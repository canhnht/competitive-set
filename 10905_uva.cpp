//This is getting accepted!
#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
typedef pair<int, int> pii;
typedef pair<int, pii> ppi;

const double PI = acos(0) * 2;
const ll MOD = 1000000007;
const int MAXN = 1e2 + 5;
const int oo = 1e9;

int N;
string a[MAXN];

bool cmp(string s1, string s2) {
	string s12, s21;
	s12 = s1 + s2;
	s21 = s2 + s1;
	return s12.compare(s21) > 0;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (scanf("%d", &N), N) {
    	for (int i = 0; i < N; ++i) cin >> a[i];
    	sort(a, a + N, cmp);
    	for (int i = 0; i < N; ++i) printf("%s", a[i].c_str());
    	printf("\n");
    }
    return 0;
}