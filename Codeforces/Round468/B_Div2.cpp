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
    int n, a, b;
    cin >> n >> a >> b;
    --a;
    --b;
    int k = 1;
    while (n > 2) {
        n /= 2;
        a /= 2;
        b /= 2;
        if (a == b) {
            cout << k << endl;
            return 0;
        }
        ++k;
    }
    return 0;
}
