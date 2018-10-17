#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, l;
    cin >> n >> m >> l;
    vector<vector<int>> a(n);
    vector<vector<int>> b(m);
    vector<int> c(n);
    vector<int> d(m);
    while (l--) {
        int x, y;
        cin >> x >> y;
        a[--x].push_back(--y);
        b[y].push_back(x);
    }
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (c[i] == 0) {
            ++k;
            c[i] = k;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int j : a[u]) {
                    if (d[j] == 0) {
                        d[j] = k;
                        for (int z : b[j]) {
                            if (c[z] == 0) {
                                c[z] = k;
                                q.push(z);
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        if (d[i] == 0) {
            ++k;
        }
    }
    cout << k - 1 << endl;
    return 0;
}
