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

// #define MOD 1e9+7
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
#define MAXN (lld)(3e5+5)
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
pint p2[MAXN], p24[MAXN], p25[MAXN], fact[MAXN], invp[MAXN], f1[MAXN];
pint MOD = static_cast<cpp_int>(1e9+7);


pint power(pint a, pint b) {
    pint x = 1, y = a;

    while(b) {
        if (ODD(b)) {
            x = (x * y) % MOD;
        }

        y = (y * y) % MOD;

        b >>= 1;
    }

    return x;
}

void pre_compute() {
    fact[0] = 1;
    invp[0] = 1;

    fori(i, 1, MAXN) {
        fact[i] = (fact[i-1] * i) % MOD;
    }

    invp[MAXN-1] = power(fact[MAXN-1], MOD-2);

    for (lld i = MAXN-2; i >= 1 ; i--) {
        invp[i] = (invp[i+1] * (i+1)) % MOD;
    }

    p2[0] = 1;
    p24[0] = 1;
    p25[0] = 1;

    fori (i, 1, MAXN) {
        p2[i] = (p2[i-1] * 2) % MOD;
        p24[i] = (p24[i-1] * 24) % MOD;
        p25[i] = (p25[i-1] * 25) % MOD;
    }
}

pint ncr(lld n, lld r) {
    if (n < r) {
        return 0;
    }

    pint ans = (fact[n] * invp[(n-r)] * invp[r]) % MOD;

    return ans;
}

pint solve(pint N, pint K, pint fixed, pint non_fixed) {
    pint ans = 0;
    f1[0] = 1;

    fori(i, 1, K+1) {
        f1[i] = f1[i-1];

        if (EVEN(i)) {
            f1[i] = (f1[i] + ncr((lld)fixed, i/2) * p25[i/2]) % MOD;
        }
    }

    for (pint x = 0 ; x <= K ; x++) {
        pint r = x + 2 * (non_fixed - x);
        if ( r <= K && non_fixed >= x) {
            pint f2 = ( ncr((lld)non_fixed, (lld)x) * p2[(lld)x] * p24[(lld)non_fixed - (lld)x] ) % MOD;
            ans = ( ans +  f2 * f1[(lld)K - (lld)r] ) % MOD;
        }

    }

    return ans;
}

int main() {
    fastio;
    pre_compute();

    int T;
    cin >> T;

    while (T--) {
        pint N, K;
        cin >> N >> K;

        string S;

        cin >> S;

        pint fixed = 0, non_fixed = 0;

        fori(i, 0, N/2) {
            if (S[i] == S[(lld)N-i-1]) {
                fixed++;
            } else {
                non_fixed++;
            }
        }

        pint ans = solve(N, K, fixed, non_fixed);

        if (ODD(N)) {
            ans += 25 * solve(N, K-1, fixed, non_fixed);
            ans %= MOD;
        }

        cout << ans << endl;
    }

    return 0;
}