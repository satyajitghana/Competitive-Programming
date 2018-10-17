#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y; cin.ignore();
    int p = 1;
    vector<bool> v;
    int f;
    while (p <= n) {
        int c = 0;
        for (int i = 1; i <= n; ++i) {
            if ((i ^ p) > i) {
                ++c;
            }
        }
        cout << "? " << c;
        for (int i = 1; i <= n; ++i) {
            if ((i ^ p) > i) {
                cout << " " << i;
            }
        }
        cout << endl;
        cin >> c; cin.ignore();
        if (c == 0 || c == x) {
            v.push_back(true);
        } else {
            v.push_back(false);
            f = p;
        }
        p *= 2;
    }
    vector<int> temp;
    for (int i = 1; i <= n; ++i) {
        if ((i ^ f) > i) {
            temp.push_back(i);
        }
    }
    while (temp.size() > 1) {
        cout << "? " << temp.size() / 2;
        for (int i = 0; i < temp.size() / 2; ++i) {
            cout << " " << temp[i];
        }
        cout << endl;
        int c;
        cin >> c; cin.ignore();
        if (c == 0 || c == x) {
            temp.erase(temp.begin(), temp.begin() + temp.size() / 2);
        } else {
            temp.erase(temp.begin() + temp.size() / 2, temp.end());
        }
    }
    int first = temp[0];
    p = 1;
    int second = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] ^ ((first ^ p) > first)) {
            second += p;
        }
        p *= 2;
    }
    cout << "! " << first << " " << second << endl;
    return 0;
}