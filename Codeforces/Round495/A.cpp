#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, d, a;
    cin >> n >> d >> a;
    int k = 2;
    while (--n) {
        int b = a + d;
        cin >> a;
        if (a - d == b) {
            ++k;
        } else if (b < a - d) {
            k += 2;
        }
    }
    cout << k << endl;
    return 0;
}
