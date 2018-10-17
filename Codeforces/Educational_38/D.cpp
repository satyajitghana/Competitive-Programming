#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, ll>>> v(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		v[--a].push_back(make_pair(--b, c));
		v[b].push_back(make_pair(a, c));
	}
	vector<ll> a(n);
	set<pair<ll, int>> s;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		s.insert(make_pair(a[i], i));
	}
	while (!s.empty()) {
		int u = s.begin()->second;
		ll cost = s.begin()->first;
		s.erase(s.begin());
		for (auto p : v[u]) {
			if (cost + 2 * p.second < a[p.first]) {
				s.erase(s.find(make_pair(a[p.first], p.first)));
				a[p.first] = cost + 2 * p.second;
				s.insert(make_pair(a[p.first], p.first));
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
	return 0;
}
