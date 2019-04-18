#include <boost/multiprecision/cpp_int.hpp>
#include <bits/stdc++.h>
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace boost::multiprecision;
using namespace std;
#define pb push_back
#define pop pop_back
#define cint cpp_int
#define fin(ii,nn) for(int i = ii ; i < nn ; i++)

int main() {
    int N;
    vector<int> A;
    cin >> N;
    for (int i = 0 ; i < N ; i++) {
        int a;
        cin >> a;
        A.pb(a);
    }
    sort(A.begin(), A.end());
    int sol = A[A.size()-2];
    if (sol == A[A.size()-1]) {
        int ans = 0;
        for (int i = A.size()-3 ; i >= 0 ; i++) {
            if (A[i] != sol) {
                ans = A[i];
                break;
            }
        }

        cout << ans << endl;
    } else {
        cout << sol << endl;
    }
}