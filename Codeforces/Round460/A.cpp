#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

int main() {
int n, m;
cin >> n >> m;
ld ans = 1000000000;
for (int i = 0; i < n; ++i) {
ld a, b;
cin >> a >> b;
ans = min(ans, a / b * m);
}
cout << fixed << setprecision(10) << ans << endl;
}
