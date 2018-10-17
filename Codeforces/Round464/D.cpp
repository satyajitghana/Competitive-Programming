#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	string s, t;
	cin >> n >> s >> t;
	vector<pair<char, char>> v;
	for (int i = 0; i < n; ++i) {
		if (s[i] != t[i]) {
			v.push_back(make_pair(s[i], t[i]));
			for (int j = i + 1; j < n; ++j) {
				if (s[j] == s[i]) {
					s[j] = t[i];
				}
				if (t[j] == s[i]) {
					t[j] = t[i];
				}
			}
		}
	}
	cout << v.size() << endl;
	for (auto i : v) {
		cout << i.first << " " << i.second << endl;
	}
	return 0;
}
