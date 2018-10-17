#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

using namespace std;

using ll = long long;

ll res(const vector<int> &a, const vector<int> &c) {
    if (a.size() == 0 || c.size() == 0) {
        return 0;
    }
    ll sum = 0;
    if (a[0] < c[0]) {
        sum += c[0] - a[0];
    }
    if (a[a.size() - 1] > c[c.size() - 1]) {
        sum += a[a.size() - 1] - c[c.size() - 1];
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a;
    vector<int> b;
    vector<int> c;
    for (int i = 0; i < n; ++i) {
        int x;
        char y;
        cin >> x >> y;
        if (y == 'B') {
            a.pb(x);
        } else if (y == 'R') {
            b.pb(x);
        } else {
            c.pb(x);
        }
    }
    ll sum = 0;
    if (c.size() == 0) {
        if (a.size() != 0) {
            sum += a[a.size() - 1] - a[0];
        }
        if (b.size() != 0) {
            sum += b[b.size() - 1] - b[0];
        }
        cout << sum << endl;
        return 0;
    }
    sum += c[c.size() - 1] - c[0];
    sum += res(a, c);
    sum += res(b, c);
    for (int i = 1; i < c.size(); ++i) {
        auto f = lower_bound(a.begin(), a.end(), c[i - 1]);
        auto e = upper_bound(a.begin(), a.end(), c[i]);
        auto ff = lower_bound(b.begin(), b.end(), c[i - 1]);
        auto ee = upper_bound(b.begin(), b.end(), c[i]);
        if (e == f) {
            if (ee == ff) {
                continue;
            }
            --ee;
            int m = max(*ff - c[i - 1], c[i] - *ee);
            ++ee;
            auto p = ff;
            while (++ff != ee) {
                m = max(m, *ff - *p);
                ++p;
            }
            sum += c[i] - c[i - 1] - m;
            continue;
        }
        if (ee == ff) {
            --e;
            int m = max(*f - c[i - 1], c[i] - *e);
            ++e;
            auto p = f;
            while (++f != e) {
                m = max(m, *f - *p);
                ++p;
            }
            sum += c[i] - c[i - 1] - m;
            continue;
        }
        --e;
        --ee;
        int m = max(*f - c[i - 1], c[i] - *e);
        ++e;
        int mm = max(*ff - c[i - 1], c[i] - *ee);
        ++ee;
        auto p = f;
        auto pp = ff;
        while (++f != e) {
            m = max(m, *f - *p);
            ++p;
        }
        while (++ff != ee) {
            mm = max(mm, *ff - *pp);
            ++pp;
        }
        if (c[i] - c[i - 1] > m + mm) {
            sum += c[i] - c[i - 1];
        } else {
            sum += c[i] - c[i - 1] - m;
            sum += c[i] - c[i - 1] - mm;
        }
    }
    cout << sum << endl;
    return 0;
}
