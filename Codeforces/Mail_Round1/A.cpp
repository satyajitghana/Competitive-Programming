#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    int x, y, z, t1, t2, t3;
    cin >> x >> y >> z >> t1 >> t2 >> t3;
    if ((abs(z - x) + abs(y - x)) * t2 + 3 * t3 <= abs(y - x) * t1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}
