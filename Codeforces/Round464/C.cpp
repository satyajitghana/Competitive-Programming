#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> v(2 * n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	for (int i = 0; i < n; ++i) {
		v[i + n] = v[i];
	}
	int s, f;
	cin >> s >> f;
	vector<int> w(2 * n);
	for (int i = 1; i < 2 * n; ++i) {
		w[i] = w[i - 1] + v[i - 1];
	}
	int best_count = 0;
	int j = 0;
	for (int i = 0; i < n; ++i) {
		if (best_count < w[f - s + i] - w[i]) {
			best_count = w[f - s + i] - w[i];
			j = i;
			j = s - j;
			while (j < 0) {
				j += n;
			}
			j %= n;
			if (j == 0) {
				j = n;
			}
		} else if (best_count == w[f - s + i] - w[i]) {
			int k = i;
			k = s - k;
			while (k < 0) {
				k += n;
			}
			k %= n;
			if (k == 0) {
				k = n;
			}
			if (k < j) {
				j = k;
			}
		}
	}
	cout << j << endl;
	return 0;
}
