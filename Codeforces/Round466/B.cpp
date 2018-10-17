#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    ll n, k, a, b;
    cin >> n >> k >> a >> b;
    ll ans = 0;
    while (n != 1) {
        if (n < k) {
            ans += a * (n - 1);
            n = 1;
        } else if (n % k == 0) {
            if (b < (n - n / k) * a) {
                n /= k;
                ans += b;
            } else {
                ans += (n - 1) * a;
                n = 1;
            }
        } else {
            ans += a * (n % k);
            n -= (n % k);
        }
    }
    cout << ans << endl;
    return 0;
}
