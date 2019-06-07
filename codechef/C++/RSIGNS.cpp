/* Include Header Files */
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/math/constants/constants.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/algorithm/string.hpp>
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <regex>
#include <cmath>

/* Define Macros */

// #define MOD pint(1e9+7)
#define precision 1e2
#define pb push_back
#define pop pop_back
#define mp make_pair
#define pint cpp_int
#define pint_pair pair<pint, pint>
#define pfloat cpp_dec_float<precision>
#define lld long long int
#define CLR(_a, _init) memset(_a, _init, sizeof(_a))
#define ODD(_num) (((_num)&1)==0?(0):(1))
#define EVEN(_num2) (!(((_num2)&1)==0?(0):(1)))
#define MAXN (lld)(1e6+5)
#define fastio ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL)
#define print_pairs(_pairs) for (auto _e : _pairs) { cout << _e.first << " " << _e.second << endl; }
#define fori(_ii, _begin, _end) for (lld _ii = _begin ; _ii < _end ; _ii++)
#define DEBUG "DEBUG------"
#define watch(__x) cout << DEBUG << (#__x) << " : " << (__x) << endl
#define stop_here return 0

using namespace boost::multiprecision;
using namespace std;

template<typename T> inline void SWAP(T &a, T&b) { T temp = b; b = a; a = temp; }

template<typename T> inline T distance(pair<T, T> a, pair<T, T> b) { return min(abs(a.first - b.first), abs(a.second - b.second)); }

template<typename T> bool pair_compare_first(const pair<T, T> &a, const pair<T, T> &b) { return a.first <= b.first; }

template<typename T> bool pair_compare_second(const pair<T, T> &a, const pair<T, T> &b) { return a.second <= b.second; }

template<typename T> inline void print_vec(vector<T> arr, int len) { fori(i, 0, len) { cout << arr[i] << " "; } }
template<typename T> inline void print_arr(T arr[], int len) { fori(i, 0, len) { cout << arr[i] << " "; } }

/* Let the Games Begin */

int A[MAXN];

pint power(pint X, pint Y, pint MOD) {
    pint res = 1;

    X = X % MOD;

    while (Y > 0) {
        if (Y & 1)
            res = (res * X) % MOD;
        
        Y = Y >> 1;
        X = (X * X) % MOD;
    }

    return res;
}

int main() {
    fastio;

    int T;
    cin >> T;

    pint MOD = 1000000000+7;

    while (T--) {
        int K;
        cin >> K;

        pint ans = 1;

        pint two = 2;

        ans = power(two, K-1, MOD);

        ans = (ans * 10) % MOD;

        cout << ans << endl;
    }

    return 0;
}