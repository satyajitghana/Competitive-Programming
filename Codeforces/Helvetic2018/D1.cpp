#include <bits/stdc++.h>

using namespace std;

struct coor{
    int a, b, i;

    bool operator<(const coor& other) const {
        return a * other.b < b * other.a;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<coor>v(n);
    for (int j = 0; j < n; ++j) {
        string s;
        cin >> s;
        v[j].a = 0;
        string temp = "";
        int i = 0;
        while (i < s.size()) {
            if (s[i] >= '0' && s[i] <= '9') {
                temp += s[i];
            } else if (temp != "") {
                v[j].a += stoi(temp);
                temp = "";
            }
            ++i;
        }
        v[j].b += stoi(temp);
        v[j].i = j;
    }
    sort(v.begin(), v.end());
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        ans[v[i].i] = upper_bound(v.begin(), v.end(), v[i]) - lower_bound(v.begin(), v.end(), v[i]);
    }
    for (int a : ans) {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}
