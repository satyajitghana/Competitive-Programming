#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> prize(n + 2);
	prize[0] = 1;
	prize[n + 1] = 1000000;
	for (int i = 1; i <= n; ++i) {
		cin >> prize[i];
	}
	int ans = 1000000;
	for (int i = 1; i < n + 2; ++i) {
		ans = min(ans, max(1000000 - prize[i], prize[i - 1] - 1));
	}
	cout << ans << endl;
	return 0;
}
