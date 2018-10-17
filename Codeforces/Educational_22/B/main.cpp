#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long x, y, l, r;
    cin >> x >> y >> l >> r;
    vector<long long> first;
    vector<long long> second;
    long long temp = 1;
    first.push_back(temp);
    while (temp <= r / x) {
        temp *= x;
        first.push_back(temp);
    }
    temp = 1;
    second.push_back(temp);
    while (temp <= r / y) {
        temp *= y;
        second.push_back(temp);
    }
    vector<long long> m;
    for (int i = 0; i < first.size(); ++i) {
        for (int j = 0; j < second.size(); ++j) {
            if (first[i] + second[j] >= l && first[i] + second[j] <= r) {
                m.push_back(first[i] + second[j]);
            }
        }
    }
    m.push_back(l - 1);
    m.push_back(r + 1);
    sort(m.begin(), m.end());
    long long ans = 0;
    for (int i = 1; i < m.size(); ++i) {
        ans = max(ans, m[i] - m[i - 1] - 1);
    }
    std::cout << ans << std::endl;
    return 0;
}