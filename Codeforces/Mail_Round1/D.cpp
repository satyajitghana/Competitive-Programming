#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

using ll = long long;
using ld = long double;

ll calc(int k) {
    ll e = 0;
            ll t = k / 2 + k % 2;
            t *= (t - 1);
            t /= 2;
            e += t;
            t = k / 2;
            t *= (t - 1);
            t /= 2;
    return e + t;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    k = 1 << (k - 1);
    vector<int> v(n + 1);
    v[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        v[i] ^= v[i - 1];
        if (v[i] >= k) {
            v[i] = 2 * k - 1 - v[i];
        }
    }
    sort(v.begin(), v.end());
    int last = -1;
    k = 0;
    ll ans = n + 1;
    ans *= n;
    ans /= 2;
    for (int i = 0; i <= n; ++i) {
        if (v[i] == last) {
            ++k;
        } else {
            ans -= calc(k);
            k = 1;
            last = v[i];
        }
    }
    ans -= calc(k);
    cout << ans << endl;
    return 0;
}
