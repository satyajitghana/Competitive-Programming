/* Include Header Files */
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/math/constants/constants.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/algorithm/string.hpp>
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <regex>

/* Define Macros */

#define MOD (int)(1e9+7)
#define precision 1e2
#define pb push_back
// #define pop pop_back
#define mp make_pair
#define pint cpp_int
#define pint_pair pair<pint, pint>
#define pfloat cpp_dec_float<precision>
#define lld long long int
#define llf long double
#define CLR(_a, _init) memset(_a, _init, sizeof(_a))
#define ODD(_num) (((_num)&1)==0?(0):(1))
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
pint MIN[MAXN];
llf DP[MAXN];

int main() {
    fastio;

    int N, K;

    cin >> N >> K;

    fori (i, 0, N) {
        cin >> A[i];
    }

    priority_queue <pair<llf, int > > pq;

    DP[0] = log(A[0]);
    MIN[0] = A[0];
    // priority queue sorts is descending order, we need the smallest value, hence the negative, 0 here is the index
    pq.push({-DP[0], 0});

    for (int i = 1 ; i < N ; i++) {
        while (i - pq.top().second > K) {
            pq.pop();
        }

        DP[i] = DP[pq.top().second] + log(A[i]);
        MIN[i] = (MIN[pq.top().second] * A[i]) % MOD;
        pq.push({-DP[i], i});
    }


    /* solution for N <= 80

    for (int i = 1 ; i < N ; i++) {
        pint minimum = MIN[i-1];
        // int min_i = 0;
        for (int j = i - 2; ((i - j) <= K) && (j >= 0) ; j--) {
            // if (DP[j] < minimum) {
            //     minimum = DP[j];
            //     min_i = j;
            // }
            minimum = min(minimum, MIN[j]);
            // cout << "(" << i << ", " << j << ")" << " ";
        }
        // watch(minimum);
        // MIN[i] = (MIN[min_i] * A[i]) % MOD;
        // DP[i] = DP[min_i] + log(A[i]);
        // cout << endl;

        MIN[i] = minimum * A[i];
    } */

    cout << MIN[N-1] % MOD << endl;

    return 0;
}