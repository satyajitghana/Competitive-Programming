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
#define mp make_pair
#define cint cpp_int
#define fin(ii, nn) for (int i = ii; i < nn; i++)

using namespace boost::multiprecision;
using namespace std;

int main() {
    fastio

    int T;
    cin >> T;
    while (T--) {
        cint N, M, K;
        cin >> N >> M >> K;
        vector<pair <cint, cint> > p;
        map<pair<cint, cint>, cint> m;
        for (int i = 0 ; i < K ; i++) {
            cint r, c;
            cin >> r >> c;
            p.pb(mp(r, c));
            m.insert(mp(mp(r, c), 4));
        }

        sort(p.begin(), p.end());

        // for (pair <int, int> e: p) {
        //     cout << e.first << " " << e.second << endl;
        // }

        for (pair<pair<cint, cint>, cint > e : m) {

            cint X = e.first.first;
            cint Y = e.first.second;

            // cout << "#" << X << " " << Y << "#" << endl;

            auto ir1 = m.find(mp(X, Y-1));
            auto ir2 = m.find(mp(X, Y+1));
            auto ir3 = m.find(mp(X-1, Y));
            auto ir4 = m.find(mp(X+1, Y));

            if (ir1 != m.end()) {
                // cout << "*" << X << " " << Y-1 << "*";
                //m[mp(X, Y-1)] -= 1;
                m[mp(X, Y)] -= 1;
            }

            if (ir2 != m.end()) {
                // cout << "*" << X << " " << Y+1 << "*";
                //m[mp(X, Y+1)] -= 1;
                m[mp(X, Y)] -= 1;
            }

            if (ir3 != m.end()) {
                // cout << "*" << X-1 << " " << Y << "*";
                //m[mp(X-1, Y)] -= 1;
                m[mp(X, Y)] -= 1;
            }

            if (ir4 != m.end()) {
                // cout << "*" << X+1 << " " << Y << "*";
                //m[mp(X+1, Y)] -= 1;
                m[mp(X, Y)] -= 1;
            }

            // cout << endl;
            // cout << e.first.first << " " << e.first.second << " " << e.second << endl;
        }

        for (pair<pair<cint, cint>, cint > e : m) {
            // cout << e.first.first << " " << e.first.second << " " << e.second << endl;
        }

        cint sum = 0;
        for (pair<pair<cint, cint>, cint > e: m) {
            sum += e.second;
        }

        cout << sum << endl;

        // auto ir = m.find(mp(3, 3));
        // if (ir == m.end()) {
        //     cout << "Not Found" << endl;
        // } else {
        //     cout << "Found" << endl;
        // }
    }

    return 0;
}