#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    ll c = 0;
    ll d = 0;
    ll e = 0;
    ll f = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == '0') {
            if (b[i] == '0') {
                ++c;
            } else {
                ++d;
            }
        } else {
            if (b[i] == '0') {
                ++e;
            } else {
                ++f;
            }
        }
    }
    cout << c * e + c * f + d * e << endl;
    return 0;
}
