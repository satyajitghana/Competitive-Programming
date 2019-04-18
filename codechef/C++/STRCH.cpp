#include <boost/multiprecision/cpp_int.hpp>
#include <boost/algorithm/string.hpp>
#include <bits/stdc++.h>
#define mod 1000000007
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define pb push_back
#define pop pop_back
#define cint cpp_int
#define fin(ii, nn) for (int i = ii; i < nn; i++)

using namespace boost::multiprecision;
using namespace std;

int main() {
    fastio
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        string S;
        cin >> S;
        string X;
        cin >> X;

        // cout << N << " " << S << " " << X << endl;
        cint len = S.size();
        cint ans = (len * (len + 1)) / 2;
        vector<string> results;
        vector<cint> counts;
        boost::split(results, S, boost::is_any_of(X));
        for (string s: results) {
            // cout << s << endl;
            counts.pb(s.size());
        }

        for (cint e: counts) {
            ans -= (e * (e + 1)) / 2;
        }

        cout << ans << endl;
    }
    return 0;
}