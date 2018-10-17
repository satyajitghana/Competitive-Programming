#include <bits/stdc++.h>

using namespace std;

bool good(char c) {
	string s = "aoeuiy";
	for (int i = 0; i < s.size(); ++i) {
		if (c == s[i]) {
			return true;
		}
	}
	return false;
}

int main() {
	string s;
	cin >> s >> s;
	string t;
	for (int i = s.size() - 1; i > 0; --i) {
		if (!(good(s[i]) && good(s[i - 1]))) {
			t = s[i] + t;
		}
	}
	t = s[0] + t;
	cout << t << endl;
	return 0;
}
