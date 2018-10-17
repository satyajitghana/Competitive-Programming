#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MOD = 1000000007;

ll gcd(ll a, ll b) {
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
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> in(n);
	vector<int> out(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		char c;
		cin >> a >> b >> c;
		in[--a].push_back(make_pair(--b, c - 'a'));
		++out[b];
	}
	queue<int> q;
	vector<int> s;
	for (int i = 0; i < n; ++i) {
		if (out[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int a = q.front();
		q.pop();
		s.push_back(a);
		for (auto p : in[a]) {
			--out[p.first];
			if (out[p.first] == 0) {
				q.push(p.first);
			}
		}
	}
	vector<vector<vector<bool>>> v(n, vector<vector<bool>>(n, vector<bool>(26, false)));
	for (int l = 1; l < n; ++l) {
		for (int i = 0; i < l; ++i) {
			int a = s[n - l - 1];
			int b = s[n - i - 1];
			for (int k = 0; k < 26; ++k) {
				bool win = false;
				for (auto p : in[a]) {
					if (k <= p.second) {
						win |= !v[b][p.first][p.second];
					}
				}
				v[a][b][k] = win;
			}
		}
		for (int i = 0; i <= l; ++i) {
			int a = s[n - i - 1];
			int b = s[n - l - 1];
			for (int k = 0; k < 26; ++k) {
				bool win = false;
				for (auto p : in[a]) {
					if (k <= p.second) {
						win |= !v[b][p.first][p.second];
					}
				}
				v[a][b][k] = win;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (v[i][j][0]) {
				cout << 'A';
			} else {
				cout << 'B';
			}
		}
		cout << endl;
	}
	return 0;
}
