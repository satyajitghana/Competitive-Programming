#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    vector<bool> v(601);
    int n;
    cin >> n;
    int k = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (v[a][j] = max(v[a][j], v[i][j] + 1); && a != 0) {
            ++k;
            v[a] = true;
        }
    }
    cout << k << endl;
    return 0;
}
