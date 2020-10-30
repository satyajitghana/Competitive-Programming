#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const double PI = 3.141592654;

// Problem Statement : https://codeforces.com/contest/1334/problem/B
int main() {
    ios :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    LL t; 
    cin >> t; 

    while (t--) {
        LL n, x; 
        cin >> n >> x; 
        vector<LL> savings(n); 
        for (LL i = 0; i < n; i++) {
            cin >> savings[i]; 
        }
        sort(savings.begin(), savings.end(), greater<LL>()); 
        LL save = 0; 
        LL ans = 0; 
        for (LL i = 0; i < savings.size(); i++) {
            save += savings[i]; 
            if (save >= (i + 1) * x) {
                ans++;    
            } else {
                break; 
            }
        }
        cout << ans << "\n"; 
    }
}