#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, k, p;
    cin >> n >> k >> p;
    vector<int> v(n);
    vector<int> pref(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    pref[0] = v[0] % p;
    for (int i = 1; i < n; ++i) {
        pref[i] = (pref[i - 1] + v[i]) % p;
    }
    vector<vector<int>> w(k, vector<int>(n, k * p));
    for (int i = 0; i < n; ++i) {
        w[0][i] = pref[i];
    }
    int q = 128;
    // if (n > 500000) {
    //     cout << pref[n - 1] << endl;
    //     return 0;
    // }
    for (int i = 1; i < k; ++i) {
        vector<int> z(q << 2, 100000000);
        for (int j = i; j < n; ++j) {
            int a = pref[j - 1] + (q << 1);
            int temp = w[i - 1][j - 1] + (p << 1) - pref[j - 1];
            while (a > 0) {
                if (z[a] > temp) {
                    z[a] = temp;
                } else {
                    break;
                }
                a >>= 1;
            }
            temp -= p;
            a = pref[j - 1] + 3 * q;
            while (a > 0) {
                if (z[a] > temp) {
                    z[a] = temp;
                } else {
                    break;
                }
                a >>= 1;
            }
            int best = z[pref[j] + 3 * q];
            a = pref[j] + 3 * q;
            while (a > 1) {
                if (a & 1) {
                    best = min(best, z[a - 1]);
                }
                a >>= 1;
            }
            w[i][j] = best - p + pref[j];
        }
    }
    cout << w[k - 1][n - 1] << endl;
    return 0;
}
