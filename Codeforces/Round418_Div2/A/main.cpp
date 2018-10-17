#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(k);
    for (int i = 0; i < k; ++i) {
        cin >> b[i];
    }
    sort(b.rbegin(), b.rend());
    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            a[i] = b[j];
            ++j;
        }
    }
    bool increase = true;
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[i - 1]) {
            increase = false;
            break;
        }
    }
    if (increase) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }
    return 0;
}