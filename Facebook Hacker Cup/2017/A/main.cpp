#include <iostream>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tests;
    cin >> tests;
    for (int t = 1; t <= tests; ++t) {
        int n, m, k;
        cin >> n >> m >> k;
        int answer = -1;
        if (n >= 2 * k + 3 && m > k) {
            answer = (m + k - 1) / k;
        }
        if (m >= 2 * k + 3 && n > k) {
            if (answer == -1) {
                answer = (n + k - 1) / k;
            } else {
                answer = min(answer, (n + k - 1) / k);
            }
        }
        if (answer > 5 && k == 1) {
            answer = 5;
        }
        if (answer > 4 && k != 1) {
            answer = 4;
        }
        cout << "Case #" << t << ": " << answer << endl;
    }
    return 0;
}