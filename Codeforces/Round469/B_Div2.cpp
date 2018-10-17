#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int &i : v) {
        cin >> i;
    }
    int sum = 0;
    int k = 0;
    auto it = v.begin();
    while (m--) {
        int a;
        cin >> a;
        sum += a;
        while (sum > 0) {
            sum -= *it;
            ++it;
        }
        if (sum == 0) {
            ++k;
        }
    }
    cout << k << endl;
    return 0;
}
