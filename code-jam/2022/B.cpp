#include <iostream>
#include <vector>

using namespace std;

int M = 1000000;

int main() {
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        vector<int> v(12);
        for (int &a : v) {
            cin >> a;
        }
        for (int i = 0; i < 4; ++i) {
            v[i] = min(v[i], min(v[4 + i], v[8 + i]));
        }
        int s = v[0] + v[1] + v[2] + v[3];
        cout << "Case #" << test << ": ";
        if (s < M) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << min(v[0], M) << " " <<
                min(v[1], max(0, M - v[0])) << " " <<
                min(v[2], max(0, M - v[0] - v[1])) << " " <<
                min(v[3], max(0, M - v[0] - v[1] - v[2])) << endl;
        }
    }
}
