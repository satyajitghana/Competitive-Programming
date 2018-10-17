#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int a = 1;
    int b = n;
    for (int i = 1; i <= n; ++i) {
        int j = n / i;
        if (i * j < n) {
            ++j;
        }
        if (i + j < a + b) {
            a = i;
            b = j;
        }
    }
    int m = n;
    int u = n - a + 1;
    while (m > 0) {
        cout << u << " ";
        ++u;
        if (u > m) {
            m -= a;
            u = m - a + 1;
        }
        if (u < 1) {
            u = 1;
        }
    }
    cout << endl;
    return 0;
}
