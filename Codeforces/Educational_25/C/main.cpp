#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for (int a : v) {
        while (a > k * 2) {
            ++ans;
            k *= 2;
        }
        k = max(a, k);
    }
    cout << ans << endl;
    return 0;
}