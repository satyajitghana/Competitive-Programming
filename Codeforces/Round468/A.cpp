#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> d(n);
    d[0] = 1;
    for (int i = 1; i < v.size(); ++i) {
        cin >> v[i];
        --v[i];
        v[i] = v[v[i]] + 1;
        d[v[i]]++;
    }
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (d[i] % 2 != 0) {
            ++k;
        }
    }
    cout << k << endl;
    return 0;
}
