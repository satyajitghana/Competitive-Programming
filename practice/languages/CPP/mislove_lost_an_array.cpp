#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const double PI = 3.141592654;

// Problem Statement : https://codeforces.com/contest/1204/problem/B

LL calculateMin(int n, int l) {
        LL sum = 1;
        l--;
        n--; 
        LL ele = 1; 
        while (l--) {
                n--; 
                ele <<= 1; 
                sum += ele; 
        }
        while (n--) {
                sum++; 
        }
        return sum; 
}

LL calculateMaxi(int n, int r) {
        LL sum = 1; 
        r--; 
        n--;
        LL power2 = 1; 
        while (r--) {
                n--; 
                power2 <<= 1; 
                sum += power2; 
        }
        while (n--) {
                sum += power2; 
        }
        return sum; 
}

int main() {
        ios :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int n, l, r; 
        cin >> n >> l >> r; 
        LL miniSum = calculateMin(n, l); 
        LL maxiSum = calculateMaxi(n, r); 
        cout << miniSum << " " << maxiSum << endl; 
}