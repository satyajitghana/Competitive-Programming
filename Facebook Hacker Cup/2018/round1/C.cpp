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
        int n, m;
        cin >> n >> m;
        int w, x, y, zz;
        vector<ll> h(n);
        cin >> h[0] >> h[1] >> w >> x >> y >> zz;
        for (int i = 2; i < n; ++i) {
            h[i] = (w * h[i - 2] + x * h[i - 1] + y) % zz;
        }
        ld z = zz;
        vector<ld> d(n - 1, 1000000);
        vector<ld> u(n - 1, 1000000);
        for (int i = 0; i < m; ++i) {
            int a, b;
            ld dd, uu;
            cin >> a >> b >> uu >> dd;
            if (b < a) {
                swap(a, b);
                swap(dd, uu);
            }
            for (int j = a - 1; j < b - 1; ++j) {
                d[j] = min(d[j], dd);
                u[j] = min(u[j], uu);
            }
        }
        ld ans1 = 0;
        ld ans2 = z;
        ld mid = (ans1 + ans2) / 2;
        while (ans2 - ans1 > 1e-7) {
            vector<ld> a(n);
            vector<ld> b(n);
            a[0] = max((ld) 0, h[0] - mid);
            b[0] = min(h[0] + mid, z);
            bool ok = true;
            for (int i = 0; i + 1 < n; ++i) {
                a[i + 1] = max((ld) 0, h[i + 1] - mid);
                b[i + 1] = min(h[i + 1] + mid, z);
                a[i + 1] = max(a[i + 1], a[i] - d[i]);
                b[i + 1] = min(b[i + 1], b[i] + u[i]);
                if (a[i + 1] > b[i + 1]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans2 = mid;
            } else {
                ans1 = mid;
            }
            mid = (ans1 + ans2) / 2;
        }
        cout << setprecision(10) << fixed;
        cout << "Case #" << test << ": " << mid << endl;
    }
    return 0;
}
