#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    int p = 1;
    for (int i = 0; i < s.size(); ++i) {
        p *= 2;
    }
    int best = 0;
    for (int i = 0; i < p; ++i) {
        int t = i;
        string test = ;
        int j = 0;
        while (t > 0) {
            if ((t & 1) != 0) {
                test += s[j];
            }
            ++j;
            t >>= 1;
        }
        if (test.size() > best && test[0] != '0') {
            int u = stoi(test);
            int a = sqrt(u);
            if (a * a == u) {
                best = test.size();
            }
        }
    }
    if (best == 0) {
        cout << -1 << endl;
    } else {
        cout << s.size() - best << endl;
    }
    return 0;
}
