#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	ll n;
	int k;
	cin >> n >> k;
	ll count;
	int j;
	ll best_sol = 0;
	for (int i = 0; i < k; ++i) {
		ll a;
		cin >> a;
		if (best_sol < (n / a) * a) {
			best_sol = (n / a) * a;
			count = n / a;
			j = i;
		}
	}
	if (best_sol != 0) {
		cout << j + 1 << " " << count << endl;
	} else {
		cout << "1 0" << endl;
	}
	return 0;
}
