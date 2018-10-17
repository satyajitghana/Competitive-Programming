#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    --x;
    vector<int> a(n, -1);
    vector<int> b(n, -1);
    vector<vector<int>> edges(n);
    for (int i = 0; i + 1 < n; ++i) {
        int l, r;
        cin >> l >> r;
        edges[--l].push_back(--r);
        edges[r].push_back(l);
    }
    a[0] = 0;
    queue<int> bfs;
    bfs.push(0);
    while (!bfs.empty()) {
        int i = bfs.front();
        bfs.pop();
        for (int j = 0; j < edges[i].size(); ++j) {
            if (a[edges[i][j]] == -1) {
                a[edges[i][j]] = a[i] + 1;
                bfs.push(edges[i][j]);
            }
        }
    }
    b[x] = 0;
    bfs.push(x);
    while (!bfs.empty()) {
        int i = bfs.front();
        bfs.pop();
        for (int j = 0; j < edges[i].size(); ++j) {
            if (b[edges[i][j]] == -1 ) {
                b[edges[i][j]] = b[i] + 1;
                bfs.push(edges[i][j]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (b[i] < a[i]) {
            ans = max(ans, a[i]);
        }
    }
    cout << ans * 2 << endl;
    return 0;
}