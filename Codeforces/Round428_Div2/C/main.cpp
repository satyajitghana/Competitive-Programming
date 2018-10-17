#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        v[--a].push_back(--b);
        v[b].push_back(a);
    }
    double ans = 0;
    vector<bool> marks(n, false);
    marks[0] = true;
    queue<pair<int, pair<int, double>>> q;
    q.push(make_pair(0, make_pair(0, 1)));
    while (!q.empty()) {
        pair<int, pair<int, double>> temp = q.front();
        q.pop();
        int count = 0;
        for (int i : v[temp.first]) {
            if (!marks[i]) {
                ++count;
            }
        }
        for (int i : v[temp.first]) {
            if (!marks[i]) {
                q.push(make_pair(i, make_pair(temp.second.first + 1, temp.second.second / count)));
                marks[i] = true;
            }
        }
        if (!count) {
            ans += temp.second.second * temp.second.first;
        }
    }
    cout << setprecision(10) << ans << endl;
    return 0;
}