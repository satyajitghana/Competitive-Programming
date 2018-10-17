#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, a, b;
    string s;
    cin >> n >> a >> b >> s;
    s = * + s;
    int k = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '.') {
            if (s[i - 1] == 'a') {
                if (b != 0) {
                    --b;
                    ++k;
                    s[i] = 'b';
                }
            } else if (s[i - 1] == 'b') {
                if (a != 0) {
                    --a;
                    ++k;
                    s[i] = 'a';
                }
            } else {
                if (a > b && a > 0) {
                    --a;
                    ++k;
                    s[i] = 'a';
                } else if (b > 0) {
                    ++k;
                    --b;
                    s[i] = 'b';
                }
            }
        }
    }
    cout << k << endl;
    return 0;
}
