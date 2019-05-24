#include <boost/multiprecision/cpp_int.hpp>
#include <boost/math/constants/constants.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/algorithm/string.hpp>
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <regex>

#define mod 1000000007
#define precision 100
#define pb push_back
#define pop pop_back
#define mp make_pair
#define pint cpp_int
#define pint_pair pair<pint, pint>
#define pfloat cpp_dec_float<precision>
#define fin(ii, nn) for (int i = ii; i < nn; i++)
#define lld long long int
#define CLR(x, y) memset(x, y, sizeof(x))
#define ODD(x) (((x)&1)==0?(0):(1))
#define MAX 1000000+5
#define fastio ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL)
#define print_pairs(_pairs) for (auto _e : _pairs) { cout << _e.first << " " << _e.second << endl; }

using namespace boost::multiprecision;
using namespace std;

#define pair_compare_first [](const pair<pint, pint> &a, const pair<pint, pint> &b) -> bool { return (a.first <= b.first); }
#define pair_compare_second [](const pair<pint, pint> &a, const pair<pint, pint> &b) -> bool { return (a.second <= b.second); }

pint distance(pair<pint, pint> a, pair<pint, pint> b) {
    return min(abs(a.first-b.first), abs(a.second-b.second));
}

int main() {
    fastio;

    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        vector<pair<pint, pint> > C;
        pint ans = numeric_limits<lld>::max();

        for (int i = 0 ; i < N ; i++) {
            pint X, Y; cin >> X >> Y;
            C.pb({X, Y});

            X = C[i].first - C[i].second;
            Y = C[i].first + C[i].second;

            C[i].first = X;
            C[i].second = Y;
        }

        // cout << endl << "*******" << endl;
        // print_pairs(C);
        // cout << endl;

        sort(C.begin(), C.end(), pair_compare_first);

        for (int i = 0 ; i < N-1 ; i++) {
            ans = min(ans, distance(C[i], C[i+1]));
        }

        // cout << "********" << endl;
		// print_pairs(C);
		// cout << endl;

        // cout << ans << endl;

        sort(C.begin(), C.end(), pair_compare_second);

        for (int i = 0 ; i < N-1 ; i++) {
            ans = min(ans, distance(C[i], C[i+1]));
        }

        // cout << "********" << endl;
		// print_pairs(C);
		// cout << endl;

        // cout << ans << endl;

        long double result = static_cast<long double>(ans) / 2.0;

        // cout << ans << endl;

        cout << fixed << setprecision(numeric_limits<long double>::max_digits10) << result << endl;
    }

    return 0;
}