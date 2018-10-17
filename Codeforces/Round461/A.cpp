#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

int main() {
ios_base::sync_with_stdio(false);
int x, y;
cin >> x >> y;
if ((x + y) % 2 == 0) {
cout << Non;
} else if (x + 1 < y) {
cout << Non;
} else if (x >= 1 && y == 1) {
cout << Non;
} else if (y == 0) {
cout << Non;
} else {
cout << Yesn;
}
return 0;
}
