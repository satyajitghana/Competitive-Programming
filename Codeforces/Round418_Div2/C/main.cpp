#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int q;
    cin >> q;
    while (q-- > 0) {
        int m;
        char c;
        cin >> m >> c;
        int l = 0;
        int r = 0;
        while (0 < m && r < n) {
            if (s[r] != c) {
                --m;
            }
            ++r;
        }
        while (r < n && s[r] == c) {
            ++r;
        }
        int ans = r - l;
        while (r < n) {
            while (r < n && s[r] == c) {
                ++r;
            }
            ++r;
            while (r < n && s[r] == c) {
                ++r;
            }
            while (s[l] == c) {
                ++l;
            }
            ++l;
            ans = max(ans, r - l);
        }
        cout << ans << endl;
    }
    return 0;
}