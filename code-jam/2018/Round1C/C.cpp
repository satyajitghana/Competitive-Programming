#include <bits/stdc++.h>

using namespace std;

struct node{
    vector<node*> sons;
    int count;

    node() : sons(26) {}
};

int main() {
    ios_base::sync_with_stdio(false);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        int n;
        cin >> n;
        vector<vector<uint64_t>> v(n + 1, vector<uint64_t>(n + 1, INT64_MAX));
        v[0][0] = 0;
        for (int i = 0; i < n; ++i) {
            uint64_t w;
            cin >> w;
            for (int j = 0; j <= i; ++j) {
                if (v[i][j] != INT64_MAX) {
                    v[i + 1][j] = min(v[i + 1][j], v[i][j]);
                    if (v[i][j] <= w * 6) {
                        v[i + 1][j + 1] = min(v[i + 1][j + 1], v[i][j] + w);
                    }
                }
            }
        }
        int k = 0;
        for (int i = 0; i <= n; ++i) {
            if (v[n][i] != INT64_MAX) {
                k = i;
            }
        }
        cout << "Case #" << test << ": " << k << endl;
    }
    return 0;
}
