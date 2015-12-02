#include <bits/stdc++.h>

using namespace std;

class SchoolAssembly {
public:
	int getBeans(int kids, int quantity);
};

int SchoolAssembly::getBeans(int kids, int quantity) {
	return (kids * quantity + 4 * (quantity - 1) + 19) / 20;
}