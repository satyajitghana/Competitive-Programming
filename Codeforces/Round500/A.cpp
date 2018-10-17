#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    n *= 2;
    vector<ll> v(n);
    for (ll &a : v) {
        cin >> a;
    }
    sort(v.begin(), v.end());
    ll ans = (v[n / 2 - 1] - v[0]) * (v[n - 1] - v[n / 2]);
    for (int i = 0; i < n / 2; ++i) {
        ans = min(ans, (v[n - 1] - v[0]) * (v[n / 2 + i - 1] - v[i]));
    }
    cout << ans << endl;
    return 0;
}
