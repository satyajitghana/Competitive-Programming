#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

ld eps = 1e-7;

int main() {
	ios_base::sync_with_stdio(false);
	ld R, x1, y1, x2, y2;
	cin >> R >> x1 >> y1 >> x2 >> y2;
	ld to_c = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	ld ans_r = (to_c + R) / 2;
	if (ans_r > R) {
		cout << fixed << setprecision(10) << x1 << " " << y1 << " " << R << endl;
	} else if (to_c > eps) {
		cout << fixed << setprecision(10) << x2 + (x1 - x2) / to_c * ans_r << " " << y2 + (y1 - y2) / to_c * ans_r << " " << ans_r << endl;
	} else {
		cout << fixed << setprecision(10) << x1 + R / 2 << " " << y1 << " " << R / 2 << endl;
	}
	return 0;
}
