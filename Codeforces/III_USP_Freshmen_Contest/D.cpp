#include <bits/stdc++.h>

using namespace std;

int main() {
  long long int n;
  cin >> n;
  long long int a[n];
  long long int sum1 = 0;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    sum1 += a[i];
  }
  long long int sum = 0;
  for (long long int i = 0; i < n; i++) {
    sum += (sum1 - a[i]) * a[i];
  }

  cout << sum / 2;
}
