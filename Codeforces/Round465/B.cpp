#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	bool top = true;
	int x = 0;
	int y = 0;
	int ans = 0;
	if (s[0] == 'U') {
		++y;
	} else {
		++x;
		top = false;
	}
	for (int i = 1; i < n; ++i) {
		if (s[i] == 'U') {
			++y;
		} else {
			++x;
		}
		if (y > x && !top) {
			top = true;
			++ans;
		} else if (x > y && top) {
			top = false;
			++ans;
		}
	}
	cout << ans << endl;
	return 0;
}
