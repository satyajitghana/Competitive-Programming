// COMPILER OPTIMIZATION
#ifdef ONLINE_JUDGE
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#endif

// INCLUDES
#include <bits/stdc++.h>
#include <cmath>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include <iostream>
#include <regex>
#include <string>

using namespace __gnu_pbds;
using namespace std;

// DEFINES
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL);               \
    std::cout.tie(NULL)
#define lld long long int
#define pii std::pair<int, int>
#define ff first
#define ss second
#define CLR(_a, _init) memset(_a, _init, sizeof(_a))
#define ODD(_num) (((_num)&1) == 0 ? (0) : (1))
#define EVEN(_num2) (!(((_num2)&1) == 0 ? (0) : (1)))
#define fori(_ii, _begin, _end) for (lld _ii = _begin; _ii < _end; _ii++)
#define ALL(_v) std::begin(_v), std::end(_v)
#define DEBUG "DEBUG: "
#define watch(__x) cout << DEBUG << (#__x) << " : " << (__x) << endl

// PBDS
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// HELPER FUNCTIONS
template <typename T>
inline void print_arr(T arr[], int N) {
    fori(i, 0, N) {
        cout << arr[i] << ' ';
    }

    cout << '\n';
}
template <typename T>
inline void print_vec(vector<T> vec, int N) {
    fori(i, 0, N) {
        cout << vec[i] << ' ';
    }

    cout << '\n';
}

template <typename T>
inline void print_set(set<T> s) {
    for (auto e : s) {
        cout << e << ' ';
    }

    cout << '\n';
}

// LET THE GAMES BEGIN
int main() {
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        std::vector<int> A(N);

        fori(i, 0, N) {
            cin >> A[i];
        }

        auto cnt = 0;

        fori(i, 0, N) {
            // unordered_map<int, int> freq;
            std::array<int, 2002> freq;
            std::fill(ALL(freq), 0);
            ordered_set<pii> s;

            fori(j, i, N) {
                int m = std::ceil(1.0 * K / (j - i + 1));
                int Ks = std::ceil(1.0 * K / m) - 1;

                s.insert({A[j], freq[A[j]]++});

                auto it = s.find_by_order(Ks);
                auto X = (*it).first;
                auto f = freq[X];

                if (freq[f] > 0)
                    cnt++;
            }
        }

        cout << cnt << '\n';
    }
    return 0;
}