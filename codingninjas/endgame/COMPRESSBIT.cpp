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
#define CLR(x, y) memset(x, y, sizeof(x))
#define ODD(x) (((x)&1)==0?(0):(1))

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

    lld T, N, A[10000], B[10000];

    cin >> T;

    while (T--) {
        cin >> N;

        CLR(A, 0);
        CLR(B, 0);

        for (int i = 1 ; i <= N ; i++) {
            cin >> A[i];
        }

        if (N & 1) {
            lld temp = A[N];
            A[N-1]--;

            if (A[N-1] < 0) {
                A[N-1] = 0;
            }
            A[N] = A[N+1] = 1;
            A[N+2] = temp - 1;
        } else {
            lld temp = A[N-1];
            A[N-2]--;
            if (A[N-2] < 0) {
                A[N-2] = 0;
            }
            
            A[N-1] = 1;
            A[N]++;
            A[N+1] = temp - 1;
        }

        if (A[0]) {
            for (int i = 100; i >= 1 ; i--) {
                A[i] = A[i-1];
            }
        }

        lld curr = 1;

        for (int i = 0 ; i <= N+10 ; i++) {
            if (A[i] == 0) {
                continue;
            }

            if ( ODD(curr) && ODD(i) ) {
                B[curr++] = A[i];
            } else if ( !ODD(curr) && !ODD(i) ) {
                B[curr++] = A[i];
            } else {
                B[curr-1] += A[i];
            }
        }

        cout << (curr-1) << " " << endl;

        for (int i = 1 ; i < curr ; i++) {
            cout << B[i] << " ";
        }

        cout << endl;
    }

    return 0;
}