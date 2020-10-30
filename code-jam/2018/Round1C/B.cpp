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
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            int k;
            cin >> k;
            int best_a = 0;
            int best_c = n + 1;
            for (int j = 0; j < k; ++j) {
                int a;
                cin >> a;
                if (v[a] != -1) {
                    ++v[a];
                    if (v[a] < best_c) {
                        best_c = v[a];
                        best_a = a;
                    }
                }
            }
            v[best_a] = -1;
            if (best_c != n + 1) {
                cout << best_a << endl;
            } else {
                cout << -1 << endl;
            }
            cout.flush();
        }
    }
    return 0;
}
