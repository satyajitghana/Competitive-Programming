#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int m = 0;
    int i = 0;
    while (n--) {
        ++i;
        int a;
        cin >> a;
        if (a == m) {
            ++m;
        } else if (m < a) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
