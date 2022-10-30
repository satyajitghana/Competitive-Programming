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
        vector<int> fun(n);
        vector<int> next(n);
        vector<int> cnt(n);
        vector<int> prev(n);
        for (int &a : fun) {
            cin >> a;
        }
        for (int &a : next) {
            cin >> a;
            --a;
            if (a != -1) {
                ++cnt[a];
            }
        }
        ll res = 0;
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            if (cnt[i] == 0) {
                s.push(i);
            }
        }
        while (!s.empty()) {
            int a = s.top();
            s.pop();
            int cur_fun = max(fun[a], prev[a]);
            if (next[a] == -1) {
                res += cur_fun;
            } else {
                int b = next[a];
                if (prev[b] == 0) {
                    prev[b] = cur_fun;
                } else if (cur_fun < prev[b]) {
                    res += prev[b];
                    prev[b] = cur_fun;
                } else {
                    res += cur_fun;
                }
                --cnt[b];
                if (cnt[b] == 0) {
                    s.push(b);
                }
            }
        }
        cout << "Case #" << test << ": " << res << endl;
    }
    return 0;
}
