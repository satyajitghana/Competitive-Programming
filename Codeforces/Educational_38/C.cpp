#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
		ll x;
		cin >> x;
		if (x == 0) {
			cout << "1 1\n";
			continue;
		}
		bool ok = false;
		for (ll n = max(static_cast<int> (sqrt(x)), 2); n * n <= 10 * x; ++n) {
			for (ll m = 2; m <= n; ++m) {
				ll k = n / m;
				if (n * n - k * k == x) {
					cout << n << " " << m << endl;
					ok = true;
					break;
				} else if (n * n - k * k > x) {
					break;
				}
			}
			if (ok) {
				break;
			}
		}
		if (!ok) {
			cout << -1 << endl;
		}
	}
	return 0;
}
