#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int best_ans = n;
    for (int i = 1; (i << 1) <= s.size(); ++i) {
        string a = s.substr(0, i);
        string b = s.substr(i, i);
        if (a == b) {
            best_ans = n - i + 1;
        }
    }
    cout << best_ans << endl;
    return 0;
}
