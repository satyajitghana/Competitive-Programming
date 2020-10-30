#include <bits/stdc++.h>

using namespace std;

using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        ld A;
        cin >> A;
        ld min_alpha = 0;
        ld max_alpha = M_PI / 4;
        ld alpha = max_alpha;
        ld min_beta = 0;
        ld max_beta = 0.9553166181245;
        ld beta = 0;
        if (A < sqrt(2)) {
            for (int i = 0; i < 30; ++i) {
                alpha = (max_alpha + min_alpha) / 2;
                ld prod = sin(alpha) + cos(alpha);
                if (prod < A) {
                    min_alpha = max((ld) 0, min(alpha, ld(M_PI / 4)));;
                } else {
                    max_alpha = max((ld) 0, min(alpha, ld(M_PI / 4)));
                }
            }
            alpha = (max_alpha + min_alpha) / 2;
        } else {
            for (int i = 0; i < 30; ++i) {
                beta = (max_beta + min_beta) / 2;
                ld prod = sin(beta) * sqrt(2) + cos(beta);
                if (prod < A) {
                    min_beta = max((ld) 0, min(beta, ld(M_PI / 4)));;
                } else {
                    max_beta = max((ld) 0, min(beta, ld(M_PI / 4)));
                }
            }
            beta = (max_beta + min_beta) / 2;
        }
        cout << "Case #" << test << ":\n";
        cout << fixed << setprecision(10) << sin(alpha) * 0.5 << " " << cos(alpha) * 0.5 * cos(beta) << " " << -sin(alpha) * 0.5 * sin(beta) << "\n";
        cout << fixed << setprecision(10) << cos(alpha) * 0.5 << " " << -sin(alpha) * 0.5 * cos(beta) << " " << sin(alpha) * 0.5 * sin(beta) << "\n";
        cout << fixed << setprecision(10) << "0 " << -0.5 * sin(beta) << " " << -0.5 * cos(beta) << "\n";
    }
    return 0;
}
