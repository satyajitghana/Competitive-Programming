#include <boost/multiprecision/cpp_int.hpp>
#include <boost/algorithm/string.hpp>
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <regex>

#define mod 1000000007
#define pb push_back
#define pop pop_back
#define mp make_pair
#define cint cpp_int
#define fin(ii, nn) for (int i = ii; i < nn; i++)
#define lld long long int
#define CLR(x, y) memset(x, y, sizeof(x))
#define ODD(x) (((x)&1)==0?(0):(1))

using namespace boost::multiprecision;
using namespace std;

void fastio() {
    ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
}

#define MAX 1000000+5

cint DP[MAX];

int main() {
    fastio();

    DP[1] = 1;

    cint result = 1;

    for (int i = 2; i <= MAX; i++) {
        result = result + i + i * (DP[i-1]);
        DP[i] = result%mod;
    }

    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;

        cout << DP[N] << endl;
        
    }

    return 0;
}
/*
        cint N;
        cin >> N;

        cint prev = 1;
        cint result = 1;

        for (cint i = 2; i <= N ; i++) {
            result = result + i + i * (prev);
            result %= mod;
            prev = result;
        }

        result %= mod;

        cout << result<< endl;
*/

// 1
// 25
// 459042010
