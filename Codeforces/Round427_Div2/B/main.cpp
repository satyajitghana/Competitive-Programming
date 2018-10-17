#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int k;
    string s;
    cin >> k >> s;
    vector<int> v(10);
    int l = 0;
    for (int i = 0; i < s.size(); ++i) {
        v[s[i] - '0']++;
        l += (s[i] - '0');
    }
    int n = 0;
    while (l < k) {
        ++n;
        for (int i = 0; i < 10; ++i) {
            if (v[i] != 0) {
                l += (9 - i);
                --v[i];
                break;
            }
        }
    }
    cout << n << endl;
    return 0;
}