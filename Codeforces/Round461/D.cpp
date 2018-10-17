#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

bool cmp(const pair<ll, ll> &a, const std::pair<ll, ll> &b) {
return a.first * b.second > a.second * b.first;
}

int main() {
ios_base::sync_with_stdio(false);
int n;
cin >> n;
vector<pair<ll, ll> > v(n);
ll ans = 0;
for (auto &i : v) {
ll s = 0;
string temp;
cin >> temp;
i.first = 0;
i.second = 0;
for (const auto &j : temp) {
if (j == 's') {
++i.first;
++s;
} else {
++i.second;
ans += s;
}
}
}
sort(v.begin(), v.end(), cmp);
ll s = 0;
for (const auto &i : v) {
ans += s * i.second;
s += i.first;
}
cout << ans << endl;
return 0;
}
