#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

uint32_t w[5001][2501][3];

int main() {
    ios_base::sync_with_stdio(false);
    uint32_t MAX = 50000;
    MAX *= MAX;
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v) {
        cin >> i;
    }
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n / 2 + 2; ++j) {
            w[i][j][0] = MAX;
            w[i][j][1] = MAX;
            w[i][j][2] = MAX;
        }
    }
    w[0][0][0] = 0;
    w[0][0][1] = max(0, v[0] - v[1] + 1);
    w[0][1][2] = max(0, v[1] - v[0] + 1);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i / 2 + 2; ++j) {
            w[i][j][0] = min(w[i - 1][j][0], w[i - 1][j][2]);
            int t1 = 0;
            if (i + 1 != n && v[i] >= v[i + 1]) {
                t1 = v[i] - v[i + 1] + 1;
            }
            int t2 = max(0, v[i] - v[i - 1] + 1);
            int t3 = max(0, t1 - t2);
            int t4 = 0;
            if (i + 1 != n && v[i + 1] >= v[i]) {
                t4 = v[i + 1] - v[i] + 1;
            }
            w[i][j][1] = min(MAX, w[i - 1][j][0] + t1);
            w[i][j][1] = min(w[i][j][1], w[i - 1][j][2] + t3);
            if (j == 0) {
                continue;
            }
            w[i][j][2] = min(MAX, w[i - 1][j - 1][1] + t4);
        }
    }
    for (int i = 0; i * 2 < n; ++i) {
        cout << min(w[n - 1][i + 1][0], w[n - 1][i + 1][2]) << " ";
    }
    cout << endl;
    return 0;
}
