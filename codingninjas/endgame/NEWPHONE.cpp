#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <regex>
#define mod 1000000007
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define pb push_back
#define pop pop_back
#define mp make_pair
#define cint cpp_int
#define fin(ii, nn) for (int i = ii; i < nn; i++)
#define lld long long int

std::string ltrim(const std::string& s) {
	return std::regex_replace(s, std::regex("^\\s+"), std::string(""));
}

std::string rtrim(const std::string& s) {
	return std::regex_replace(s, std::regex("\\s+$"), std::string(""));
}

std::string trim(const std::string& s) {
	return ltrim(rtrim(s));
}

using namespace std;

string hashtab[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

lld keylens[] = {0, 3, 3, 3, 3, 3, 4, 3, 4};

char get_digit(char x) {
    lld digpos = 0;
    lld pos = x - 'a' + 1;
    while (pos > 0) {
        pos -= keylens[digpos++];
    }

    return '0' + digpos;
}

int main() {
    fastio
    int N;
    cin >> N;
    vector <string> v;
    for (int i = 0 ; i < N ; i++) {
        string str; cin >> str;
        for (auto &x: str) {
            x = get_digit(x);
        }

        v.pb(str);
    }
    string input;
    cin >> input;
    lld ans = 0;
    for (auto e: v) {
        ans += input == e;
    }

    cout << ans << endl;
    return 0;
}