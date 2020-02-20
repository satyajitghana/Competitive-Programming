
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

#define F first
#define S second

using namespace std;

/* Input */
void open_input(string file_name) {
    // string file_name("a_example.txt");
#ifndef ONLINE_JUDGE
    if (not file_name.empty())
        freopen(file_name.c_str(), "r", stdin);
#endif
}

/* Output */
void open_output(string file_name) {
    // string file_name("a_sol.txt");
#ifndef ONLINE_JUDGE
    if (not file_name.empty())
        freopen(file_name.c_str(), "w", stdout);
#endif
}

/* Let the Games Begin */

struct Lib {
    lld id;
    lld books;
    lld signup_days;
    lld books_rate;
    lld score = 0;

    vector<lld> book_id;
};

vector<Lib> libs;

auto main(int argc, char* argv[]) -> int {
    fastio;
    open_input(argv[1]);
    open_output(argv[2]);

    lld temp;

    // number of books, number of libraries, total days
    lld B, L, D;
    cin >> B >> L >> D;

    // score for each book
    vector<lld> book_scores;

    for (int i = 0; i < B; i++) {
        cin >> temp;
        book_scores.push_back(temp);
    }

    for (int i = 0; i < L; i++) {
        Lib _temp;
        cin >> _temp.books >> _temp.signup_days >> _temp.books_rate;
        for (int j = 0; j < _temp.books; j++) {
            lld book_id;
            cin >> book_id;
            _temp.book_id.push_back(book_id);
            _temp.score += book_scores.at(book_id);
        }

        sort(begin(_temp.book_id), end(_temp.book_id));

        libs.push_back(_temp);
    }

    sort(begin(libs), end(libs), [](Lib a, Lib b) { return a.signup_days >= b.signup_days; });

    vector<vector<lld>> v;
    vector<pair<lld, lld>> vv;
    v.resize(libs.size() + 1);

    int i = 0, j = libs.size() - 1;
    while (i <= D and j >= 0) {
        if (D - libs.at(j).signup_days >= 0) {
            i += libs.at(j).signup_days;
            vv.push_back({j, D - i});
        }
        j--;
    }

    map<int, bool> mp;
    int cnt = vv.size();
    for (int i = 0; i < vv.size(); i++) {
        bool fin = 0;
        int k = 0;
        for (int j = 0; j < vv[i].S && k < libs[vv[i].F].book_id.size(); j++) {
            for (int l = 0; l < libs[vv[i].F].books_rate && k < libs[vv[i].F].book_id.size(); k++) {
                if (mp.count(libs[vv[i].F].book_id[k]) == 0) {
                    mp[libs[vv[i].F].book_id[k]] = 1;
                    v[vv[i].F].push_back(libs[vv[i].F].book_id[k]);
                    l++;
                }
            }
        }
        if (v[vv[i].F].size() == 0)
            cnt--;
    }
    cout << cnt << endl;
    for (int i = 0; i < vv.size(); i++) {
        if (v[vv[i].F].size() == 0)
            continue;
        cout << vv[i].F << " " << v[vv[i].F].size() << endl;
        for (int j = 0; j < v[vv[i].F].size(); j++) {
            cout << v[vv[i].F][j] << " ";
        }
        cout << endl;
    }

    stop_here;
}