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

    string S[100000];

    for (int i = 0 ; i < N ; i++) {
        cin >> S[i];
    }

    set<string> s;
    map<string, lld> m;
    vector<string> l;

    for (int i = 0 ; i < N ; i++) {
        if (m.find(S[i]) != m.end()) {
            lld n = m[S[i]];
            m[S[i]] = n + 1;
            l.pb(S[i] + " " + to_string(n+1));
        } else {
            m.insert(mp(S[i], 1));
            string t = "";
            bool inserted = false;

            for (int j = 0; j < S[i].length() ; j++) {
                string curr = S[i];
                t = t + curr[j];
                if (!inserted && ( s.find(t) == s.end() ) ) {
                    inserted = true;
                    l.pb(t);
                }
                s.insert(t);
            }
            if (!inserted) {
                l.pb(t);
            }
        }
    }

    for (string s: l) {
        cout << s << endl;
    }

    return 0;

}