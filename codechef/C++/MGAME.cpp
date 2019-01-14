#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    long long N, P;
    cin >> T;
    while (T--) {
        cin >> N >> P;
        long long ans = 0l;
        
        if (N == 1 || N == 2) {
            ans = P*P*P;
        } else {
            ans = ans + (P - (N-1)/2)*(P - (N-1)/2);
            ans = ans + (P-N)*(P - (N-1)/2);
            ans = ans + (P-N)*(P-N);
        }

        cout << ans << endl;
    }
}