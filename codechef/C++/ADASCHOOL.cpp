#include <bits/stdc++.h> 
#define pb push_back 
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main() {
    fastio

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        if (N == M) {
            if (N%2 == 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }
}