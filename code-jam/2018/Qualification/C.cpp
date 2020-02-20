#include <bits/stdc++.h>

using namespace std;

using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        int A;
        cin >> A;
        int n = 10;
        // int m = min(max(A / n + 1, 3), 20);
        int m = 20;
        vector<vector<bool>> v(n, vector<bool>(m, false));
        int i = 0;
        int j = 0;
        int x = 1;
        int y = 1;
        while (true) {
            while (v[i][j]) {
                ++j;
                if (j >= m) {
                    ++i;
                    j = 0;
                }
            }
            cout << x + min(i + 1, n - 2) << " " << y + min(j + 1, m - 2) << endl;
            cout.flush();
            int a, b;
            cin >> a >> b;
            if (a == 0 && b == 0) {
                break;
            } else if (a == -1 && b == -1) {
                return 0;
            }
            if (i == 0 && j == 0) {
                x = a;
                y = b;
            }
            v[a - x][b - y] = true;
        }
    }
    return 0;
}
