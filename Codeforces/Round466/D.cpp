#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v) {
        cin >> i;
    }
    string s;
    cin >> s;
    int l = -1000000000;
    int r = 1000000000;
    for (int i = 0; i + 4 < n; ++i) {
        int mi = v[i];
        int ma = v[i];
        for (int j = 1; j < 5; ++j) {
            mi = min(mi, v[i + j]);
            ma = max(ma, v[i + j]);
        }
        if (s[i] == '0' && s[i + 1] == '0' && s[i + 2] == '0' && s[i + 3] == '0' && s[i + 4] == '1') {
            l = max(l, ma + 1);
        }
        if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '1' && s[i + 3] == '1' && s[i + 4] == '0') {
            r = min(r, mi - 1);
        }
    }
    cout << l <<   << max(l, r) << endl;
    return 0;
}
