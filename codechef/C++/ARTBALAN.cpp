#include <bits/stdc++.h> 
#define pb push_back 
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long ll;
typedef long long int lld;

using namespace std;

#define MAX 1000

vector<lld> V;

int main() {
    fastio

    int T;
    cin >> T;

    while (T--) {

        lld ans = LONG_MAX;

        V.clear();
        for (int i = 0; i < 26 ; i++) {
            V.pb(0);
        }

        // for (lld i: V) {
        //     cout << i << " ";
        // }

        // cout << std::endl;

        string S;
        cin >> S;

        lld N = S.size();

        for (int i = 0 ; i < N; i++) {
            V[S[i]-'A']++;
        }

        sort(V.begin(), V.end());

        // for (lld i: V) {
        //     cout << i << " ";
        // }

        for (int i = 1 ; i < N+1 ; i++) {
            lld curr = N / i;
            if (N%i == 0 && curr <= 26) {
                lld x = 0, y = 0;
                for (int j = 25; j >= 26-curr ; j--) {
                    if (V[j] > i) {
                        x = x + abs(V[j]-i);
                        y = y + abs(V[j]-i);
                    } else if (V[j] < i) {
                        lld z = min(y, i - V[j]);
                        y = y - z;
                        x = x + abs(i-V[j]-z);
                    }
                }
                ans = min(x, ans);
            }
        }
        cout << ans << endl;
    }

    return 0;
}