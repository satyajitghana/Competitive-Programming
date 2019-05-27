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

#define mod 1e9+7
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
#define MAX (lld)(1e6+5)
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

int A[MAX];

pint query(pint l, pint r) {
    cout << 1 << " " << l << " " << r << endl;

    fflush(stdout);
    pint res;
    cin >> res;

    return res;
}

pint search(pint left, pint right, pint from) {
    pint ans = LLONG_MAX;
    while (left <= right) {
        pint mid = (left + right) / 2;
        pint res = query(from, mid);
        if (res > 0) {
            right = mid - 1;
            ans = min(ans, mid);
            // watch(ans);
        } else {
            left = mid + 1;
        }
    }

    return ans;
}

int main() {
    fastio;

    pint N;
    cin >> N;

    pint l1, r1, l2, r2, left, right, mid, res;
    l1 = r1 = l2 = r2 = LLONG_MAX;

    left = 1; right = N;
	while (left <= right) {
	    mid = (left+right)/2;
	    if (query(1, mid) < 2) {
            left = mid+1;
	    } else {
            right = mid-1;
            l2 = min(l2, mid);
	    }
	}

    r2 = left = l2; right = N;
    while (left <= right) {
        mid = (left+right)/2;
        if (query(mid, N) > 0) {
            left = mid+1;
            r2 = max(r2, mid);
        } else {
            right = mid-1;
        }
    }

    left = 1; right = l2-1;
    while (left <= right) {
        mid = (left+right)/2;
        if (query(1, mid) > 0) {
            right = mid-1;
            l1 = min(l1, mid);
        } else {
            left = mid+1;
        }
    }

    r1 = left = l1; right = l2-1;
    while (left <= right) {
        mid = (left+right)/2;
        if (query(mid, l2-1) > 0) {
            left = mid+1;
            r1 = max(r1, mid);
        } else {
            right = mid-1;
        }
    }

    cout << 2 << " " << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
    fflush(stdout); 

    return 0;
}