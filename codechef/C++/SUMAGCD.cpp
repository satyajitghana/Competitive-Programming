/* Include Header Files */
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/math/constants/constants.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/range/adaptor/reversed.hpp>
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
#define stop_here std::cout << std::endl; return 0

using namespace boost::multiprecision;
using namespace std;

template<typename T> inline void SWAP(T &a, T&b) { T temp = b; b = a; a = temp; }

template<typename T> inline T distance(pair<T, T> a, pair<T, T> b) { return min(abs(a.first - b.first), abs(a.second - b.second)); }

template<typename T> bool pair_compare_first(const pair<T, T> &a, const pair<T, T> &b) { return a.first <= b.first; }

template<typename T> bool pair_compare_second(const pair<T, T> &a, const pair<T, T> &b) { return a.second <= b.second; }

template<typename T> inline void print_vec(vector<T> arr, int len) { fori(i, 0, len) { cout << arr[i] << " "; } }
template<typename T> inline void print_arr(T arr[], int len) { fori(i, 0, len) { cout << arr[i] << " "; } }

/* Let the Games Begin */

lld A[MAXN];
lld X[MAXN];
lld MAX = LLONG_MIN;
vector <lld> to_check;

lld gcd(lld a, lld b) {
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

lld findGCD(vector <lld> arr) {
    lld result = arr[0];

    for (int i = 1 ; i < arr.size() ; i++) {
        result = gcd(arr[i], result);
    }

    return result;
}

lld findGCD(lld arr[], lld n, lld comp) {
    int i = 0;
    while (X[i] != comp) i++;
    lld result = arr[i];
    for (i = i+1 ; i < n ; i++) {
        if (X[i] == comp)
            result = gcd(arr[i], result);
    }

    return result;
}

void findSolution(lld arr[], lld n, lld idx) {
    if (idx < n) {
        X[idx] = 1;

        // print_arr(X, n);
        // cout << endl;

        lld GCD1 = findGCD(arr, n, 1);
        lld GCD2 = findGCD(arr, n, 0);

        // watch(GCD1);
        // watch(GCD2);

        // cout << DEBUG << endl;

        lld sum =  GCD1 + GCD2;

        if (sum > MAX) {
            MAX = sum;
            findSolution(arr, n, idx+1);
        } else {
            X[idx] = 0;
            findSolution(arr, n, idx+1);
        }
    }
}

lld solve(lld arr[], lld n) {

    for (int i = 0 ; i < n ; i++) {
        X[i] = 1;
        findSolution(arr, n, 0);
    }

    return MAX;
}

int main() {
    fastio;

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        set <lld> choices;

        MAX = LLONG_MIN;

        for (int i = 0 ; i < N ; i++) {
            cin >> A[i];
            X[i] = 0;

            if (A[i] > MAX) {
                MAX = A[i];
            }
        }

        for (int i = 0 ; i < N ; i++) {
            // if (A[i] > 2 * sqrt(MAX))
            if (A[i] > MAX * 0.5)
                choices.insert(A[i]);
        }

        MAX = LLONG_MIN;

        set <lld> new_options;

        int c = 0;

        for (auto e : boost::adaptors::reverse(choices)) {
            new_options.insert(e);
            c++;

            if (c >= 3)
                break;
        }

        for (auto curr: boost::adaptors::reverse(new_options)) {
            // cout << e << " ";

            for (int i = 0 ; i < N ; i++) {
                X[i] = 0;
            }

            // to_check.clear();

            for (int i = 0 ; i < N ; i++) {
                if (A[i] == curr) {
                    X[i] = 1;
                }
                // if (A[i] != curr) {
                //     to_check.push_back(A[i]);
                // }
            }

            lld currMAX = curr + findGCD(A, N, 0);
            // lld currMAX = curr + findGCD(to_check);

            if (currMAX > MAX) {
                MAX = currMAX;
            }
        }

        // lld cnt = 0;

        // for (int i = 0 ; i < N ; i++) {
        //     if (A[i] == MAX) {
        //         X[i] = 1;
        //         cnt ++;
        //     }
        // }

        // lld ans = findGCD(A, N, 0) + MAX;

        // if (cnt == N) {
        //     ans = MAX + MAX;
        // }

        // MAX = LLONG_MIN;

        // for (int j = 0 ; j < N ; j++) {
        //     lld curr = A[j];

        //     for (int i = 0 ; i < N ; i++) {
        //         X[i] = 0;
        //     }

        //     for (int i = 0 ; i < N ; i++) {
        //         if (A[i] == curr) {
        //             X[i] = 1;
        //         }
        //     }

        //     lld currMAX = curr + findGCD(A, N, 0);

        //     if (currMAX > MAX) {
        //         MAX = currMAX;
        //     }
        // }

        lld check = A[0];
        lld cnt = 1;

        for (int i = 1 ; i < N ; i++) {
            if (A[i] == check)
                cnt++;
        }

        if (cnt == N)
            MAX = 2 * A[0];
        
        cout << MAX << endl;

        // cout << solve(A, N) << endl;
    }

    return 0;
}