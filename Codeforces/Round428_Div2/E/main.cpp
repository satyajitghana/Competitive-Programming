#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n;
    double kk;
    cin >> n >> kk;
    vector<vector<int>> v(n, vector<int> (n));
    for (vector<int>& i : v) {
        for (int& j : i) {
            cin >> j;
        }
    }
    int n1 = n / 2 + n % 2;
    int l = 1;
    for (int i = 0; i < n1; ++i) {
        l *= 2;
    }
    vector<int> ans1(l);
    double ans = 0;
    for (int i = 0; i < l; ++i) {
        int temp = 1;
        vector<int> click;
        int k = 0;
        for (int j = 0; j < n1; ++j) {
            if ((i ^ temp) < i) {
                click.push_back(j);
                ++k;
            }
            temp *= 2;
        }
        bool is_click = true;
        for (int j = 0; j < click.size() && is_click; ++j) {
            for (int z = j + 1; z < click.size() && is_click; ++z) {
                if (!v[click[j]][click[z]]) {
                    is_click = false;
                }
            }
        }
        if (is_click) {
            ans1[i] = k;
            ans = max(ans, double(k));
        }
    }
    for (int i = 0; i < l; ++i) {
        for (int j = 1; i + j < l; j *= 2) {
            if ((i ^ j) > i) {
                ans1[i + j] = max(ans1[i + j], ans1[i]);
            }
        }
    }
    int l2 = 1;
    for (int i = n1; i < n; ++i) {
        l2 *= 2;
    }
    for (int i = 0; i < l2; ++i) {
        int temp = 1;
        vector<int> click;
        int k = 0;
        for (int j = n1; j < n; ++j) {
            if ((i ^ temp) < i) {
                click.push_back(j);
                ++k;
            }
            temp *= 2;
        }
        bool is_click = true;
        for (int j = 0; j < click.size() && is_click; ++j) {
            for (int z = j + 1; z < click.size() && is_click; ++z) {
                if (!v[click[j]][click[z]]) {
                    is_click = false;
                }
            }
        }
        if (is_click) {
            vector<bool> click2(n1, true);
            for (int j = 0; j < click.size(); ++j) {
                for (int z = 0; z < n1; ++z) {
                    if (!v[click[j]][z]) {
                        click2[z] = false;
                    }
                }
            }
            temp = 1;
            int lll = 0;
            for (int j = 0; j < n1; ++j) {
                if (click2[j]) {
                    lll += temp;
                }
                temp *= 2;
            }
            ans = max(ans, double(k + ans1[lll]));
        }
    }
    cout << setprecision(10) << kk * kk * (ans - 1) / 2 / ans << endl;
    return 0;
}