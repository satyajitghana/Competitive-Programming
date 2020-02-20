#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tests;
    cin >> tests;
    for (int t = 1; t <= tests; ++t) {
        ll n, k, v;
        cin >> n >> k >> v;
        vector<string> data(n);
        for (auto &i : data) {
            cin >> i;
        }
        vector<pair<ll, string>> w;
        cout << "Case #" << t << ":";
        for (ll i = (v - 1) * k; i < v * k; ++i) {
            w.emplace_back(i % n, data[i % n]);
        }
        sort(w.begin(), w.end());
        for (const auto &i : w) {
            cout << " " << i.second;
        }
        cout << endl;
    } 
}
