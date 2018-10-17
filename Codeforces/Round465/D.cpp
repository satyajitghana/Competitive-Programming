#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

ld eps = 1e-7;
ll MOD = 1000000007;

int main() {
	ios_base::sync_with_stdio(false);
	ll n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int &i : v) {
		cin >> i;
	}
	vector<int> w(n);
	ll res = 0;
	ll q = 1;
	ll p = 1;
	for (int &i : w) {
		cin >> i;
	}
	for (int i = 0; i < n; ++i) {
		ll pp = 1;
		ll qq = q;
		if (v[i] == 0 && w[i] == 0) {
			pp = m * (m - 1) / 2;
			pp %= MOD;
			qq *= m;
			qq %= MOD;
			qq *= m;
			qq %= MOD;
		} else if (v[i] == 0) {
			pp = (m - w[i]);
			qq *= m;
			qq %= MOD;
		} else if (w[i] == 0) {
			pp = v[i] - 1;
			qq *= m;
			qq %= MOD;
		} else {
			if (v[i] != w[i]) {
				if (v[i] > w[i]) {
					pp = p;
					ll ppp = pp;
					ll qqq = qq;
					while (ppp > 0 && qqq > 0) {
						if (ppp > qqq) {
							ppp %= qqq;
						} else {
							qqq %= ppp;
						}
					}
					pp /= (ppp + qqq);
					qq /= (ppp + qqq);
					ll x1 = 1;
					ll y1 = 0;
					ll x2 = 0;
					ll y2 = 1;
					ll r = qq;
					ll s = MOD;
					while (r > 0 && s > 0) {
						if (r > s) {
							x1 -= x2 * (r / s);
							x1 %= MOD;
							y1 -= y2 * (r / s);
							y1 %= MOD;
							r %= s;
						} else {
							x2 -= x1 * (s / r);
							x2 %= MOD;
							y2 -= y1 * (s / r);
							y2 %= MOD;
							s %= r;
						}
					}
					if (r != 0) {
						res += x1 * pp;
					} else {
						res += x2 * pp;
					}
					res %= MOD;
					if (res < 0) {
						res += MOD;
					}
				}
				break;
			}
			p *= m;
			p %= MOD;
		}
		if (v[i] == 0 || w[i] == 0) {
			ll ppp = pp;
			ll qqq = qq;
			while (ppp > 0 && qqq > 0) {
				if (ppp > qqq) {
					ppp %= qqq;
				} else {
					qqq %= ppp;
				}
			}
			pp /= (ppp + qqq);
			qq /= (ppp + qqq);
			ll x1 = 1;
			ll y1 = 0;
			ll x2 = 0;
			ll y2 = 1;
			ll r = qq;
			ll s = MOD;
			while (r > 0 && s > 0) {
				if (r > s) {
					x1 -= x2 * (r / s);
					x1 %= MOD;
					y1 -= y2 * (r / s);
					y1 %= MOD;
					r %= s;
				} else {
					x2 -= x1 * (s / r);
					x2 %= MOD;
					y2 -= y1 * (s / r);
					y2 %= MOD;
					s %= r;
				}
			}
			if (r != 0) {
				res += x1 * pp;
			} else {
				res += x2 * pp;
			}
			res %= MOD;
			if (res < 0) {
				res += MOD;
			}
		}
		q *= m;
		q %= MOD;
	}
	cout << res << endl;
	return 0;
}
