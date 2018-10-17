#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

int main() {
int n, m, k;
cin >> n >> m >> k;
vector<string> s(n);
for (auto &a : s) {
cin >> a;
}
int ans = 0;
vector<int> a(m);
for (int i = 0; i < n; ++i) {
if (s[i][0] == '.') {
a[0] = 1;
} else {
a[0] = 0;
}
if (a[0] >= k) {
++ans;
}
for (int j = 1; j < m; ++j) {
if (s[i][j] == '.') {
a[j] = a[j - 1] + 1;
} else {
a[j] = 0;
}
if (a[j] >= k) {
++ans;
}
}
}
a = vector<int>(n);
if (k != 1) {
for (int i = 0; i < m; ++i) {
if (s[0][i] == '.') {
a[0] = 1;
} else {
a[0] = 0;
}
if (a[0] >= k) {
++ans;
}
for (int j = 1; j < n; ++j) {
if (s[j][i] == '.') {
a[j] = a[j - 1] + 1;
} else {
a[j] = 0;
}
if (a[j] >= k) {
++ans;
}
}
}
}
cout << ans << endl;
}
