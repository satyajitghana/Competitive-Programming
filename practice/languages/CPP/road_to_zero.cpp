#include <bits/stdc++.h>
using namespace std;
using LL = long long;

// Problem Statement : https://codeforces.com/contest/1342/problem/A
int main() {
      ios :: sync_with_stdio(false);
      cin.tie(nullptr) ;
      cout.tie(nullptr) ;

      long long int t; 
      cin >> t;
       
      while (t--) {
            long long int x, y; 
            cin >> x >> y; 
            long long int a, b; 
            cin >> a >> b; 

            if (2 * a < b) {
                  cout << a * (abs(x) + abs(y)) << endl; 
            } else {
                  if ((x <= 0 and y >= 0) or (x >= 0 and y <= 0)) {
                        cout << a * (abs(x) + abs(y)) << endl; 
                  } else {
                        cout << b * min(abs(x), abs(y)) + a * (abs(x - y)) << endl; 
                  }
            }
      }
}