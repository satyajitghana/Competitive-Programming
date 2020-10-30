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
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        vector<vector<int>> sons(n);
        for (int i = 1; i < n; ++i) {
            int a;
            cin >> a;
            sons[a].push_back(i);
        }
        stack<pair<int, int>> s;
        s.emplace(0, 0);
        int p = 1;
        while (p < n) {
            p *= 2;
        }
        vector<int> v(2 * p);
        vector<int> temp(n);
        vector<pair<int, int>> w(n);
        int k = 0;
        while (!s.empty()) {
            int u = s.top().first;
            int start = s.top().second;
            s.pop();
            if (start == 0) {
                v[p + k] = u;
                temp[k] = u;
                w[u].first = k + p;
                ++k;
            }
            if (start < sons[u].size()) {
                s.emplace(u, start + 1);
                s.emplace(sons[u][start], 0);
            } else {
                w[u].second = k + p;
            }
        }
        for (int i = p - 1; i > 0; --i) {
            v[i] = max(v[2 * i], v[2 * i + 1]);
        }
        vector<int> z(n);
        for (int i = 0; i < m; ++i) {
            ll c = a;
            c *= i;
            c += b;
            c %= n;
            ++z[c];
        }
        ll sum = 0;
        for (int i = n - 1; i >= 0; --i) {
            int u = temp[i];
            while (z[u] > 0) {
                int l = w[u].first;
                int r = w[u].second;
                int b = l;
                while (l != r) {
                    if (l % 2 == 1) {
                        if (v[l] > v[b]) {
                            b = l;
                        }
                        ++l;
                    }
                    if (r % 2 == 1) {
                        if (v[--r] > v[b]) {
                            b = r;
                        }
                    }
                    l /= 2;
                    r /= 2;
                }
                while (b < p) {
                    if (v[b] == v[b * 2]) {
                        b *= 2;
                    } else {
                        b = b * 2 + 1;
                    }
                }
                sum += v[b];
                v[b] = 0;
                while (b > 1) {
                    b /= 2;
                    v[b] = max(v[2 * b], v[2 * b + 1]);
                }
                --z[u];
            }
        }
        cout << "Case #" << test << ": " << sum << endl;
    }
    return 0;
}
