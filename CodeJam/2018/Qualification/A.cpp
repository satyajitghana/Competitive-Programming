#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        int n;
        string s;
        cin >> n >> s;
        int k = 0;
        while (true) {
            int sum = 0;
            int damage = 1;
            int last_c = -1;
            int last_s = -1;
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] == 'C') {
                    damage *= 2;
                    last_c = i;
                } else {
                    sum += damage;
                    last_s = last_c;
                }
            }
            if (sum <= n) {
                break;
            }
            if (last_s == -1) {
                k = -1;
                break;
            }
            ++k;
            s[last_s] = 'S';
            s[last_s + 1] = 'C';
        }
        cout << "Case #" << test << ": ";
        if (k == -1) {
            cout << "Impossible\n";
        } else {
            cout << k << endl;
        }
    }
    return 0;
}
