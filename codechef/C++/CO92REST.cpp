/* Include Header Files */
#include <bits/stdc++.h>

/* Define Macros */

#define MOD (long long int)(1e9+7)
#define precision 1e2
#define pb push_back
#define pop pop_back
#define mp make_pair
#define lld long long int
#define CLR(_a, _init) memset(_a, _init, sizeof(_a))
#define ODD(_num) (((_num)&2)==0?(0):(1))
#define EVEN(_num2) (!(((_num2)&1)==0?(0):(1)))
#define MAXN (100500)
//#define MAXN 20
#define fastio ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL)
#define print_pairs(_pairs) for (auto _e : _pairs) { cout << _e.first << " " << _e.second << endl; }
#define fori(_ii, _begin, _end) for (lld _ii = _begin ; _ii < _end ; _ii++)
#define DEBUG "DEBUG------"
#define watch(__x) cout << DEBUG << (#__x) << " : " << (__x) << endl
#define stop_here return 0
#define ff first
#define ss second

using namespace std;

template<typename T> inline void SWAP(T &a, T&b) { T temp = b; b = a; a = temp; }

template<typename T> inline T distance(pair<T, T> a, pair<T, T> b) { return min(abs(a.first - b.first), abs(a.second - b.second)); }

template<typename T> bool pair_compare_first(const pair<T, T> &a, const pair<T, T> &b) { return a.first <= b.first; }

template<typename T> bool pair_compare_second(const pair<T, T> &a, const pair<T, T> &b) { return a.second <= b.second; }

template<typename T> inline void print_vec(vector<T> arr, int len) { fori(i, 0, len) { cout << arr[i] << " "; } }
template<typename T> inline void print_arr(T arr[], int len) { fori(i, 0, len) { cout << arr[i] << " "; } }

/* Let the Games Begin */

int A[MAXN], N;
int dx[MAXN];
int in_i[MAXN], out_i[MAXN];
int in_d[MAXN], out_d[MAXN];

vector<pair<int, int> > merge(int in[MAXN], int out[MAXN]) {
    vector<pair<int, int> > segs;
    int cur = -1;
    int balance = 0;
    for(int i = 1; i <= N; ++i) {
        if (cur == -1 && in[i] == 0) continue;
        balance += in[i];
        if (balance > 0 && cur == -1) cur = i;
        balance -= out[i];
        if (balance == 0 && cur != -1) {
            segs.pb({cur, i});
            cur = -1;
        }
    }
    return segs;
}

int main() {
    fastio;

    int T;
    cin >> T;

    while (T--) {
next:
        int M, K;
        cin >> N >> M >> K;

        for (int i = 1 ; i <= N ; i++) {
            cin >> A[i];
            in_i[i] = out_i[i] = 0;
            in_d[i] = out_d[i] = 0;
        }

        // vector<pair<int, int> > i_conds;
        // vector<pair<int, int> > d_conds;

        while (M--) {
            char type;
            int L, R;
            cin >> type >> L >> R;
            if (type == 'I') {
                // i_conds.pb({L, R});
                in_i[L]++;
                out_i[R]++;
            } else {
                // d_conds.pb({L, R});
                in_d[L]++;
                out_d[R]++;
            }
        }
        // sort the increasing and decreasing conditions based on the staring index
        // sort(i_conds.begin(), i_conds.end());
        // sort(d_conds.begin(), d_conds.end());

        // find the segments

        vector<pair<int, int> > i_segs = merge(in_i, out_i);
        vector<pair<int, int> > d_segs = merge(in_d, out_d);

        // vector<pair<int, int> > i_segs;

        // int begin = i_conds[0].ff;
        // int end = i_conds[0].ss;

        // for (auto e: i_conds) {
        //     if (e.ff < end) {
        //         end = e.ss;
        //     } else {
        //         i_segs.pb({begin, end});
        //         begin = e.ff;
        //         end = e.ss;
        //     }
        // }

        // vector<pair<int, int> > d_segs;

        // begin = d_conds[0].ff;
        // end = d_conds[0].ss;

        // for (auto e: d_conds) {
        //     if (e.ff < end) {
        //         end = e.ss;
        //     } else {
        //         d_segs.pb({begin, end});
        //         begin = e.ff;
        //         end = e.ss;
        //     }
        // }

        // check if there are any intersections
        memset(dx, 0, sizeof(dx));

        for (auto seg: i_segs) {
            dx[seg.ff]++;
            dx[seg.ss]--;
        }

        for (auto seg: d_segs) {
            dx[seg.ff]++;
            dx[seg.ss]--;
        }

        int cnt = 0;
        int flag = 0;
        for (int i = 1; i <= N ; i++) {
            cnt += dx[i];

            if (cnt >= 2) {
                flag = 1;
                break;
            }
        }

        if (flag == 1) {
            cout << 0 << endl;
            continue;
        }

        memset(dx, 0, sizeof(dx));

        for (auto seg: i_segs) {
            dx[seg.ff]++;
            dx[seg.ss]--;
        }

        for (auto seg: d_segs) {
            dx[seg.ff]--;
            dx[seg.ss]++;
        }

        for (int i = 1 ; i <= N ; i++) {
            dx[i] += dx[i-1];
        }

        int res = 1;
        // int C = N;

        for (int i = 1; i < N ; ) {
            if (dx[i] == 0) {
                i++;
                continue;
            }

            // find the bounds

            int j = i;
            while(dx[j] != 0 && j < N) ++j;

            int idx = -1;

            for (int k = i; k <= j; k++) {
                if (A[k] != -1) {
                    idx = k;
                    break;
                }
            }

            // C -= j - i + 1;

            if (idx == -1) {
                for (int k = i; k <= j ; k++) {
                    A[k] = 1;
                }

                int mx = 0, mn = 0, C = 0;

                for (int k = i; k < j ; k++) {
                    C += dx[k];
                    mx = max(mx, C);
                    mn = min(mn, C);
                }

                if (mx-mn + 1 > K) {
                    res = 0;
                    goto stop;
                }
                res = (1LL * res * (K - mx + mn)) % MOD;
            } else {
                for (int k = idx - 1; k >= i ; k--) {
                    int x = A[k+1] - dx[k];
                    if (A[k] != -1 && A[k] != x) {
                        res = 0;
                        goto stop;
                    }
                    A[k] = x;
                    if (A[k] < 1 || A[k] > K) {
                        res = 0;
                        goto stop;
                    }
                }
                for (int k = idx + 1 ; k <= j ; k++) {
                    int x = A[k-1] + dx[k-1];
                    if (A[k] != -1 && A[k] != x) {
                        res = 0;
                        goto stop;
                    }
                    A[k] = x;
                    if (A[k] < 1 || A[k] > K) {
                        res = 0;
                        goto stop;
                    }
                }
            }

            i = j;
        }


        for (int i = 1; i <= N ; i++) {
            if (A[i] == -1) res = (1LL * res * K) % MOD;
        }
stop:
        cout << res << endl;
        // stop_here;

    }

    return 0;
}
