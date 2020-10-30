#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
#define li long long
#define pb push_back

struct Library {
    li no_of_books;
    li signup_time;
    li shiping_rate;
    vector<li> lib_books;
};

li num, books, lib_count, days;
vector<li> books_arr;
map<li, bool> books_hash;

void display_output(struct Library *lib, li libraries_scanned) {
    ofstream myfile;
    cout << libraries_scanned << endl;
    for (li i = 0; i < libraries_scanned; i++) {
        cout << i << " " << lib[i].lib_books.size() << endl;
        for (li j = 0; j < lib[i].no_of_books; j++) {
            cout << lib[i].lib_books[j] << " ";
        }
        cout << endl;
    }
}

void scan_input(struct Library *lib) {
    for (li i = 0; i < books; i++) {
        cin >> num;
        books_arr.pb(num);
        books_hash[i] = false;
    }

    for (li i = 0; i < lib_count; i++) {
        li no_of_books;
        li signup_time;
        li shiping_rate;
        vector<li> lib_books;

        cin >> no_of_books >> signup_time >> shiping_rate;
        for (li j = 0; j < no_of_books; j++) {
            cin >> num;
            lib_books.pb(num);
        }
        lib[i].no_of_books = no_of_books;
        lib[i].signup_time = signup_time;
        lib[i].shiping_rate = shiping_rate;
        lib[i].lib_books = lib_books;
    }
}

void solve(struct Library *lib) {
    li score = 0, shipping_days = days;
    struct Library new_library[lib_count];
    li libraries_scanned = 0;

    for (li i = 0; i < lib_count && shipping_days > 0; i++) {
        struct Library current_library = lib[i];
        shipping_days -= current_library.signup_time;
        new_library[i].no_of_books = current_library.no_of_books;
        new_library[i].shiping_rate = current_library.shiping_rate;
        new_library[i].signup_time = current_library.signup_time;
        vector<li> lib_books;

        for (li j = 0, k = 1; j < current_library.no_of_books; j++, k++) {
            lib_books.pb(current_library.lib_books[j]);
            li book_score = books_arr[current_library.lib_books[j]];
            score += book_score;
            if (k % current_library.shiping_rate == 0) {
                shipping_days--;
                k = 1;
            }
            if (shipping_days == 0) {
                break;
            }
        }
        new_library[i].lib_books = lib_books;
        libraries_scanned++;
    }
    display_output(new_library, libraries_scanned);
}

void input() {
#ifndef ONLINE_JUDGE
    freopen("b_read_on.txt", "r", stdin);
#endif
}

int main() {
    input();
    cin >> books >> lib_count >> days;
    Library lib[lib_count];
    scan_input(lib);
    solve(lib);
    return 0;
}