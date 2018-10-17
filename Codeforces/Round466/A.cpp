#include <bits\stdc++.h>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> v(n);
    for (int &i : v) {
        cin >> i;
    }
    sort (v.begin(), v.end());
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (v[j] - v[i] <= d) {
                ans = max(j - i + 1, ans);
            }
        }
    }
    cout << n - ans;
}
