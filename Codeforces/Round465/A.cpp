#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	int ans = 0;
	cin >> n;
	for (int i = 1; i < n; ++i) {
		if (n % i == 0) {
			++ans;
		}
	}
	cout << ans << endl;
	return 0;
}
