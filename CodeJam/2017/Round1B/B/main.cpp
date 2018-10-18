#include <iostream>
#include <vector>

using namespace std;

void out(int test, string ans) {
    cout << "Case #" << test << ": ";
    if (ans == "-1") {
        cout << "IMPOSSIBLE";
    } else {
        cout << ans;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        int n, r, o, y, g, b, v;
        cin >> n >> r >> o >> y >> g >> b >> v;
        if (o >= b && o != 0) {
            if (o + b == n) {
                string temp = "";
                while (o-- > 0) {
                    temp += "OB";
                }
                out(test, temp);
                continue;
            }
            out(test, "-1");
            continue;
        }
        if (g >= r && g != 0) {
            if (g + r == n) {
                string temp = "";
                while (g-- > 0) {
                    temp += "GR";
                }
                out(test, temp);
                continue;
            }
            out(test, "-1");
            continue;
        }
        if (v >= y && v != 0) {
            if (v + y == n) {
                string temp = "";
                while (v-- > 0) {
                    temp += "VY";
                }
                out(test, temp);
                continue;
            }
            out(test, "-1");
            continue;
        }
        b -= o;
        r -= g;
        y -= v;
        vector<string> B(b, "B");
        vector<string> R(r, "R");
        vector<string> Y(y, "Y");
        --r;
        --y;
        --b;
        if (o != 0) {
            while (o-- > 0) {
                B[b] += "OB";
            }
        }
        if (g != 0) {
            while (g-- > 0) {
                R[r] += "GR";
            }
        }
        if (v != 0) {
            while (v-- > 0) {
                Y[y] += "VY";
            }
        }
        string ans = "";
        if (r > y && r > b) {
            ans += R[r];
            --r;
        } else if (b > y) {
            ans += B[b];
            --b;
        } else {
            ans += Y[y];
            --y;
        }
        n = 0;
        while (r >= 0 || y >= 0 || b >= 0) {
            if (ans[n] == 'R') {
                if (y > b) {
                    if (y == -1) {
                        break;
                    }
                    ans += Y[y];
                    --y;
                } else if (b > y) {
                    if (b == -1) {
                        break;
                    }
                    ans += B[b];
                    --b;
                } else if (ans[0] == 'Y') {
                    if (y == -1) {
                        break;
                    }
                    ans += Y[y];
                    --y;
                } else {
                    if (b == -1) {
                        break;
                    }
                    ans += B[b];
                    --b;
                }
            } else if (ans[n] == 'B') {
                if (y > r) {
                    if (y == -1) {
                        break;
                    }
                    ans += Y[y];
                    --y;
                } else if (r > y) {
                    if (r == -1) {
                        break;
                    }
                    ans += R[r];
                    --r;
                } else if (ans[0] == 'Y') {
                    if (y == -1) {
                        break;
                    }
                    ans += Y[y];
                    --y;
                } else {
                    if (r == -1) {
                        break;
                    }
                    ans += R[r];
                    --r;
                }
            } else {
                if (b > r) {
                    if (b == -1) {
                        break;
                    }
                    ans += B[b];
                    --b;
                } else if (r > y) {
                    if (r == -1) {
                        break;
                    }
                    ans += R[r];
                    --r;
                } else if (ans[0] == 'B') {
                    if (b == -1) {
                        break;
                    }
                    ans += B[b];
                    --b;
                } else {
                    if (r == -1) {
                        break;
                    }
                    ans += R[r];
                    --r;
                }
            }
            n = ans.length() - 1;
        }
        if (b != -1 || r != -1 || y != -1 || ans[0] == ans[n]) {
            out(test, "-1");
            continue;
        }
        out(test, ans);
    }
    return 0;
}