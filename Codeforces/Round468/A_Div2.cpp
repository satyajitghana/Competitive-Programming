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
    int a, b;
    cin >> a >> b;
    if (b < a) {
        swap(a, b);
    }
    int t = (b - a) / 2;
    int ans = t * (t + 1);
    if ((b - a) % 2 != 0) {
        ans += t + 1;
    }
    cout << ans << endl;
    return 0;
}
