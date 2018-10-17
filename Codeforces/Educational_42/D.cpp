#include <bits/stdc++.h>

#define mp make_pair

using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    set<pair<ll, int>> s;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        s.insert(mp(a, i));
    }
    ll a = 0;
    int i = 0;
    vector<pair<int, ll>> v;
        if (a == s.begin()->first) {
            s.insert(mp(a * 2, s.begin()->second));
            a = 0;
        } else {
            if (a != 0) {
                v.push_back(mp(i, a));
            }
            a = s.begin()->first;
            i = s.begin()->second;
        }
        s.erase(s.begin());
    }
    v.push_back(mp(i, a));
    sort(v.begin(), v.end());
    cout << v.size() << endl;
    for (auto u : v) {
        cout << u.second <<  ;
    }
    cout << endl;
    return 0;
}
