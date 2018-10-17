#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, p;
    cin >> n >> p;
    vector<int> v(n);
    vector<int> pref(n);
    vector<int> suf(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    pref[0] = v[0] % p;
    for (int i = 1; i < n; ++i) {
        pref[i] = (pref[i - 1] + v[i]) % p;
    }
    suf[n - 1] = v[n - 1] % p;
    for (int i = n - 2; i >= 0; --i) {
        suf[i] = (suf[i + 1] + v[i]) % p; 
    }
    int best_ans = 0;
    for (int i = 0; i + 1 < n; ++i) {
        best_ans = max(best_ans, pref[i] + suf[i + 1]);
    }
    cout << best_ans << endl;
    return 0;
}
