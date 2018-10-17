#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(1000001);
    vector<long long> two(v.size());
    vector<long long> len(v.size());
    two[0] = 1;
    long long ans = 0;
    long long mod = 1000000007;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ++v[a];
    }
    for (int i = 1; i < v.size(); ++i) {
        for (int j = 2 * i; j < v.size(); j += i) {
            v[i] += v[j];
        }
        two[i] = two[i - 1] * 2;
        two[i] %= mod;
    }
    for (int i = v.size() - 1; i > 1; --i) {
        if (v[i] != 0) {
            len[i] = (two[v[i] - 1] * v[i]) % mod;
            for (int j = 2 * i; j < v.size(); j += i) {
                len[i] -= len[j];
                while (len[i] < 0) {
                    len[i] += mod;
                }
            }
            ans += len[i] * i;
            ans %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}