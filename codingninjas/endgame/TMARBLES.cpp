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

int main() {
    fastio

    lld N, TAR;

    cin >> N >> TAR;

    lld A[100000];

    for (int i = 0 ; i < N ; i++) {
        cin >> A[i];
    }

    lld start, end, ans;

    start = end = 0;

    ans = A[0];

    bool possible = false;

    while (start < N && end < N) {
        if (ans < TAR) {
            ans += A[++end];
        } else if (ans > TAR) {
            ans -= A[start++];
        } else {
            possible = true;
            break;
        }
    }

    if (possible) {
        cout << "true" << endl;

        for (int i = start; i < end + 1 ; i++) {
            cout << A[i] << " ";
        }

    } else {
        cout << "false" << endl;
    }

    return 0;

}