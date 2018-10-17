#include <iostream>

using namespace std;

int get_num(char a) {
    return a == 118 ? 0 : (a == 60 ? 1 : (a == 94 ? 2 : 3));
}

int main() {
    char a;
    cin >> a;
    int f = get_num(a);
    cin >> a;
    int l = get_num(a);
    int n;
    cin >> n;
    int ans = 0;
    if ((f + n) % 4 == l) {
        ++ans;
    }
    if ((l + n) % 4 == f) {
        ans += 2;
    }
    cout << (ans == 1 ? "cw" : (ans == 2 ? "ccw" : "undefined")) << endl;
    return 0;
}