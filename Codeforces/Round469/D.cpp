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
    ll n, d, k;
    cin >> n >> d >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<int> pref(n);
    pref[0] = v[0];
    for (int i = 1; i < n; ++i) {
        pref[i] = v[i] + pref[i - 1];
    }
    int a = 0;
    int b = 0;
    int j = 0;
    int up = 0;
    for (int i = 0; i < n / 2 + n % 2; ++i) {
        if (pref[min(n - 1, i + d * (i + 1))] - up >= k) {
            up += k;
            int temp = k;
            while (temp != 0) {
                if (v[j] >= temp) {
                    v[j] -= temp;
                    temp = 0;
                } else {
                    temp -= v[j];
                    v[j] = 0;
                    ++j;
                }
            }
        } else {
            ++a;
        }
    }
    for (int i = n / 2 + n % 2; i < n; ++i) {
        while (j < i - (n - i) * d) {
            up += v[j];
            v[j] = 0;
            ++j;
        }
        if (pref[n - 1] - up >= k) {
            up += k;
            int temp = k;
            while (temp != 0) {
                if (v[j] >= temp) {
                    v[j] -= temp;
                    temp = 0;
                } else {
                    temp -= v[j];
                    v[j] = 0;
                    ++j;
                }
            }
        } else {
            ++b;
        }
    }
    cout << max(a, b) << endl;
    return 0;
}
