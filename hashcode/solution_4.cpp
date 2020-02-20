#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct library_t {
    unsigned long long id;
    unsigned long long n_books;
    unsigned long long signup_time;
    unsigned long long ships_per_day;
    unsigned long long score;
    vector<int> books;
};

struct output_v {
    unsigned long long id;
    unsigned long long n_books;
    vector<int> b_ids;
};

void write_output(vector<output_v> &v) {
    cout << v.size() << endl;
    for (auto l : v) {
        cout << l.id << " " << l.n_books << endl;
        for (auto j : l.b_ids) {
            cout << j << " ";
        }
        cout << l.b_ids[v.size() - 1] << endl;
    }
}

unsigned long long n_books;
unsigned long long n_libraries;
unsigned long long n_days;
vector<int> book_value;
vector<library_t> libraries;

bool compare(unsigned long long a, unsigned long long b) {
    if (book_value[a] > book_value[b])
        return true;
    if (book_value[a] == book_value[b] && a > b)
        return true;
    return false;
}

unsigned long long library_score(unsigned long long a, unsigned long long b,
                                 unsigned long long c, int d, int e) {
    return 0;
}

bool compare_lib(library_t &l1, library_t &l2) { return l1.signup_time < l2.signup_time; }

void input() {
#ifndef ONLINE_JUDGE
    freopen("b_read_on.txt", "r", stdin);
#endif
}

int main() {
    input();
    // freopen("b_read_on.txt", "r", stdin);
    // freopen("b_output", "w", stdout);
    cin >> n_books;
    cin >> n_libraries;
    cin >> n_days;

    unsigned long long aux, signup, ships, aux4;

    for (unsigned long long i = 0; i < n_books; i++) {
        cin >> aux;
        book_value.push_back(aux);
    }

    for (unsigned long long i = 0; i < n_libraries; i++) {
        cin >> aux;
        cin >> signup;
        cin >> ships;
        vector<int> aux5;
        for (unsigned long long j = 0; j < aux; j++) {
            cin >> aux4;
            aux5.push_back(aux4);
        }
        sort(aux5.begin(), aux5.end(), compare);

        libraries.push_back({i, aux, signup, ships,
                             library_score(n_days, signup, ships, book_value[aux5[0]], book_value[aux5.back()]), aux5});
    }

    sort(libraries.begin(), libraries.end(), compare_lib);

    vector<output_v> output;

    int sum_days = 0;

    while (sum_days <= n_days) {
        for (auto l : libraries) {
            output_v o;
            o.id = l.id;
            o.n_books = l.n_books;
            o.b_ids = l.books;
            sum_days += l.signup_time;
            output.push_back(o);
        }
    }

    write_output(output);

    return 0;
}

// int sumOfBook;
// int numOfLibrary;
// int numOfDay;
// unordered_map<int, int> weightsOfBook;
// cin >> sumOfBook >> numOfLibrary >> numOfDay;
// for (int i = 0; i < sumOfBook; i++) {
//     int weight;
//     cin >> weight;
//     weightsOfBook.insert(pair<int, int>(i, weight));
// }
// vector<vector<vector<int>>> library;
// for (int i = 0; i < numOfLibrary; i++) {
//     int numOfBook;
//     int numOfSignup;
//     int numOfShip;
//     cin >> numOfBook >> numOfSignup >> numOfShip;
//     for (int j = 0; j < numOfBook; j++) {

//     }

// }