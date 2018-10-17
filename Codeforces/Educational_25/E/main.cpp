#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> in(n);
    vector<int> out(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        in[b].push_back(a);
        ++out[a];
    }
    set<int> se;
    stack<int> s;
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        if (out[i] == 0) {
            se.insert(i);
        }
    }
    int l = 1;
    while (!se.empty()) {
        int a = *(--se.end());
        se.erase(--se.end());
        s.push(a);
        for (int j : in[a]) {
            --out[j];
            if (out[j] == 0) {
                se.insert(j);
            }
        }
    }
    while (!s.empty()) {
        ans[s.top()] = l;
        ++l;
        s.pop();
    }
    cout << ans[0];
    for (int i = 1; i < n; ++i) {
        cout << " " << ans[i];
    }
    cout << endl;
    return 0;
}