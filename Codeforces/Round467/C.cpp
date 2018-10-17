#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

vector<int> z_function (const string& s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i=1, l=0, r=0; i<n; ++i) {
        if (i <= r)
            z[i] = min (r-i+1, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if (i+z[i]-1 > r)
            l = i,  r = i+z[i]-1;
    }
    return z;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    string s, t;
    cin >> n >> s >> t;
    int good_part = 0;
    vector<int> ans;
    vector<int> ccc(26);
    for (char a : s) {
        ccc[a - 'a']++;
    }
    for (char a : t) {
        ccc[a - 'a']--;
    }
    for (int i : ccc) {
        if (i != 0) {
            cout << -1 << endl;
            return 0;
        }
    }
    while (good_part < n) {
        string temp = t;
        temp += ;
        temp += s;
        auto z = z_function(temp);
        int max_i = t.size() + 1;
        for (int j = t.size() + 1; j < z.size(); ++j) {
            if (z[j] > z[max_i]) {
                max_i = j;
            }
        }
        int best_z = z[max_i];
        max_i -= t.size() + 1;
        int bad_part = t.size() - max_i - best_z;
        if (bad_part + max_i + best_z != 0) {
            ans.push_back(bad_part + max_i + best_z );
        }
        if (good_part + max_i != 0) {
            ans.push_back(good_part + max_i);
        }
        if (bad_part + best_z + max_i != 0) {
            ans.push_back(bad_part + best_z + max_i);
        }
        if (good_part != 0) {
            ans.push_back(good_part);
        }
        temp = ;
        for (int j = max_i + best_z; j < s.size(); ++j) {
            temp += s[j];
        }
        for (int j = max_i - 1; j >= 0; --j) {
            temp += s[j];
        }
        good_part += best_z;
        t.erase(0, best_z);
        s = std::move(temp);
    }
    if (ans.size() > 6100) {
    throw runtime_error(err);
    }
    cout << ans.size() << endl;
    for (int i : ans) {
        cout << i <<  ;
    }
    cout << endl;
    return 0;
}
