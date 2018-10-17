#include <iostream>
#include <vector>
#include <set>
#include <iomanip>

using namespace std;

typedef long double ld;

int main() {
int64_t n, m, r, k;
cin >> n >> m >> r >> k;
vector<int64_t> a;
vector<int64_t> b;
int64_t t = 0;
for (int64_t i = 0; i < n; ++i) {
int64_t t = min(n - r + 1, min(r, min(i + 1, n - i)));
if (a.size() < t) {
a.push_back(1);
} else {
++a[t - 1];
}
}
for (int64_t i = 0; i < m; ++i) {
int64_t t = min(m - r + 1, min(r, min(i + 1, m - i)));
if (b.size() < t) {
b.push_back(1);
} else {
++b[t - 1];
}
}
ld ans = 0;
int64_t nn = n;
int64_t mm = m;
n = a.size();
m = b.size();
set<pair<int64_t, pair<int64_t, int64_t>>> s;
for (int64_t i = 0; i < a.size(); ++i) {
s.insert(make_pair((i + 1) * b.size(), make_pair(i, b.size() - 1)));
}
while (k > 0) {
auto it = --s.end();
ans += min(k, a[it->second.first] * b[it->second.second]) * it->first;
k -= a[it->second.first] * b[it->second.second];
if (it->second.second > 0) {
s.insert(make_pair((it->second.first + 1) * (it->second.second), make_pair(it->second.first, it->second.second - 1)));
}
s.erase(it);
}
cout << fixed << setprecision(10) << ans / (nn - r + 1) / (mm - r + 1) << endl;
return 0;
}
