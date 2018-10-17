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
    ll a, b;
    cin >> a >> b;
    while (true) {
        if (a == 0 || b == 0) {
            break;  
        }
        if (a >= 2 * b) {
            a %= 2 * b;
            continue;
        }
        if (b >= 2 * a) {
            b %= 2 * a;
            continue;
        }
        break;
    }
    cout << a <<   << b << endl;
    return 0;
}
