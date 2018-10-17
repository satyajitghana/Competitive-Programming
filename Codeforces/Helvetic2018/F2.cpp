#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        --v[i];
    }
    vector<int> k(m);
    int l = 0;
    int u = 0;
    for (int i = 0; i < m; ++i) {
        cin >> k[i];
        if (k[i] != 0) {
            ++l;
        }
    }
    int best = 10000000;
    int j = 0;
    for (int i = 0; i < n; ++i) {
        --k[v[i]];
        if (k[v[i]] == 0) {
            --l;
        } else if (k[v[i]] < 0) {
            ++u;
        }
        while (l == 0) {
            best = min(best, u);
            ++k[v[j]];
            if (k[v[j]] == 1) {
                ++l;
            } else {
                --u;
            }
            ++j;
        }
    }
    if (best == 10000000) {
        best = -1;
    } 
    cout << best << endl;
    return 0;
}
