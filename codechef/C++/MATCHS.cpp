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
#define MAX 1000000+5

using namespace boost::multiprecision;
using namespace std;

void fastio() {
    ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
}

int main() {
    fastio();

    int T;
    cin >> T;

    while (T--) {
        cint N, M;
        cin >> N >> M;

        cint count = 1;

        cint X = max(N, M);
        cint Y = (N + M) - X;

        while(X%Y !=0 && X/Y <= 1) {
            count ++;

            X = X - Y;
            M = X;
            N = Y;

            X = max(M, N);
            Y = (M + N) - X;
        }

        ODD(count) ? cout << "Ari" << endl : cout << "Rich" << endl;
    }

    return 0;
}