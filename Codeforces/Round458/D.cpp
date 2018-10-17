#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	while (a && b) {
		if (a > b) {
			a %= b;
		} else {
			b %= a;
		}
	}
	return a + b;
}

int main() {
    ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int p = 1;
	while (p < n) {
		p *= 2;
	}
	vector<int> v(2 * p);
	for (int i = 0; i < n; ++i) {
		cin >> v[i + p];
	}
	for (int i = n; i < p; ++i) {
		v[i + p] = 1;
	}
	for (int i = p - 1; i > 0; --i) {
		v[i] = gcd(v[i * 2], v[i * 2 + 1]);
	}
	int m;
	cin >> m;
	while (m-- > 0) {
		int a;
		cin >> a;
		if (a == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			l = l + p - 1;
			r = r + p;
			int k = 0;
			while (l != r) {
				if (l % 2 == 1) {
					int u = l;
					while (v[u] % x != 0) {
						if (u >= p) {
							++k;
							break;
						} else {
							if (v[u * 2] % x != 0 && v[u * 2 + 1] % x != 0) {
								k += 2;
								break;
							} else if (v[u * 2] % x != 0) {
								u *= 2;
							} else {
								u = u * 2 + 1;
							}
						}
					}
					if (k > 1) {
						break;
					}
					++l;
				}
				if (r % 2 == 1) {
					int u = r - 1;
					while (v[u] % x != 0) {
						if (u >= p) {
							++k;
							break;
						} else {
							if (v[u * 2] % x != 0 && v[u * 2 + 1] % x != 0) {
								k += 2;
								break;
							} else if (v[u * 2] % x != 0) {
								u *= 2;
							} else {
								u = u * 2 + 1;
							}
						}
					}
					if (k > 1) {
						break;
					}
					--r;
				}
				l /= 2;
				r /= 2;
			}
			if (k > 1) {
				cout << "NO\n";
			} else {
				cout << "YES\n";
			}
		} else {
			int u, x;
			cin >> u >> x;
			u = u + p - 1;
			v[u] = x;
			u /= 2;
			while (u >= 1) {
				v[u] = gcd(v[u * 2], v[u * 2 + 1]);
				u /= 2;
			}
		}
	}
	return 0;
}
