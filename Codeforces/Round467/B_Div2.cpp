#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    int p, y;
    cin >> p >> y;
    while (y > p) {
        int t = y;
        for (int i = 2; i * i <= y && i <= p; ++i) {
            if (t % i == 0) {
                t /= i;
                break;
            }
        }
        if (t == y) {
            cout << y << endl;
            break;
        }
        --y;
    }
    if (y == p) {
        cout << -1 << endl;
    }
    return 0;
}
