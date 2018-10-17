#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
	ios_base::sync_with_stdio(false);
	vector<ld> v;
	int q;
	cin >> q;
	int a;
	cin >> a >> a;
	--q;
	v.push_back(a);
	int j = 0;
	ld sum = a;
	int k = 1;
	while (q--) {
		cin >> a;
		if (a == 1) {
			cin >> a;
			sum -= v[v.size() - 1];
			sum += a;
			v.push_back(a);
			while (j + 1 < v.size() && v[j] < sum / k) {
				sum += v[j];
				++j;
				++k;
			}
		} else {
			cout << fixed << setprecision(10) << v[v.size() - 1] - sum / k << endl;
		}
	} 
	return 0;
}
