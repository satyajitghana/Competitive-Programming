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
    int sum = 0;
    while (n--) {
        int a;
        cin >> a;
        sum += a > 0 ? a : -a;
    }
    cout << sum << endl;
    return 0;
}
