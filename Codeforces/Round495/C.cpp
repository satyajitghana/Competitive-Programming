#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> a(n);
    set<int> s;
    cin >> v[0];
    a[0] = 1;
    s.insert(v[0]);
    for (int i = 1; i < n; ++i) {
        cin >> v[i];
        if (s.find(v[i]) == s.end()) {
            a[i] = a[i - 1] + 1;
            s.insert(v[i]);
        } else {
            a[i] = a[i - 1];
        }
    }
    s.clear();
    ll ans = 0;
    for (int i = n - 1; i > 0; --i) {
        if (s.find(v[i]) == s.end()) {
            s.insert(v[i]);
            ans += a[i - 1];
        }
    }
    cout << ans << endl;
    return 0;
}
