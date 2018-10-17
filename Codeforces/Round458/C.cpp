#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;

const int MOD = 1000000007;

int bit_count(int i) {
	int ans = 0;
	while (i > 0) {
		if (i % 2 != 0) {
			++ans;
		}
		i /= 2;
	}
	return ans;
}

int main() {
	int m = 1010;
	string s;
	int k;
	cin >> s >> k;
	if (k == 0) {
		cout << "1\n";
		return 0;
	}
	vector<int> v(m);
	v[1] = 0;
	for (int i = 2; i < m; ++i) {
		v[i] = v[bit_count(i)] + 1;
	}
	vector<int> w(m);
	vector<int> z(m);
	z[0] = 1;
	for (char c : s) {
		vector<int> temp = vector<int> (m);
		for (int i = 0; i < m - 1; ++i) {
			temp[i] += w[i];
			temp[i] %= MOD;
			temp[i + 1] += w[i];
			temp[i + 1] %= MOD;
			if (c == '1') {
				temp[i] += z[i];
				temp[i] %= MOD;
			}
		}
		w = move(temp);
		if (c == '1') {
			for (int i = m - 1; i > 0; --i) {
				z[i] = z[i - 1];
				z[i - 1] = 0;
			}
		}
	}
	if (k == 1) {
		cout << w[1] + z[1] - 1 << endl;
		return 0;
	}
	int ans = 0;
	for (int i = 1; i < m; ++i) {
		if (v[i] + 1 == k) {
			ans += w[i];
			ans %= MOD;
			ans += z[i];
			ans %= MOD;
		}
	}
	cout << ans << endl;
	return 0;
}
