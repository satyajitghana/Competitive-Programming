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
    for (int i = 0; i < m; ++i) {
        cin >> k[i];
        if (k[i] != 0) {
            ++l;
        }
    }
    int j = 0;
    for (int i = 0; i < n; ++i) {
        --k[v[i]];
        if (k[v[i]] == 0) {
            --l;
        } 
        while (k[v[i]] < 0) {
            ++k[v[j]];
            if (k[v[j]] == 1) {
                ++l;
            }
            ++j;
        } 
        if (l == 0) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}
