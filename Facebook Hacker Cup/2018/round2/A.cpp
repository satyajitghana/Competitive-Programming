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
        int n, k;
        cin >> n >> k;
        int ans = -k;
        for (int i = 1; i < n; ++i) {
            ans += (k - i);
            if (k - i == 0) {
                break;
            }
        }
        cout << "Case #" << test << ": " << max(0, ans) << endl;
        if (n == 2) {
            cout << 1 << endl;
            cout << "1 2 1" << endl;
            continue;
        }
        if (k == 2) {
            cout << 1 << endl;
            cout << "1 " << n << " 1" << endl;
            continue;
        }
        cout << min(n, k) << endl;
        cout << "1 " << n << " " << k << endl;
        for (int i = 1; i < n; ++i) {
            if (k - i == 0) {
                break;
            }
            if (k - i == 1) {
                cout << i << " " << n << " 1" << endl;
                break;
            }
            cout << i << " " << i + 1 << " " << k - i << endl;
        }
    }
    return 0;
}
