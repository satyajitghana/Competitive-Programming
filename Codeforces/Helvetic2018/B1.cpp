#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        ++v[--a];
        ++v[--b];
    }
    int k = 0;
    for (int a : v) {
        if (a == 1) {
            ++k;
        }
    }
    cout << k << endl;
    return 0;
}
