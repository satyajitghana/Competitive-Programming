#include <bits/stdc++.h>
#define mod 1000000007
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define pb push_back
#define pop pop_back
#define mp make_pair
#define cint cpp_int
#define fin(ii, nn) for (int i = ii; i < nn; i++)

using namespace std;

int main() {
    fastio
    int N, M;
    cin >> N >> M;
    int A[1000][1000];
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < M ; j++) {
            cin >> A[i][j];
        }
    }
    int Q;
    cin >> Q;
    int B[1000];
    int cnt;
    while (Q--) {
        cnt = 0;

        for (int i = 0 ; i < M ; i++) {
            cin >> B[i];
        }

        for (int i = 0 ; i < N ; i++) {
            bool found = true;
            for (int j = 0 ; j < M ; j++) {
                if (B[j] != -1 && A[i][j] != B[j]) {
                    found = false;
                    break;
                }
            }

            if (found) {
                cnt++;
            }
        }

        cout << cnt << endl;
    }
    return 0;
}