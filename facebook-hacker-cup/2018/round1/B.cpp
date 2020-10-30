#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        int n;
        vector<string> v(3);
        cin >> n >> v[0] >> v[1] >> v[2];
        int k = 0;
        if (v[0][0] == '#' || v[1][0] == '#' || n % 2 != 0 ||
            v[1][n - 1] == '#' || v[2][n - 1] == '#') {
            k = -1;
        }
        for (int i = 1; i + 1 < n; i += 2) {
            if (k == -1) {
                break;
            }
            if (v[1][i] == '#' || v[1][i + 1] == '#') {
                k = -1;
                break;
            }
            int u = 0;
            if (v[0][i] == '#' || v[0][i + 1] == '#') {
                ++u;
            }
            if (v[2][i] == '#' || v[2][i + 1] == '#') {
                ++u;
            }
            if (u == 0) {
                ++k;
            }
            if (u == 2) {
                k = -1;
            }
        }
        cout << "Case #" << test << ": ";
        if (k == -1) {
            cout << 0;
        } else {
            int ans = 1;
            int mod = 1000 * 1000 * 1000 + 7;
            while (k > 0) {
                ans *= 2;
                ans %= mod;
                --k;
            }
            cout << ans;
        }
        cout << endl;
    }
    return 0;
}
