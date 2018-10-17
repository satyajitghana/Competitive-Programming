#include <iostream>

using namespace std;

int main() {
    int n, k;
    int ans = 0;
    int candies = 0;
    cin >> n >> k;
    while (n-- && k > 0) {
        ++ans;
        int a;
        cin >> a;
        candies += a;
        k -= min(candies, 8);
        candies = max(candies - 8, 0);
    }
    if (0 < k) {
        cout << "-1\n";
    } else {
        cout << ans << endl;
    }
    return 0;
}