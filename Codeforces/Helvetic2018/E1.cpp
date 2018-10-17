#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

vector<bool> use;
vector<int> comb;

struct line{
    ll A, B, C;
};

bool rek(const vector<pll> &v, const vector<pll> &w, int i) {
    if (i == v.size()) {
        vector<line> lines(v.size());
        for (int j = 0; j < v.size(); ++j) {
            lines[j].A = v[j].S - w[comb[j]].S;
            lines[j].B = w[comb[j]].F - v[j].F;
            lines[j].C = v[j].F * w[comb[j]].S - v[j].S * w[comb[j]].F;
        }
        for (int j = 0; j < v.size(); ++j) {
            for (int k = j + 1; k < v.size(); ++k) {
                int a = 1;
                int b = 1;
                int c = 1;
                int d = 1;
                if (lines[j].A * v[k].F + lines[j].B * v[k].S + lines[j].C < 0) {
                    a = -1;
                }
                if (lines[j].A * w[comb[k]].F + lines[j].B * w[comb[k]].S + lines[j].C < 0) {
                    b = -1;
                }
                if (lines[k].A * v[j].F + lines[k].B * v[j].S + lines[k].C < 0) {
                    c = -1;
                }
                if (lines[k].A * w[comb[j]].F + lines[k].B * w[comb[j]].S + lines[k].C < 0) {
                    d = -1;
                }
                if (a * b < 0 && c * d < 0) {
                    return false;
                }
            }
        }
        return true;
    } else {
        for (int j = 0; j < w.size(); ++j) {
            if (!use[j]) {
                use[j] = true;
                comb[i] = j;
                if(rek(v, w, i + 1)) {
                    return true;
                }
                use[j] = false;
            }
        }
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<pll> v(n);
    for (auto &p : v) {
        cin >> p.F >> p.S;
    }
    vector<pll> w(m);
    for (auto &p : w) {
        cin >> p.F >> p.S;
    }
    use.resize(m, false);
    comb.resize(n);
    if (n != m || !rek(v, w, 0)) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }
    return 0;
}
