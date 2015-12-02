#include <bits/stdc++.h>

using namespace std;

class GroceryBagger {
public:
	int minimumBags(int, vector<string>);
};

map<string, int> mapper;

int GroceryBagger::minimumBags(int sz, vector<string> item) {
	mapper.clear();
	for (int i = 0; i < item.size(); ++i) {
		mapper[item[i]] += 1;
	}
	int res = 0;
	for (map<string, int>::iterator it = mapper.begin(); it != mapper.end(); ++it) {
		res += (it->second + sz - 1) / sz;
	}
	return res;
}