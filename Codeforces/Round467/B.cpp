#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> in(n);
    vector<vector<int>> out(n);
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        for (int j = 0; j < c; ++j) {
            int a;
            cin >> a;
            in[--a].push_back(i);
            out[i].push_back(a);
        }
    }
    stack<int> q;
    vector<vector<int>> mark(n, vector<int> (2, -1));
    for (int i = 0; i < n; ++i) {
        if (out[i].size() == 0) {
            mark[i][0] = -2;
            q.push(i);
        }
    }
        int u = q.top();
        q.pop();
        for (int i : in[u]) {
            if (mark[u][0] != -1 && mark[i][1] == -1) {
                mark[i][1] = u;
                q.push(i);
            }
            if (mark[u][1] != -1 && mark[i][0] == -1) {
                mark[i][0] = u;
                q.push(i);
            }
        }
    }
    int s;
    cin >> s;
    --s;
    if (mark[s][1] != -1) {
        cout << Win << endl;
        int i = 1;
        while (mark[s][i] != -2) {
            cout << s + 1 <<  ;
            s = mark[s][i];
            i = 1 - i;
        }
        cout << s + 1 << endl;
    } else {
        stack<pair<int, int>> st;
        vector<int> mark2(n, 0);
        mark2[s] = 1;
        st.push(make_pair(s, 0));
            auto u = st.top();
            st.pop();
            bool neww = false;
            for (int i = u.second; i < out[u.first].size(); ++i) {
                if (mark2[out[u.first][i]] == 1) {
                    cout << Drawn;
                    return 0;
                } else if (mark2[out[u.first][i]] == 0) {
                    mark2[out[u.first][i]] = 1;
                    neww = true;
                    st.push(make_pair(u.first, i + 1));
                    st.push(make_pair(out[u.first][i], 0));
                    break;
                }
            }
                mark2[u.first] = 2;
            }
        }
        cout << Losen;
    }
    return 0;
}
