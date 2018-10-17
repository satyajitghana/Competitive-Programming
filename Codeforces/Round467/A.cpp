#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    ll k, d, t;
    cin >> k >> d >> t;
    ll temp = k / d;
    ll new_k = k;
    if (k % d != 0) {
        new_k = d * (temp + 1);
    }
    d = new_k - k;
    t *= 2;
    temp = t / (2 * k + d);
    t -= temp * (2 * k + d);
    ld ans = temp * (k + d);
    if (2 * k >= t) {
        ans += t / 2.0;
    } else {
        ans += k;
        t -= 2 * k;
        ans += t;
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}
