#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    vector<int> ss(26);
    vector<int> tt(26);
    for (char a : s) {
        if (a != '?') {
            ss[a - 'a']++;
        }
    }
    for (char a : t) {
        if (a != '?') {
            tt[a - 'a']++;
        }
    }
    int k = 0;
    int first_i = 0;
    while(true) {
        for (int i = 0; i < 26; ++i) {
            while (ss[i] < k * tt[i]) {
                while (first_i < s.length()) {
                    if (s[first_i] == '?') {
                        s[first_i] = 'a' + i;
                        ++first_i;
                        ++ss[i];
                        break;
                    }
                    ++first_i;
                }
                if (first_i >= s.length()) {
                    break;
                }
            }
        }
        ++k;
        if (first_i >= s.length()) {
            break;
        }
    }
    cout << s << endl;
    return 0;
}