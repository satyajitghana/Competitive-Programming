#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

int main() {
A.cpp ios_base::sync_with_stdio(false);
A.cpp int n;
A.cpp cin >> n;
A.cpp int k = 0;
A.cpp for (int i = 1; i <= n; ++i) {
A.cpp A.cpp for (int j = i; j <= n; ++j) {
A.cpp A.cpp A.cpp int a = i ^ j;
A.cpp A.cpp A.cpp if (a >= j && a <= n && i + j > a) {
A.cpp A.cpp A.cpp A.cpp ++k;
A.cpp A.cpp A.cpp }
A.cpp A.cpp }
A.cpp }
A.cpp cout << k << endl;
A.cpp return 0;
}
