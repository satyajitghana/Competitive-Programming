#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == 'U' && s[i - 1] == 'R' || s[i] == 'R' && s[i - 1] == 'U') {
            --n;
            ++i;
        }
    }
    cout << n << endl;
    return 0;
}
