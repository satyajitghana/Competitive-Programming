#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int k = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 1; j < n - k; ++j) {
            if (abs(v[j] - v[j - 1]) > 1) {
                cout << non;
                return 0;
            }
        }
        int max_pos = 0;
        for (int j = 1; j < n - k; ++j) {
            if (v[max_pos] < v[j]) {
                max_pos = j;
            }
        }
        int temp = v[max_pos];
        for (int j = max_pos + 1; j < n; ++j) {
            v[j - 1] = v[j];
        }
        ++k;
    }
    cout << yesn;
    return 0;
}
