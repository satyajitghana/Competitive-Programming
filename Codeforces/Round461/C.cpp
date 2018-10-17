#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

int main() {
ios_base::sync_with_stdio(false);
ll x, y;
cin >> x >> y;
for (int i = 1; i <= min((ll)10000000, y); ++i) {
if (x % i != i - 1) {
cout << Non;
return 0;
}
}
cout << Yesn;
return 0;
}
