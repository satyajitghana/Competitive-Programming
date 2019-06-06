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

#define MOD (long long int)(1e9+7)
#define precision 1e2
#define pb push_back
#define mp make_pair
#define pint cpp_int
#define pint_pair pair<pint, pint>
#define pfloat cpp_dec_float<precision>
#define lld long long int
#define CLR(_a, _init) memset(_a, _init, sizeof(_a))
#define ODD(_num) (((_num)&1)==0?(0):(1))
#define EVEN(_num2) (!(((_num2)&1)==0?(0):(1)))
#define MAXN (lld)(100500)
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

int A[MAXN], N;
int dx[MAXN];

int main() {
    fastio;

    int T;
    cin >> T;
    while(T--) {
        int M, K;
        cin >> N >> M >> K;
        for (int i = 1; i <= N ; i++) {
            cin >> A[i];
        }

        vector < pair <int, int> > i_conds;
        vector < pair <int, int> > d_conds; 
        while (M--) {
            char type; int L, R;
            cin >> type >> L >> R;
            if (type == 'I') {
                i_conds.pb({L, R});
            } else {
                d_conds.pb({L, R});
            }
        }

        // sort the segments
        sort(i_conds.begin(), i_conds.end());
        sort(d_conds.begin(), d_conds.end());

        // create the increasing and decreasing segments by merging overlaps

        vector < pair <int, int> > i_segs;

        i_segs.push_back(i_conds[0]);
        for (auto part : i_conds) {
            auto temp = i_segs.back();
            if (part.first <= temp.second && part.second > temp.second) {
                i_segs.pop_back();
                i_segs.push_back({temp.first, part.second});
            }
        }

        vector < pair <int, int> > d_segs;

        d_segs.push_back(d_conds[0]);
        for (auto part : d_conds) {
            auto temp = d_segs.back();
            if (part.first <= temp.second && part.second > temp.second) {
                d_segs.pop_back();
                d_segs.push_back({temp.first, part.second});
            }
        }

        // check vector that contains all the segments
        vector <pair<int, int> > check;

        // cout << "ISEGS" << endl;
        for (auto e : i_segs) {
            // cout << e.first << " " << e.second << endl;
            check.push_back(e);
        }

        // cout << "DSEGS" << endl;
        for (auto e : d_segs) {
            // cout << e.first << " " << e.second << endl;
            check.push_back(e);
        }

        int ans = 1;

        // check for overlap of increasing and decreasing segments
        sort(check.begin(), check.end());

        for (int i = 1 ; i < check.size() ; i++) {
            if (check[i].first < check[i-1].second) {
                ans = 0;
                goto end;
            }
        }

        // below part tested works

        // create the dx array
        memset(dx, 0, sizeof(dx));

        for (auto seg : i_segs) {
            dx[seg.first]++;
            dx[seg.second]--;
        }

        for (auto seg : d_segs) {
            dx[seg.first]--;
            dx[seg.second]++;
        }

        for (int i = 1 ; i <= N ; i++) {
            dx[i] += dx[i-1];
        }

        for (int i = 1 ; i < N ;) {
            if (dx[i] == 0) {
                i++;
                continue;
            }
            
            int j;
            for (j = i ; dx[j] != 0 && j < N ; j++);

            int const_idx = -1;
            for (int k = i; k <= j ; k++) {
                if (A[k] != -1) {
                    const_idx = k;
                    break;
                }
            }

            if (const_idx == -1) {
                // flag these to not include later at the end
                for (int k = i ; k <= j ; k++) {
                    A[k] = 1;
                }

                int mx = 0, mn = 0, c = 0;
                for (int k = i ; k < j ; k++) {
                    c += dx[k];
                    mx = max(mx, c);
                    mn = min(mn, c);
                }

                int delta = mx - mn;
                if (delta + 1 > K) {
                    ans = 0;
                    goto end;
                }

                ans = (1LL * ans * (K - delta)) % MOD;
            } else {
                for (int k = const_idx - 1 ; k >= i ; k--) {
                    int x = A[k+1] - dx[k];
                    // check if the number is bounded between [1, K]
                    if (x < 1 || x > K) {
                        ans = 0;
                        goto end;
                    }
                    // check if any other constant here violates the rule
                    if (x != A[k] && A[k] != -1) {
                        ans = 0;
                        goto end;
                    }
                    A[k] = x;
                }

                // do the same for the right half
                for (int k = const_idx + 1 ; k <= j ; k++) {
                    int x = A[k-1] + dx[k-1];
                    if (x < 1 || x > K) {
                        ans = 0;
                        goto end;
                    }

                    if (x != A[k] && A[k] != -1) {
                        ans = 0;
                        goto end;
                    }

                    A[k] = x;
                }
            }

            i = j;
        }

        for (int i = 1 ; i <= N ; i++) {
            if (A[i] == -1) {
                ans = (1LL * ans * K) % MOD;
            }
        }

end:
        cout << ans << endl;
    } 

    return 0;
}