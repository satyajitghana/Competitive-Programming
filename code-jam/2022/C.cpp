#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define F first
#define S second
#define pb push_back
#define eb emplace_back

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    ios_base::sync_with_stdio(false);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int &a : v) {
            cin >> a;
        }
        sort(v.begin(), v.end());
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (v[i] > res) {
                ++res;
            }
        }
        cout << "Case #" << test << ": " << res << endl;
    }
    return 0;
}
