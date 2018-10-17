#include <bits/stdc++.h>

using namespace std;

vector<string> rotate90(const vector<string>& in) {
    int n = in.size();
    vector<string> ans(n);
    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; j >= 0; --j) {
            ans[i] += in[j][i];
        }
    }
    return ans;
}

vector<string> fliphor(const vector<string>& in) {
    int n = in.size();
    vector<string> ans(n);
    for (int i = 0; i < n; ++i) {
        ans[i] = in[n - i - 1];
    }
    return ans;
}

vector<string> flipver(const vector<string> &in) {
    int n = in.size();
    vector<string> ans(n);
    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; j >= 0; --j) {
            ans[i] += in[i][j];
        }
    }
    return ans;
}

bool equal(const vector<string> &a, const vector<string> &b) {
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<string> a[4];
    vector<string> b(n);
    a[0].resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[0][i];
    }
    a[1] = fliphor(a[0]);
    a[2] = flipver(a[0]);
    a[3] = flipver(a[1]);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            a[i] = rotate90(a[i]);
            if (equal(a[i], b)) {
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No\n";
    return 0;
}
