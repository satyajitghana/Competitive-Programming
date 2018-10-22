#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

using ll = long long;
using ld = long double;

struct ttt {
    int a, b, c, d;

    ttt(int a_, int b_, int c_, int d_) : a(a_), b(b_), c(c_), d(d_) {}
};


int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<string> w(n * m);
    vector<ttt> a;
    a.reserve(400000);
    vector<int> o(m);
    vector<int> z(m);
    for (int i = 0; i < n * m; ++i) {
        string s;
        cin >> s;
        for (int j = s.size(); j > 0; --j) {
            if (s[j - 1] == '0') {
                if (i == 0) {
                    a.emplace_back(1, 1, 1, 2);
                    ++z[1];
                } else if (i < m) {
                    a.emplace_back(1, i % m + 1, 1, 1);
                    ++z[0];
                } else {
                    a.emplace_back(i / m + 1, i % m + 1, 1, i % m + 1);
                    ++z[i % m];
                }
            } else {
                if (i == m) {
                    a.emplace_back(2, 1, 2, 2);
                    ++o[1];
                } else if (i > m && i < 2 * m) {
                    a.emplace_back(2, i % m + 1, 2, 1);
                    ++o[0];
                } else {
                    a.emplace_back(i / m + 1, i % m + 1, 2, i % m + 1);
                    ++o[i % m];
                }
            }
        }
    }
    z[0] = 0;
    o[0] = 0;
    for (int i = 0; i < m; ++i) {
        while (z[i]) {
            --z[i];
            a.emplace_back(1, i + 1, 1, 1);
        }
        while (o[i]) {
            --o[i];
            a.emplace_back(2, i + 1, 2, 1);
        }
    }
    for (int i = 0; i < n * m; ++i) {
        cin >> w[i];
        for (int j = w[i].size(); j > 0; --j) {
            if (w[i][j - 1] == '0') {
                if (i / m != 0) {
                    ++z[i % m];
                } else if (i % m != 0) {
                    ++z[0];
                } else {
                    ++z[1];
                }
            } else {
                if (i / m != 1) {
                    ++o[i % m];
                } else if (i % m != 0) {
                    ++o[0];
                } else {
                    ++o[1];
                }
            }
        }
    }
    z[0] = 0;
    o[0] = 0;
    for (int i = 0; i < m; ++i) {
        while (z[i]) {
            --z[i];
            a.emplace_back(1, 1, 1, i + 1);
        }
        while (o[i]) {
            --o[i];
            a.emplace_back(2, 1, 2, i + 1);
        }
    }
    for (int i = 0; i < n * m; ++i) {
        for (int j = w[i].size(); j > 0; --j) {
            if (w[i][j - 1] == '0') {
                if (i / m != 0) {
                    a.emplace_back(1, i % m + 1, i / m + 1, i % m + 1);
                } else if (i % m != 0) {
                    a.emplace_back(1, 1, 1, i % m + 1);
                } else {
                    a.emplace_back(1, 2, 1, 1);
                }
            } else {
                if (i / m != 1) {
                    a.emplace_back(2, i % m + 1, i / m + 1, i % m + 1);
                } else if (i % m != 0) {
                    a.emplace_back(2, 1, 2, i % m + 1);
                } else {
                    a.emplace_back(2, 2, 2, 1);
                }
            }
        }
    }
    cout << a.size() << endl;
    for (auto &b : a) {
        printf("%d %d %d %d\n", b.a,  b.b, b.c, b.d);
    }
    return 0;
}
