#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tests;
    cin >> tests;
    for (int t = 1; t <= tests; ++t) {
        int n;
        cin >> n;
        int a;
        for (int i = 0; i <= n; ++i) {
            cin >> a;
        }
        cout << "Case #" << t << ": " << n % 2 << endl;
        if (n % 2) {
            cout << "0.0" << endl;
        }
    }
    return 0;
}
