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
const int MAXN = 1e5 + 5;
const int oo = 1e9;

int N;
char line[MAXN];
bool a1[100][100], a2[100][100];

int build(int, int, int, int, int, bool [][100]);

int main(){
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &N);
    while (N--) {
    	scanf("%s", line);
    	build(0, 0, 32, 32, 0, a1);
    	// for (int i = 0; i < 32; ++i) {
    	// 	for (int k = 0; k < 32; ++k) cout << a1[i][k];
    	// 	cout << endl;
    	// }
    	// cout << "==========" << endl;
    	scanf("%s", line);
    	build(0, 0, 32, 32, 0, a2);
    	// for (int i = 0; i < 32; ++i) {
    	// 	for (int k = 0; k < 32; ++k) cout << a2[i][k];
    	// 	cout << endl;
    	// }
    	// cout << "==========" << endl;
    	int res = 0;
    	for (int i = 0; i < 32; ++i) {
    		for (int k = 0; k < 32; ++k) {
    			res += a1[i][k] | a2[i][k];
    		}
    	}
    	printf("There are %d black pixels.\n", res);
    }
    return 0;
}

int build(int x1, int y1, int x2, int y2, int start, bool a[][100]) {
	int end = start;	
	int mx = (x1 + x2) / 2;
	int my = (y1 + y2) / 2;
	if (line[start] == 'p') {
		end = build(x1, my, mx, y2, end + 1, a);		
		end = build(x1, y1, mx, my, end + 1, a);
		end = build(mx, y1, x2, my, end + 1, a);
		end = build(mx, my, x2, y2, end + 1, a);
	} else if (line[start] == 'e') {
		for (int i = x1; i < x2; ++i) {
			for (int k = y1; k < y2; ++k) {
				a[i][k] = false;
			}
		}		
	} else if (line[start] == 'f') {
		for (int i = x1; i < x2; ++i) {
			for (int k = y1; k < y2; ++k) {
				a[i][k] = true;
			}
		}
	}
	// cout << start << " " << end << endl;
	return end;
}