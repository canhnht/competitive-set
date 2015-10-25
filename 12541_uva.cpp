//This is getting accepted!
#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, pii> ppi;

const double PI = acos(0) * 2;
const ll MOD = 1000000007;
const int MAXN = 1e2 + 5;
const int oo = 1e9;

int n;
pair<pair<ll, pll>, string> persons[MAXN];

int main(){
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    char name[20];
    ll d, m, y;
    for (int i = 0; i < n; ++i) {
    	scanf("%s%lld%lld%lld", name, &d, &m, &y);
    	persons[i] = make_pair(make_pair(y, make_pair(m, d)), string(name));
    }
    sort(persons, persons + n);
    printf("%s\n%s\n", persons[n - 1].second.c_str(), persons[0].second.c_str());
    return 0;
}