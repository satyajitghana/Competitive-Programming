#include <boost/multiprecision/cpp_int.hpp>
#include <bits/stdc++.h>
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace boost::multiprecision;
using namespace std;
#define pb push_back
#define cint cpp_int
#define fin(ii,nn) for(int i = ii ; i < nn ; i++)

using namespace std;

int main() {
    fastio

    int N, Q, D;
    D = 0;
    cin >> N >> Q;
    vector<int> A;
    for (int i = 0 ; i < N ; i++) {
        int t; cin >> t;
        A.pb(t);
        D = D ^ A[i];
    }
    A[N] = D;

    // cout << D << endl;

    vector<int> DP(100005);
    DP[0] = A[0];
    DP[1] = DP[0] ^ A[1];
    for (int i = 1 ; i <= N ; i++) {
        DP[i+1] = DP[i] ^ A[i+1];
    }

    for (int i = 0 ; i < Q ; i++) {
        int K;
        cin >> K;
        cout << DP[(K-1)%(N+1)] << endl;
    }

    // for (int i = 0 ; i <= N ; i++)
    //     cout << DP[i] << " ";
}