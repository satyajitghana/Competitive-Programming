#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int &i : v) {
		cin >> i;
		--i;
	}
	for (int i = 0; i < n; ++i) {
		if (v[v[v[i]]] == i) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}
