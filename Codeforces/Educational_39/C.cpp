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
    char it = 'a';
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] <= it) {
            s[i] = it;
            ++it;
        }
        if (it > 'z') {
            break;
        }
    }
    if (it <= 'z') {
        cout << -1 << endl;
    } else {
        cout << s << endl;
    }
    return 0;
}
