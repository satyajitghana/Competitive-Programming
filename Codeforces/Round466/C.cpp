#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    string s;
    cin >> n >> k >> s;
    set<char> c;
    for (char a : s) {
        c.insert(a);
    }
    if (k > n) {
        while (s.size() != k) {
            s += *c.begin();
        }
    } else {
        if (k < n) {
            s.erase(k);
        }
        int i = k - 1;
        while (c.find(s[i]) == --c.end()) {
            s[i] = *c.begin();
            --i;
        }
        s[i] = *(++c.find(s[i]));
    }
    cout << s << endl;
    return 0;
}
