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
    int n, m, h;
    cin >> n >> m >> h;
    vector<int> centers(n);
    for (int &i : centers) {
        cin >> i;
    }
    vector<vector<int>> edges(n);
    vector<vector<int>> t(n);
    while (m--) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        if ((centers[a] + 1) % h == centers[b]) {
            edges[a].push_back(b);
            t[b].push_back(a);
        }
        if ((centers[b] + 1) % h == centers[a]) {
            edges[b].push_back(a);
            t[a].push_back(b);
        }
    }
    vector<int> used(n, -1);
    vector<int> order;
    for (int i = 0; i < n; ++i) {
        if (used[i] == -1) {
            used[i] = 0;
            stack<pair<int, int>> s;
            s.push(mp(i, 0));
                int u = s.top().F;
                int q = s.top().S;
                s.pop();
                int j;
                for (j = q; j < edges[u].size(); ++j) {
                    if (used[edges[u][j]] == -1) {
                        s.push(mp(u, j + 1));
                        s.push(mp(edges[u][j], 0));
                        used[edges[u][j]] = 0;
                        break;
                    }
                }
                if (j == edges[u].size()) {
                    order.pb(u);
                }
            }
        }
    }
    int comp = 1;
    for (int i = n - 1; i >= 0; --i) {
        if (used[order[i]] == 0) {
            used[order[i]] = comp;
            queue<int> q;
            q.push(order[i]);
                int u = q.front();
                q.pop();
                for (int j : t[u]) {
                    if (used[j] == 0) {
                        used[j] = comp;
                        q.push(j);
                    }
                }
            }
            ++comp;
        }
    }
    vector<int> ans(comp, 0);
    for (int i = 0; i < n; ++i) {
        ++ans[used[i]];
        for (int u : edges[i]) {
            if (used[u] != used[i]) {
                ans[used[i]] = 1000000;
            }
        }
    }
    int best = 1000000;
    int temp = 0;
    for (int i = 1; i < comp; ++i) {
        if (ans[i] < best) {
            best = ans[i];
            temp = i;
        }
    }
    cout << best << endl;
    for (int i = 0; i < n; ++i) {
        if (used[i] == temp) {
            cout << i + 1 <<  ;
        }
    }
    cout << endl;
    return 0;
}
