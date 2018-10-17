#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long sum = 0;
    long long a;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        sum += a;
    }
    int m;
    cin >> m;
    long long ans = -1;
    long long l, r;
    while (m > 0) {
        --m;
        cin >> l >> r;
        if (l <= sum && sum <= r) {
            ans = sum;
            break;
        } else if (sum < l) {
            ans = l;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}