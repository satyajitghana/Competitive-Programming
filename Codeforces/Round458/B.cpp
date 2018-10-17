#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int &i : v) {
		cin >> i;
	}
	sort(v.rbegin(), v.rend());
	int j = 1;
	for (int i = 1; i < n; ++i) {
		if (v[i] == v[i - 1]) {
			++j;
		} else {
			if (j % 2 == 1) {
				cout << "Conan\n";
				return 0;
			}
			j = 1;
		}
	}
	if (j % 2 == 1) {
		cout << "Conan\n";
	} 	else {
		cout << "Agasa\n";
	}
	return 0;
}
