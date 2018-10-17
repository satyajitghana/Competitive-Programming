#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void pre(vector<pair<int, int>> &v, vector<int> &a,
         map<int, vector<int>> &m, int i) {
    if (i != -1) {
        m[i].push_back(a.size());
        a.push_back(i);
        pre(v, a, m, v[i].first);
        pre(v, a, m, v[i].second);
    }
}

void post(vector<pair<int, int>> &v, vector<int> &a,
          map<int, vector<int>> &m, int i) {
    if (i != -1) {
        post(v, a, m, v[i].first);
        post(v, a, m, v[i].second);
        m[i].push_back(a.size());
        a.push_back(i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> v(n);
        for (auto &i : v) {
            cin >> i.first >> i.second;
            --i.first;
            --i.second;
        }
        vector<int> a(n);
        vector<int> b(n);
        map<int, vector<int>> ma;
        map<int, vector<int>> mb;
        pre(v, a, ma, 0);
        post(v, b, mb, 0);
        vector<int> ans(n, -1);
        for (int i = 0; i < a.size(); ++i) {
            if (ans[a[i]] != -1) {
                continue;
            }
            queue<int> q;
            q.push(a[i]);
            ans[a[i]] = k;
            if (a[i] != b[i]) {
                q.push(b[i]);
                ans[b[i]] = k;
            }
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int j : ma[u]) {
                    if (ans[b[j]] == -1) {
                        q.push(b[j]);
                        ans[b[j]] = k;
                    }
                }
                for (int j : mb[u]) {
                    if (ans[a[j]] == -1) {
                        q.push(a[j]);
                        ans[a[j]] = k;
                    }
                }
            }
            --k;
            if (k == -1) {
                k = 0;
            }
        }
        cout << "Case #" << test << ":";
        if (k > 0) {
            cout << " Impossible\n";
            continue;
        }
        for (int i : ans) {
            cout << " ";
            if (i == 0) {
                cout << 1;
            } else {
                cout << i;
            }
        }
        cout << endl;
    }
    return 0;
}
