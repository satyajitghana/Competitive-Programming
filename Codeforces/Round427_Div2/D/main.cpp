#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> z_func(string s, int st) {
    vector<int> v(s.size() - st);
    int l = 0;
    int r = 0;
    for (int i = st + 1; i < s.size(); ++i) {
        if (i < r) {
            v[i - st] = min(v[i - l], r - i);
        }
        while (i + v[i - st] < s.size() && s[i + v[i - st]] == s[v[i - st] + st]) {
            ++v[i - st];
        }
        if (i + v[i - st] > r) {
            r = i + v[i - st];
            l = i;
        }
    }
    return v;
}

int main() {
    string s;
    cin >> s;
    string rev = "";
    for (int i = s.size() - 1; i >= 0; --i) {
        rev += s[i];
    }
    vector<vector<int>> z(s.size());
    string tr = s + '$' + rev;
    for (int i = 0; i < s.size(); ++i) {
        z[i] = z_func(tr, i);
    }
    vector<vector<bool>> temp(s.size(), vector<bool>(s.size(), false));
    vector<int> ans(s.size());
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 1; i + j <= s.size(); ++j) {
            if (z[i][2 * s.size() - 2 * i - j + 1] >= j) {
                ++ans[0];
                temp[i][j - 1] = true;
            }
        }
    }
    int l = 1;
    for (int i = 1; i < s.size(); ++i) {
        for (int j = 0; j < s.size(); ++j) {
            for (int g = (s.size() - j) / 2; g >= l; --g) {
                if (z[j][g] >= g && temp[j][g - 1]) {
                    ++ans[i];
                    temp[j][2 * g - 1] = true;
                }
                if (j + 2 * g + 1 <= s.size() && z[j][g + 1] >= g && temp[j][g - 1]) {
                    ++ans[i];
                    temp[j][2 * g] = true;
                }
                temp[j][g - 1] = false;
            }
        }
        if (l < 10000) {
            l *= 2;
        }
    }
    for (int i = 0; i < s.size(); ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}