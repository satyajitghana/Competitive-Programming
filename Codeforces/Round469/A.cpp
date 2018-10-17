#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    set<int> v;
    set<int> w;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0') {
            v.insert(i + 1);
        } else {
            w.insert(i + 1);
        }
    }
    vector<vector<int>> ans;
    while (v.size() != 0) {
        if (w.size() != 0 && *v.begin() > *w.begin()) {
            cout << -1n;
            return 0;
        }
        int i = ans.size();
        int j = 0;
        ans.push_back(vector<int>(1, *v.begin()));
        v.erase(v.begin());
        while (true) {
            if (w.lower_bound(ans[i][j]) != w.end()) {
                ans[i].push_back(*w.lower_bound(ans[i][j]));
                w.erase(w.lower_bound(ans[i][j]));
                ++j;
            } else {
                break;
            }
            if (v.lower_bound(ans[i][j]) != v.end()) {
                ans[i].push_back(*v.lower_bound(ans[i][j]));
                v.erase(v.lower_bound(ans[i][j]));
                ++j;
            } else {
                cout << -1n;
                return 0;
            }
        }
    }
    if (w.size() != 0) {
        cout << -1n;
        return 0;
    }
    cout << ans.size() << endl;
    for (auto &a : ans) {
        cout << a.size();
        for (int b : a) {
            cout <<   << b;
        }
        cout << endl;
    }
    return 0;
}
