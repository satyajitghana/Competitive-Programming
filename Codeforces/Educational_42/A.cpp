
 #include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    int sum = 0;
    for (int &i : v) {
        cin >> i;
        sum += i;
    }
    int sum2 = 0;
    for (int i = 0 ; i < n; ++i) {
        sum2 += v[i];
        if (sum2 * 2 >= sum) {
            cout << i + 1 << endl;
            return 0;
        }
    }
}
