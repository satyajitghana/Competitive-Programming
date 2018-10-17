#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    int n, c, step_c, log_c = -1;
    cin >> n >> c;
    int p = 1;
    int k = 1;
    while(p < n) {
        p *= 2;
        if (c <= p && log_c == -1) {
            log_c = k - 1;
            step_c = p / 2;
        }
        ++k;
    }
    vector<int> v(n);
    vector<ll> sum(n + 1);
    vector<vector<int>> tree(k, vector<int> (p));
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        sum[i + 1] = sum[i] + v[i];
        tree[0][i] = v[i];
    }
    if (n < c) {
        cout << sum[n] << endl;
        return 0;
    }
    if (c == 1) {
        cout << 0 << endl;
        return 0;
    }
    p = 1;
    for (int i = 1; i < k; ++i) {
        for (int j = 0; j + p < n; ++j) {
            tree[i][j] = min(tree[i - 1][j], tree[i - 1][j + p]);
        }
        p *= 2;
    }
    vector<ll> ans(n + 1);
    for (int i = 1; i <= n; ++i) {
        ans[i] = ans[i - 1] + v[i - 1];
        if (i >= c) {
            ans[i] = min(ans[i], ans[i - c] + sum[i] - sum[i - c] - min(tree[log_c][i - c], tree[log_c][i - step_c]));
        }
    }
    cout << ans[n] << endl;
    return 0;
}
