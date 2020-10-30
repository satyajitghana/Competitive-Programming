#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tests;
    cin >> tests;
    for (int t = 1; t <= tests; ++t) {
        string A;
        cin >> A;
        int i = 1;
        while(i < A.size() && A[i] != A[0]) {
            ++i;
        }
        cout << "Case #" << t << ": ";
        if (i >= A.size()) {
            cout << "Impossible\n";
        } else {
            string B = A.substr(0, i) + A;
            if (B.substr(0, A.size()) == A) {
                cout << "Impossible\n";
            } else {
                cout << B << endl;
            }
        }
    }
    return 0;
}
