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
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<vector<int>> time(n + 1, vector<int> (k + 1, 1000000));
    time[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        vector<int> times;
        for (int j = 0; j < m; ++j) {
            if (v[i][j] == '1') {
                times.push_back(j);
            }
        }
        vector<int> best(times.size() + 1, 1000000);
        best[0] = 0;
        for (int j = 0; j < times.size(); ++j) {
            for (int z = 0; z + j < times.size(); ++z) {
                best[j + 1] = min(best[j + 1], times[z + j] - times[z] + 1);
            }
        }
        for (int j = 0; j <= k; ++j) {
            for (int z = j; z <= k; ++z) {
                if (z - j <= times.size()) {
                    time[i + 1][z] = min(time[i + 1][z], time[i][j] + best[times.size() - z + j]);
                }
            }
        }
    }
    int best_time = 1000000;
    for (int i = 0; i <= k; ++i) {
        best_time = min(time[n][i], best_time);
    }
    cout << best_time << endl;
    return 0;
}
