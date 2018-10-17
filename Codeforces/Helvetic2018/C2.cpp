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
    vector<vector<int>> w(k, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        w[0][i] = pref[i];
    }
    for (int i = 1; i < k; ++i) {
        vector<int> z(p, -1);
        for (int j = i; j < n; ++j) {
            z[pref[j - 1]] = max(z[pref[j - 1]], w[i - 1][j - 1]);
            for (int q = 0; q < p; ++q) {
                if (z[q] != -1) {
                    int x = pref[j] - q;
                    if (x < 0) {
                        x += p;
                    }
                    w[i][j] = max(w[i][j], z[q] + x);
                }
            }

        }
    }
    cout << w[k - 1][n - 1] << endl;
    return 0;
}
