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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        i = a + b + c + d;
    }
    int a = v[0];
    sort(v.rbegin(), v.rend());
    int ans = 0;
    while (ans < n && a < v[ans]) {
        ++ans;
    }
    cout << ans + 1 << endl;
    return 0;
}
