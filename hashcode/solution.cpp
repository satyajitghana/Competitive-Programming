#pragma GCC optimize("O3")
/* Include Header Files */
#include <bits/stdc++.h>
#include <cmath>
#include <functional>
#include <iostream>
#include <regex>
#include <string>

/* Define Macros */
#define MOD 1e9 + 7
#define precision 1e2
#define pb push_back
#define pop pop_back
#define mp make_pair
#define lld long long int
#define CLR(_a, _init) memset(_a, _init, sizeof(_a))
#define ODD(_num) (((_num)&1) == 0 ? (0) : (1))
#define EVEN(_num2) (!(((_num2)&1) == 0 ? (0) : (1)))
#define MAXN (lld)(1e6 + 5)
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL);               \
    std::cout.tie(NULL)
#define print_pairs(_pairs)                           \
    for (auto _e : _pairs) {                          \
        cout << _e.first << " " << _e.second << endl; \
    }
#define fori(_ii, _begin, _end) for (lld _ii = _begin; _ii < _end; _ii++)
#define DEBUG "DEBUG------"
#define watch(__x) cout << DEBUG << (#__x) << " : " << (__x) << endl
#define stop_here return 0

using namespace std;

template <typename T>
inline void SWAP(T &a, T &b) {
    T temp = b;
    b = a;
    a = temp;
}

template <typename T>
inline T distance(pair<T, T> a, pair<T, T> b) { return min(abs(a.first - b.first), abs(a.second - b.second)); }

template <typename T>
bool pair_compare_first(const pair<T, T> &a, const pair<T, T> &b) { return a.first <= b.first; }

template <typename T>
bool pair_compare_second(const pair<T, T> &a, const pair<T, T> &b) { return a.second <= b.second; }

template <typename T>
inline void print_vec(vector<T> arr, int len) {
    fori(i, 0, len) { cout << arr[i] << " "; }
}
template <typename T>
inline void print_arr(T arr[], int len) {
    fori(i, 0, len) { cout << arr[i] << " "; }
}

/* Input */
void input() {
#ifndef ONLINE_JUDGE
    freopen("a_example.txt", "r", stdin);
#endif
}

/* Let the Games Begin */

class lib {
   public:
    int id;
    int n_books;
    int n_signup_days;
    int n_books_per_day;

    vector<int> books;
};

int main() {
    fastio;
    input();

    int temp;

    // score for each book
    vector<int> book_scores;

    // libraries
    vector<int> libraries;

    // number of books, number of libraries, total days
    int B, L, D;
    cin >> B >> L >> D;

    for (int i = 0; i < B; i++) {
        cin >> temp;
        book_scores.push_back(temp);
    }

    vector<pair<int, lib>> times;

    // index i represents the library id
    for (int i = 0; i < L; i++) {  // for every library
        lib _lib;

        cin >> _lib.n_books >> _lib.n_signup_days >> _lib.n_books_per_day;
        _lib.id = i;

        for (int j = 0; j < _lib.n_books; j++) {
            cin >> temp;
            _lib.books.push_back(temp);
        }

        pair<int, lib> total_time;

        total_time.first = _lib.n_signup_days + ceil(double(_lib.n_books) / _lib.n_books_per_day);
        total_time.second = _lib;
        times.push_back(total_time);
    }

    // sort(begin(libraries), end(libraries), [](lib a, lib b) { return a.n_signup_days >= b.n_signup_days; });
    sort(begin(times), end(times), [](pair<int, lib> a, pair<int, lib> b) { return a.first >= b.first; });

    cout << L << '\n';

    for (auto [time, lib] : times) {
        cout << lib.id << " " << lib.n_books << '\n';
        sort(begin(lib.books), end(lib.books), greater<int>());

        for (auto book : lib.books) {
            cout << book << " ";
        }

        cout << '\n';
    }

    return 0;
}