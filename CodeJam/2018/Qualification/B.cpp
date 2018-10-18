#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        int n;
        cin >> n;
        vector<int> odd((n >> 1) + (n & 1));
        vector<int> even((n >> 1));
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            if ((i & 1) == 0) {
                cin >> odd[i >> 1];
            } else {
                cin >> even[i >> 1];
            }
        }
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        merge(odd.begin(), odd.end(), even.begin(), even.end(), v.begin());
        int fail = -1;
        for (int i = 0; i < n; ++i) {
            if ((i & 1) == 0 && odd[i >> 1] != v[i]) {
                fail = i;
                break;
            } else if ((i & 1) == 1 && even[i >> 1] != v[i]) {
                fail = i;
                break;
            }
        }
        cout << "Case #" << test << ": ";
        if (fail == -1) {
            cout << "OK\n";
        } else {
            cout << fail << endl;
        }
    }
    return 0;
}
