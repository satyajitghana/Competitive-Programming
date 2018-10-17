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
    ll n, q;
    cin >> n >> q;
    while (q--) {
        ll a;
        cin >> a;
        while ((a & 1) == 0) {
            a += n - (a >> 1);
        }
        cout << a / 2 + 1 << endl;
    }
    return 0;
}
