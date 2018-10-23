#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> l(n);
    vector<int> r(n);
    int k = n;
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> r[i];
    }
    while (k > 0) {
        int t = 0;
        for (int i = 0; i < n; ++i) {
            if (l[i] == 0 && r[i] == 0) {
                for (int j = 0; j < i; ++j) {
                    --r[j];
                }
                ++t;
                ans[i] = k;
                l[i] = -1;
                r[i] = -1;
            } else {
                l[i] -= t;
            }
        }
        if (t == 0) {
            cout << "NO\n";
            return 0;
        }
        k -= t;
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
