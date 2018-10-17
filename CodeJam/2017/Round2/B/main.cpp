#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("output", "w", stdout);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        int n, c, m;
        cin >> n >> c >> m;
        int p = 1;
        while (p < n) {
            p *= 2;
        }
        vector<pair<int, int>> data(2 * p, make_pair(0, 0));
        vector<int> pass(c);
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            ++data[--a + p].first;
            ++pass[--b];
        }
        int rays = 0;
        for (int i = 0; i < c; ++i) {
            rays = max(rays, pass[i]);
        }
        for (int i = p - 1; i > 0; --i) {
            data[i].first = max(data[2 * i].first, data[2 * i + 1].first);
        }
        int last_ans = 0;
        int ans = 0;
        int last_first = INT32_MAX;
        while (data[1].first > rays) {
            if (data[1].first < last_first) {
                last_first = data[1].first;
                last_ans = ans;
            }
            int a = 1;
            while (a < p) {
                if (data[a].first == data[2 * a + 1].first) {
                    a = 2 * a + 1;
                } else {
                    a *= 2;
                }
            }
            if (a == p) {
                break;
            }
            ++data[a - 1].first;
            ++data[a - 1].second;
            --data[a].first;
            if (data[a].second != 0) {
                --data[a].second;
            } else {
                ++ans;
            }
            int temp_a = a;
            a /= 2;
            while (a > 0) {
                data[a].first = max(data[2 * a].first, data[2 * a + 1].first);
                a /= 2;
            }
            a = temp_a - 1;
            a /= 2;
            while (a > 0) {
                data[a].first = max(data[2 * a].first, data[2 * a + 1].first);
                a /= 2;
            }
        }
        if (data[1].first < last_first) {
            last_ans = ans;
        }
        cout << "Case #" << test << ": " << max(data[1].first, rays) << " " << last_ans << std::endl;
    }
    return 0;
}