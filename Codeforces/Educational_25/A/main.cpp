#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s >> s;
    int k = 0;
    string ans = "";
    for (char a : s) {
        if (a == '0') {
            ans += ('0' + k);
            k = 0;
        } else {
            ++k;
        }
    }
    ans += ('0' + k);
    cout << ans;
    return 0;
}