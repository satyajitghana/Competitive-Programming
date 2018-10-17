#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct tup {
    vector<ll> a;
    int n = 4;

    tup() {
        a.resize(n, 0);
    }

    tup(vector<ll> v) {
        a = v;
    }

    void operator+=(const tup &other) {
        for (int i = 0; i < n; ++i) {
            a[i] += other.a[i];
        }
    }

    tup operator+(const tup& s) const {
        vector<ll> temp(n);
        for (int i = 0; i < n; ++i) {
            temp[i] = a[i] + s.a[i];
        }
        return tup(temp);
    }

    tup operator+(const int& s) const {
        vector<ll> temp(n);
        for (int i = 0; i < n; ++i) {
            temp[i] = a[i] + s;
        }
        return tup(temp);
    }

    tup operator%(const tup &s) const {
        vector<ll> temp(n);
        for (int i = 0; i < n; ++i) {
            temp[i] = a[i] % s.a[i];
        }
        return tup(temp);
    }

    tup operator-(const tup& s) const {
        vector<ll> temp(n);
        for (int i = 0; i < n; ++i) {
            temp[i] = a[i] - s.a[i];
        }
        return tup(temp);
    }

    tup operator*(const tup& s) const {
        vector<ll> temp(n);
        for (int i = 0; i < n; ++i) {
            temp[i] = a[i] * s.a[i];
        }
        return tup(temp);
    }

    bool operator==(const tup &other) const {
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            ok &= (a[i] == other.a[i]);
        }
        return ok;
    }

    void add_smaller(const tup& other) {
        for (int i = 0; i < n; ++i) {
            if (a[i] < 0) {
                a[i] += other.a[i];
            } 
        }
    }
};

tup p(vector<ll>{999873917, 1000000007, 111111003, 1515121107});
tup a(vector<ll>{143, 101, 197, 31});

vector<tup> hashh(string s) {
    vector<tup> ans(s.size() + 1);
    for (int i = 1; i <= s.size(); ++i) {
        ans[i] = (ans[i - 1] * a + (s[i - 1] - 'a')) % p;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    vector<string> w(m);
    vector<vector<tup>> hashv(n + 1);
    hashv[0] = vector<tup> (m + 1);
    vector<vector<tup>> hashw(m);
    tup am = tup(vector<ll>{1, 1, 1, 1});
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        hashv[i + 1] = hashh(v[i]);
    }
    for (int i = 0; i < m; ++i) {
        cin >> w[i];
        am = (am * a) % p;
        hashw[i] = hashh(w[i]);
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j <= n - m; ++j) {
            hashw[i][j] = (hashw[i][j] * am - hashw[i][j + m]) % p;
            hashw[i][j].add_smaller(p);
            if (i > 0) {
                hashw[i][j] = (hashw[i - 1][j] * a + hashw[i][j]) % p;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        hashv[i][m] = (hashv[i - 1][m] * a + hashv[i][m]) % p;
    }
    for (int i = 0; i <= n - m; ++i) {
        hashv[i][m] = (hashv[i][m] * am - hashv[i + m][m]) % p;
        hashv[i][m].add_smaller(p);
    }
    for (int i = 0; i <= n - m; ++i) {
        for (int j = 0; j <= n - m; ++j) {
            if (hashv[i][m] == hashw[m - 1][j]) {
                bool ok = true;
                for (int ii = 0; ii < m; ++ii) {
                    for (int jj = 0; jj < m; ++jj) {
                        if (v[i + ii][jj] != w[ii][j + jj]) {
                            ok = false;
                            break;
                        }
                    }
                    if (!ok) {
                        break;
                    }
                }
                if (ok) {
                    cout << i + 1 << " " << j + 1 << endl;
                    return 0;
                }
            }
        }
    }
    throw runtime_error("");
    return 0;
}
