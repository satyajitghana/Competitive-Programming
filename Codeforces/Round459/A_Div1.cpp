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
string s;
cin >> s;
int ans = 0;
for (int i = 0; i < s.size(); ++i) {
int min_b = 0;
int max_b = 0;
for (int j = i; j < s.size(); ++j) {
if (s[j] == ')') {
--min_b;
--max_b;
} else if (s[j] == '(') {
++min_b;
++max_b;
} else {
--min_b;
++max_b;
}
if (max_b < 0) {
break;
}
if (min_b < 0) {
min_b += 2;
}
if (min_b == 0) {
++ans;
}
}
}
cout << ans << endl;
return 0;
}
