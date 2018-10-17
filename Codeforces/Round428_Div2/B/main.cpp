#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int one = 0;
    int two = n * 2;
    int four = n;
    vector<int> v(k);
    for (int &a : v) {
        cin >> a;
        while (a >= 4 && four) {
            --four;
            a -= 4;
        }
        while (a >= 4 && two) {
            --two;
            a -= 2;
        }
    }
    sort(v.rbegin(), v.rend());
    for (int a : v) {
        if (four && a == 4) {
            --four;
        } else if (a == 3) {
            --one;
            --two;
        } else if (a == 2) {
            --two;
        } else if (a == 1) {
            --one;
        }
    }
    if (four < 0) {
        two += four * 2;
    } else {
        two += four;
        one += four;
    }
    if (two < 0) {
        one += two * 2;
    } else {
        one += two;
    }
    if (one >= 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}