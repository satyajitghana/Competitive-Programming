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
#define MAXN (lld)(10005)
// #define MAXN 20
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

bool pair_compare_first(const pair<int, int> &a, const pair<int, int> &b) { return a.first >= b.first; }

template<typename T> bool pair_compare_second(const pair<T, T> &a, const pair<T, T> &b) { return a.second <= b.second; }

template<typename T> inline void print_vec(vector<T> arr, int len) { fori(i, 0, len) { cout << arr[i] << " "; } }
template<typename T> inline void print_arr(T arr[], int len) { fori(i, 0, len) { cout << arr[i] << " "; } }

/* Let the Games Begin */

// int A[MAXN];
// int B[MAXN];

// vector < pair <lld, lld> > xors(MAXN);
// pair <int, int> xors[MAXN];

pint A[MAXN];
pint B[MAXN];

int main() {
    fastio;

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        pint MAX = 0;

        fori(i, 0, N) {
            cin >> A[i];
            MAX += A[i];
        }

        // watch(MAX);

        pint K, X;

        cin >> K >> X;

        if (X == 0) {
            cout << MAX << endl;
            continue;
        }

        lld pot = 0;

        fori (i, 0, N) {
            B[i] = (A[i] xor X) - A[i];
            if (B[i] > 0)
                pot++;
        }

        pint buffer = N - pot;

        sort(B, B + N, greater<pint>());

        // watch(pot);
        // print_arr(B, N);
        // cout << endl;

        if (K == N) {
            // if K == N then either XOR all the elements or NONE of them,,
            pint sum = 0;
            for (int i = 0; i < N ; i++) {
                sum += B[i];
            }

            if (sum > 0) {
                MAX += sum;
            }

            cout << MAX << endl;
        } else if (ODD(K) or EVEN(pot)) {
            for (int i = 0 ; i < pot ; i++) {
                MAX += B[i];
            }
            cout << MAX << endl;
        } else {

            for (int i = 0 ; i < pot ; i++) {
                MAX += B[i];
            }

            pint diff = 0;
            pint sum = 0;

            for (int i = 0 ; i < N ; i++) {
                diff = abs( (A[i] xor X) - A[i]);
                sum = max(sum, MAX - diff);
            }

            cout << sum << endl;

            // pint sum = MAX;
            // for (int i = 0 ; i < pot-1 ; i++) {
            //     sum += B[i];
            // }

            // if (B[pot-1] + B[pot] > 0) {
            //     sum += B[pot-1] + B[pot];
            // }

            // MAX = max(MAX, sum);
            
            // cout << MAX << endl;
        }
        // } else {
        //     lld sum = MAX;
            
        //     for (int i = 0 ; i < pot - pot%K ; i++) {
        //         sum += B[i];
        //     }

        //     lld sum2 = 0;
        //     if ((N - pot - pot%K) >= K) {
        //         for (int i = (pot-pot%K) ; i < K ; i++)
        //             sum2 += B[i];
        //     }

        //     if (sum2 > 0)
        //         sum += sum2;

        //     MAX = max(MAX, sum);

        //     cout << MAX << endl;

            // lld newK = K - buffer;
            // lld newPot = pot - pot%newK;

            // lld sum = MAX;
            
            // if (EVEN(newPot/newK)) {
            //     for (int i = 0 ; i < newPot ; i++) {
            //         sum += B[i];
            //     }

            //     for (int i = newPot ; i < newK ; i++) {

            //     }
            // }
        // } 

        // lld pot = 0;
        // lld zeros = 0;

        // lld TEST[MAXN] = {5, 4, 3, 2, 1, 0, -2, -3};

        // fori(i, 0, N) {
        //     B[i] = (A[i] xor X) - A[i];
        //     // B[i] = TEST[i];
        //     if (B[i] > 0) {
        //         pot++;
        //     }
        //     if (B[i] == 0) {
        //         zeros++;
        //     }
        // }

        // lld oldK = K;

        // K = (K - zeros > 0) ? K - zeros : 1;

        // lld buffer = N - pot - zeros;

        // sort(B, B + N, greater<lld>());

        // int k = 0;

        // while (B[k] >= 0 && k < N) k++;

        // int i = 0;

        // lld sum = 0;

        // lld times = pot / K;

        // while (times--) {
        //     for (int o = 0 ; o < K ; o++, i++) {
        //         sum += B[i];
        //     }
        // }

        // for (i = 0 ; i < pot ; i++) {
        //     for (int j = 0 ; j < K and i < pot; j++, i++) {
        //         sum += B[i];
        //     }
        // }

        // watch(sum);

        // MAX += sum;

        // lld remaining = pot % K;
        // lld negs = N - k;

        // if (remaining) {

        //     lld sum2 = 0;

        //     if (negs + remaining >= K) {
        //         for (; i < pot ; i++) {
        //             sum2 += B[i];
        //         }

        //         for (int j = 0 ; j < K - remaining ; j++) {
        //             sum2 += B[k+j];
        //         }
        //     }

            // watch(sum2);

        //     if (sum2 > 0) {
        //         MAX += sum2;
        //     }
        // }

        // cout << MAX << endl;

        // lld newK = (K - buffer > 0) ? (K - buffer) : 1;

        // lld newN = pot - pot%newK;

        // lld h = pot/newK;

        // if (ODD(h)) {
        //     newN -= newK;
        // }


        // for (int i = 0 ; i < newN ; i++) {
        //     MAX += B[i];
        // }

        // cout << MAX << endl;

        // sort(A, A + N);

        // watch(MAX);

        // cout << "B : " << endl;
        // print_arr(B, N);
        // cout << endl;
        // cout << "A : " << endl;
        // print_arr(A, N);
        // cout << endl;

        // for (int i = 0 ; i < N ;) {
        //     if (i+K < N) {
        //         lld sum = 0;
        //         for (int j = 0 ; j < K ; j++, i++) {
        //             sum += B[i];
        //         }
        //         if (sum > 0) {
        //             MAX += sum;
        //         }
        //     } else {
        //         break;
        //     }
        // }

        // cout << MAX << endl;

        // lld MAX2 = 0;

        // lld tol = N -  N % K;

        // for (int i = 0 ; i < tol ;) {
        //     lld sum1 = 0, sum2 = 0;
        //     for (int j = 0 ; j < K and i < tol; j++, i++) {
        //         sum1 += A[i];
        //         sum2 += B[i] + A[i];
        //     }

        //     MAX2 += max(sum1, sum2);
        // }

        // cout << max(MAX, MAX2) << endl;

        // fori(i, 0, N) {
        //     cout << "A[" << i << "] = "  << A[i] <<  " B[" << i << "] = "  << B[i]<< endl;
        // }

        // stop_here;

        // the input A[i] = 0 or 1, the xor element X = 0 or 1

        // if (X == 0) {
        //     cout << MAX << endl;
        // } else {
        //     int cntzero = 0;

        //     for (int i = 0 ; i < N ; i++) {
        //         if (A[i] == 0) {
        //             cntzero++;
        //         }
        //     }

        //     int changes = cntzero / K;
        //     int remaining = cntzero%K;

        //     int newMAX = MAX + changes * K;

        //     if (remaining > K/2) {
        //         newMAX += remaining - (K - remaining);
        //     }

        //     cout << newMAX << endl;
        // }

        // for (int i = 0 ; i < N ; i++) {
        //     // xors.push_back({ ( (A[i] xor X) - A[i]), i});
        //     xors[i] = make_pair(( (A[i] xor X) - A[i]), i);
        // }

        // sort(xors, xors + N, pair_compare_first);

        // // for (auto e : xors) {
        // //     cout << e.first << " " << e.second << endl;
        // // }

        // // cout << endl;

        // lld sum = 0;

        // for (int i = 0 ; i < N;) {
        //     lld xorSUM = 0;
        //     lld arrSUM = 0;
        //     for (int j = 0 ; j < K and i < N ; j++, i++) {
        //         xorSUM += A[xors[i].second] xor X;
        //         arrSUM += A[xors[i].second];
        //     }

        //     // watch(xorSUM);
        //     // watch(arrSUM);

        //     sum += max(xorSUM, arrSUM);
        // }

        // cout << sum << endl;

        // if (2 * K > N ) {
        //     // watch("HERE");
        //     vector <bool> permute;

        //     for (int i = 0 ; i < N-K ; i++) {
        //         permute.push_back(false);
        //     }

        //     for (int i = 0 ; i < K ; i++) {
        //         permute.push_back(true);
        //     }

        //     MAX = LLONG_MIN;

        //     do {

        //         lld sum = 0;

        //         for (int i = 0 ; i < N ; i++) {
        //             B[i] = A[i];
        //             if (permute[i])
        //                 B[i] = A[i] ^ X;
                    
        //             sum += B[i];
        //         }

        //         MAX = max(MAX, sum);

        //     } while(next_permutation(permute.begin(), permute.end()));
        // }

        // else {
        //     lld MAX_N = 0;

        //     fori(i, 0, N) {
        //         B[i] = A[i];

        //         if ( (A[i] ^ X) > A[i]) {
        //             watch(A[i]);
        //             B[i] = A[i] ^ X;
        //         }

        //         MAX_N += B[i];
        //     }

        //     MAX = max(MAX, MAX_N);
        // }

        // cout << MAX << endl;
    }

    return 0;
}