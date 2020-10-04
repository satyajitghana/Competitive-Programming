#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const double PI = 3.141592654;

// Problem Statement : https://codeforces.com/contest/1206/problem/B
int main() {
        int n; 
        cin >> n; 
        LL ans = 0L; 
        int posOnes = 0; 
        int negOnes = 0; 
        int zeroes = 0; 
        for (int i = 0; i < n; i++) {
                LL e; 
                cin >> e;
                if (e == 0) {
                        zeroes++; 
                        continue;
                } else if (e > 0) {
                        ans += (e - 1); 
                        posOnes++; 
                } else {
                        ans += (-1 - (e)); 
                        negOnes++; 
                }
        }
        if (negOnes % 2 == 0) {
                cout << ans + zeroes << endl; 
        } else {
                if (zeroes) {
                        ans += 1;
                        zeroes--; 
                } else {
                        ans += 2; 
                }
                cout << ans + zeroes << endl; 
        }
}