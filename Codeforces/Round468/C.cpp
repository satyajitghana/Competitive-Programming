#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v(2 * n);
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        v[2 * i] = mp(l, 0);
        v[2 * i + 1] = mp(r, 1);
    }
    sort(v.begin(), v.end());
    vector<int> w(m);
    int left = 0;
    int k = 0;
    for (auto p : v) {
        while (p.F > left) {
            w[left] = max(k, w[left]);
            ++left;
        }
        w[p.F] = max(w[p.F], k);
        if (p.S == 0) {
            ++k;
        } else {
            --k;
        }
        w[p.F] = max(w[p.F], k);
    }
    int p = 1;
    while (p < n) {
        p *= 2;
    }
    vector<int> d(2 * p);
    vector<int> ans(m, 0);
    for (int i = 0; i < m; ++i) {
        int a = 0;
        int l = p;
        int r = p + w[i] + 1;
        while (l != r) {
            if (l % 2 != 0) {
                a = max(a, d[l]);
                ++l;
            }
            if (r % 2 != 0) {
                --r;
                a = max(a, d[r]);
            }
            l /= 2;
            r /= 2;
        }
        ans[i] = a + 1;
        a = ans[i];
        l = p + w[i];
        while (l > 0) {
            d[l] = max(d[l], a);
            l /= 2;
        }
    }
    d.clear();
    d.resize(2 * p, 0);
    for (int i = 0; i < m; ++i) {
        int a = 0;
        int l = p + w[i];
        int r = 2 * p;
        while (l != r) {
            if (l % 2 != 0) {
                a = max(a, d[l]);
                ++l;
            }
            if (r % 2 != 0) {
                --r;
                a = max(a, d[r]);
            }
            l /= 2;
            r /= 2;
        }
        ans[i] = max(a + 1, ans[i]);
        a = ans[i];
        l = p + w[i];
        while (l > 0) {
            d[l] = max(d[l], a);
            l /= 2;
        }
    }
    int q = 0;
    for (int a : ans) {
        q = max(a, q);
    }
    cout << q << endl;
    return 0;
}
