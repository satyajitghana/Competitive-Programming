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

    int N, K;
    cin >> N >> K;

    lld A[100000];

    for (int i = 0 ; i < N ; i++) {
        cin >> A[i];
    }

    lld ans = INT_MIN;
    lld max_until = 0;

    for (int i = 0 ; i < N * K ; i++) {
        max_until += A[i%N];

        if (ans < max_until) {
            ans = max_until;
        }

        if (max_until < 0) {
            max_until = 0;
        }
    }

    cout << ans << endl;

    return 0;
}