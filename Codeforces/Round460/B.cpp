#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

int digits(int num) {
A.cpp int ans = 0;
A.cpp while(num > 0) {
A.cpp A.cpp ans += num % 10;
A.cpp A.cpp num /= 10;
A.cpp }
A.cpp return ans;
}

int main() {
A.cpp int k;
A.cpp cin >> k;
A.cpp ld ans = 1000000000;
A.cpp int i = 18;
A.cpp while (k > 0) {
A.cpp A.cpp ++i;
A.cpp A.cpp if (digits(i) == 10) {
A.cpp A.cpp A.cpp --k;
A.cpp A.cpp }
A.cpp }
A.cpp cout << i << endl;
}
