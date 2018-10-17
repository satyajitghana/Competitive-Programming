#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, k = 0;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> v(n);
    vector<int> w(26, -1);
    for (int i = 0; i < n; ++i) {
        if (w[s[i] - 'A'] == -1) {
            ++v[i];
        }
        w[s[i] - 'A'] = i;
    }
    for (int i = 0; i < 26; ++i) {
        if (w[i] != -1 && w[i] + 1 < n) {
            --v[w[i] + 1];
        }
    }
    int real_k = 0;
    for (int i = 0; i < n; ++i) {
        real_k += v[i];
        if (real_k > k) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}