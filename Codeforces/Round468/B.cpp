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
    vector<vector<vector<int>>> v(26, vector<vector<int>>(s.size(), vector<int> (26)));
    vector<int> k(26);
    for (int i = 0; i < s.size(); ++i) {
        k[s[i] - 'a']++;
        for (int j = 1; j < s.size(); ++j) {
            v[s[i] - 'a'][j][s[(i + j) % s.size()] - 'a']++;
        }
    }
    ld prob = 0;
    for (int i = 0; i < 26; ++i) {
        ld temp = 1;
        temp /= s.size();
        int temp2 = 0;
        for (int j = 1; j < s.size(); ++j) {
            int temp3 = 0;
            for (int u = 0; u < 26; ++u) {
                if (v[i][j][u] == 1) {
                    temp3 += 1;
                }
            }
            temp2 = max(temp2, temp3);
        }
        temp *= temp2;
        prob += temp;
    }
    cout << fixed << setprecision(10) << prob << endl;
    return 0;
}
