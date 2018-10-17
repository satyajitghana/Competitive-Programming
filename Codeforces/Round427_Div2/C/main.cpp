#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q, c;
    cin >> n >> q >> c;
    vector<vector<int>> v(n, vector<int> (3));
    for (int i = 0; i < n; ++i) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }
    vector<vector<vector<int>>> m(c + 1, vector<vector<int>>(100, vector<int> (100)));
    for (int i = 0; i <= c; ++i) {
        for (int j = 0; j < n; ++j) {
            m[i][v[j][0] - 1][v[j][1] - 1] += (v[j][2] + i) % (c + 1);
        }
    }
    vector<vector<vector<int>>> w(c + 1, vector<vector<int>>(101, vector<int> (101)));
    for (int i = 0; i <= c; ++i) {
        for (int j = 1; j <= 100; ++j) {
            for (int l = 1; l <= 100; ++l) {
                w[i][j][l] = m[i][j - 1][l - 1] + w[i][j - 1][l] + w[i][j][l - 1] - w[i][j - 1][l - 1];
            }
        }
    }
    ++c;
    while (q-- > 0) {
        int t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        cout << w[t % c][x2][y2] - w[t % c][x1 - 1][y2] - w[t % c][x2][y1 - 1] + w[t % c][x1 - 1][y1 - 1] << endl;
    }
    return 0;
}