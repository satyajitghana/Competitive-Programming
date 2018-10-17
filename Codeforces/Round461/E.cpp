#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

int main() {
ios_base::sync_with_stdio(false);
ll n, w, b, x;
cin >> n >> w >> b >> x;
vector<ll> v(10001, -1);
vector<ll> c(n);
for (int i = 0; i < n; ++i) {
cin >> c[i];
}
vector<ll> cost(n);
for (int i = 0; i < n; ++i) {
cin >> cost[i];
}
v[0] = w;
for (ll i = 0; i < n; ++i) {
vector<ll> new_v(10001, -1);
set<pair<ll, ll>> s;
for (ll j = 0; j < 10001; ++j) {
while (s.size() != 0 && s.begin()->second + c[i] < j) {
s.erase(s.begin());
}
if (s.size() != 0) {
new_v[j] = max(v[j], v[s.begin()->second] - cost[i] * (j - s.begin()->second));
} else {
new_v[j] = v[j];
}
if (v[j] != -1) {
s.insert(make_pair((10001 - j) * cost[i] - v[j], j));
}
}
v = move(new_v);
for (ll j = 0; j < 10001; ++j) {
if (v[j] == -1) {
break;
}
v[j] = min(w + b * j, v[j] + x);
// cout << v[j] <<  ;
}
// cout << endl;
}
for (ll i = 10000; i >= 0; --i) {
if (v[i] != -1) {
cout << i << endl;
return 0;
}
}
return 0;
}
