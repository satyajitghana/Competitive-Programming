#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

long long rec(int fl, vector<int>& vcl, int ml, const vector<vector<long long>>& map) {
    if (fl >= map.size()) {
        return 1;
    }
    long long answer = 0;
    for (int i = 0; i < map[fl].size(); ++i) {
        if (vcl[i] == 0 && map[fl][i] != 0) {
            vcl[i] = 1;
            if (fl + 1 == ml) {
                answer += map[fl][i] * rec(fl + 2, vcl, ml, map);
            } else {
                answer += map[fl][i] * rec(fl + 2, vcl, ml, map);
            }
            vcl[i] = 0;
            answer %= MOD;
        }
    }
    return answer;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int tests;
    cin >> tests;

    for (int t = 1; t <= tests; ++t) {
        long long answer = 0;
        long long n, m;
        cin >> n >> m;
        vector<vector<long long>> map(n, vector<long long>(n));
        for (int i = 0; i < n; ++i) {
            map[i][i] = 1;
        }
        long long sum = 1;
        long long w, aw, bw;
        cin >> w >> aw >> bw;
        long long d, ad, bd;
        cin >> d >> ad >> bd;
        long long s, as, bs;
        cin >> s >> as >> bs;
        while (m-- > 0) {
            long long z = max((long long) 1, min(n, w + d - 1));
            --w;
            --z;

            map[w][z] += s;
            map[w][z] %= MOD;

            vector<int> vcl(n);
            vcl[z] = 1;
            if (w != 0) {
                sum += s * rec(0, vcl, w, map);
            } else {
                sum += s * rec(1, vcl, w, map);
            }
            sum %= MOD;

            answer += sum;
            answer %= MOD;

            ++w;
            ++z;

            w = (aw * w + bw) % n + 1;
            d = (ad * d + bd) % 3;
            s = (as * s + bs) % 1000000000 + 1;
        }

        cout << "Case #" << t << ": " << answer << endl;
    }
    return 0;
}