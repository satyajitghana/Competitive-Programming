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

    lld N;
    cin >> N;

    vector <lld> arrivals;
    vector <lld> departures;

    for (int i = 0 ; i < N ; i++) {
        lld input; cin >> input;
        arrivals.pb(input);
    }

    for (int i = 0 ; i < N ; i++) {
        lld input; cin >> input;
        departures.pb(input);
    }

    sort(arrivals.begin(), arrivals.end());
    sort(departures.begin(), departures.end());

    int i = 0;
    int j = 0;
    int cnt = 0;
    int ans = INT_MIN;

    while ( i < N && j < N) {
        if (arrivals[i] < departures[j]) {
            cnt++; i++;
        } else {
            cnt--; j++;
        }

        if (cnt > ans) {
            ans = cnt;
        }
    }

    cout << ans << endl;

    return 0;
}