#include <bits/stdc++.h>

using namespace std;

int main() {
    int l, r, a;
    cin >> l >> r >> a;
    while (a--) {
        if (l < r) {
            ++l;
        } else {
            ++r;
        }
    }
    cout << min(l, r) * 2 << endl;
    return 0;
}
