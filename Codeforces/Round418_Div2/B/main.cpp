#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >>  b[i];
    }
    vector<int> p(n);
    int c[2]{-1, -1};
    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            c[j] = i;
            ++j;
        }
    }
    if (j == 1) {
        vector<bool> temp(n, true);
        for (int i = 0; i < n; ++i) {
            if (i != c[0]) {
                temp[a[i] - 1] = false;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (temp[i]) {
                a[c[0]] = i + 1;
            }
        }
    } else {
        int temp1 = b[c[0]];
        int temp2 = a[c[1]];
        bool ok = (temp1 != temp2);
        for (int i = 0; i < n; ++i) {
            if (i != c[0] && i != c[1]) {
                if (a[i] == temp1 || a[i] == temp2) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) {
            a[c[0]] = b[c[0]];
        } else {
            a[c[1]] = b[c[1]];
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}