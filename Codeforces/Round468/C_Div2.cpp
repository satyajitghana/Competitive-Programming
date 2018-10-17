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
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v) {
        cin >> i;
    }
    sort(v.begin(), v.end());
    int mi = v[0];
    int ma = v[v.size() - 1];
    vector<int> w(3);
    for (int i : v) {
        w[i - mi]++;
    }
    int k = 0;
    vector<int> ans;
    while (w[0] > w[2]) {
        ans.push_back(mi);
        --w[0];
        ++k;
    }
    while (w[0] < w[2]) {
        ans.push_back(ma);
        --w[2];
        ++k;
    }
    if (w[1] < 2 * w[0] || mi + 2 != ma) {
        k += w[1];
        w[1] += 2 * w[0];
        while (w[1]-- > 0) {
            ans.push_back(mi + 1);
        }
    } else {
        if (w[1] % 2 != 0) {
            ans.push_back(mi + 1);
            ++k;
        }
        k += w[0] * 2;
        w[1] /= 2;
        w[1] += w[0];
        while (w[1]-- > 0) {
            ans.push_back(mi);
            ans.push_back(ma);
        }
    }
    cout << k << endl;
    for (int i : ans) {
        cout << i <<  ;
    }
    cout << endl;
    return 0;
}
