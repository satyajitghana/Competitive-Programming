#include <bits/stdc++.h>

using namespace std;

void go(string str) {
	str[0] = 'a';
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string str;
		cin >> str;
		go(str);
	} 
}
