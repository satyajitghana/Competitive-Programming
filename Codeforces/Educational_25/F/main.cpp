#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> z_func(const string& s, int u) {
    vector<int> ans(s.size() - u);
    int r = 0;
    int l = 0;
    for (int i = 1; i < s.size() - u; ++i) {
        if (i < r) {
            ans[i] = min(ans[i - l], r - i);
        }
        while (u + i + ans[i] < s.size() && s[i + ans[i] + u] == s[ans[i] + u]) {
            ++ans[i];
        }
        if (i + ans[i] >= r) {
            l = i;
            r = i + ans[i];
        }
    }
    ans[0] = ans.size();
    return ans;
}

int get_digits(int a) {
    int k = 0;
    while (a > 0) {
        a /= 10;
        ++k;
    }
    return k;
}

int main() {
    string s;
    cin >> s;
    vector<vector<int>> v(s.size());
    for (int i = 0; i < s.size(); ++i) {
        v[i] = z_func(s, i);
    }
    vector<int> ans(s.size() + 1);
    for (int i = 0; i < s.size(); ++i) {
        ans[i + 1] = i + 2;
    }
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 1; j <= v[i].size(); ++j) {
            int k = 0;
            while (i + j * k < s.size() && v[i][j * k] >= j) {
                ++k;
                ans[i + j * k] = min(ans[i + j * k], ans[i] + j + get_digits(k));
            }
        }
    }
    cout << ans[s.size()];
    return 0;
}