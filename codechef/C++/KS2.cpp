/* Include Header Files */
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/math/constants/constants.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <regex>
#include <cmath>

/* Define Macros */

#define MOD 1e9+7
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

pint sum_digits(pint num) {
    string n = boost::lexical_cast<string>(num);

    pint sum;

    for (char c : n) {
        sum += c - '0';
    }

    return sum;
}

int main() {
    fastio;

    pint T;
    cin >> T;

    while (T--){
        pint N;
        
        cin >> N;

        vector < pint > round_nos;

        // 19 28 37 46 55 64 73 82 91 109 118 127 136 145 154 163 172 181 190 208 217 226 235 244
        // 253 262 271 280 299 307 316 325 334 343 352 361 370 389 398 406 415 424 433 442 451 460 
        // 479 488 497 505 514 523 532 541 550 569 578 587 596 604 613 622 631 640 659 668 677 686 695 703 712 721 730 749 758 767 776 785 794 802 811 820 839 848 857 866 875 884 893 901 910 929 938 947 956 965 974
        
        string ans = boost::lexical_cast<string>(N);

        pint sum_ = sum_digits(N);

        pint rem = 10 - (sum_%10);

        ans += boost::lexical_cast<string>(rem%10);

        cout << ans << endl;
    }

    return 0;
}