#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1000000007;

struct st {
    int a, b, c, d;

    st() : a(0), b(0), c(0), d(0) {}
    st(int a_, int b_, int c_, int d_) : a(a_), b(b_), c(c_) {}

    bool operator==(const st &o) const {
        return a == o.a && b == o.b && c == o.c && d == o.d;
    }
};

template<> struct hash<st> {
    using argument_type = st;
    using result_type = std::size_t;
    result_type operator()(argument_type const& a) const
    {
        result_type h1 ( std::hash<int>()(a.a) );
        result_type h2 ( std::hash<int>()(a.b) );
        result_type h3 ( std::hash<int>()(a.c) );
        result_type h4 ( std::hash<int>()(a.d) );
        h1 = std::hash<result_type>()(h1);
        h1 = std::hash<result_type>()(h1 + h2);
        h1 = std::hash<result_type>()(h1 + h3);
        h1 = std::hash<result_type>()(h1 + h4);
        return h1;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        int n;
        cin >> n;
        vector<pair<int, int>> v(n + 2);
        cin >> v[0].second >> v[n + 1].second;
        v[0].first = -1;
        v[n + 1].first = 1000000001;
        for (int i = 1; i <= n; ++i) {
            cin >> v[i].first >> v[i].second;
        }
        sort(v.begin(), v.end());
        unordered_map<st, int> m;
        m.insert(make_pair(st(v[0].second, v[0].second, -1, 1000000001), 1));
        for (int i = 1; i <= n; ++i) {
            unordered_map<st, int> temp;
            for (auto a : m) {
                st b = a.first;
                if (b.c < v[i].second) {
                    b.a = min(b.a, v[i].second);
                    temp[b] += a.second;
                    temp[b] %= MOD;
                }
                b = a.first;
                if (v[n + 1].second < v[i].second) {
                    b.d = min(b.d, v[i].second);
                    if (b.c < b.d) {
                        temp[b] += a.second;
                        temp[b] %= MOD;
                    }
                } else {
                    b.c = max(b.c, v[i].second);
                    if (b.c < b.d) {
                        temp[b] += a.second;
                        temp[b] %= MOD;
                    }
                }
                b = a.first;
                if (b.d > v[i].second) {
                    b.b = max(b.b, v[i].second);
                    temp[b] += a.second;
                    temp[b] %= MOD;
                }
                b = a.first;
                if (b.b < v[i].second || b.a > v[i].second) {
                    temp[b] += a.second;
                    temp[b] %= MOD;
                }
            }
            m = temp;
        }
        int ans = 1;
        while (n-- > 0) {
            ans *= 2;
            ans %= MOD;
            ans *= 2;
            ans %= MOD;
        }
        for (auto a : m) {
            ans -= a.second;
            ans += MOD;
            ans %= MOD;
        }
        cout << "Case #" << test << ": " << ans << endl;
    }
    return 0;
}
