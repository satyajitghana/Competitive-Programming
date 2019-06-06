#include <bits/stdc++.h>

#define MAXN 100500
#define MOD (long long int) 1e9+7

using namespace std;

int A[MAXN];
int dx[MAXN];

vector < pair <int, int> > merge_conds(vector < pair <int, int> > conds) {
    vector < pair <int, int> > segs;

    if (conds.size() == 1) {
        return conds;
    }

    segs.push_back(conds[0]);

    for (auto seg : conds) {
        auto curr = segs.back();
        if (seg.first <= curr.second && seg.second > curr.second) {
            segs.pop_back();
            segs.push_back({curr.first, seg.second});
        } else if (seg.first > curr.second) {
            segs.push_back(seg);
        }
    }

    return segs;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        int N, M, K;
        cin >> N >> M >> K;

        for (int i = 1 ; i <= N ; i++) {
            cin >> A[i];
        }

        vector < pair <int, int> > i_conds;
        vector < pair <int, int> > d_conds;

        while (M--) {
            char type;
            int L, R;
            cin >> type >> L >> R;
            if (type == 'I') {
                i_conds.push_back({L, R});
                for (int k = L ; k <= R ; k++) {
                    dx[k] = 1;
                }
            } else {
                d_conds.push_back({L, R});
                for (int k = L ; k <= R ; k++) {
                    dx[k] = -1;
                }
            }
        }

        vector < pair <int, int> > i_segs;
        vector < pair <int, int> > d_segs;

        // sort the conditions and merge the values;
        sort(i_conds.begin(), i_conds.end());
        sort(d_conds.begin(), d_conds.end());

        i_segs = merge_conds(i_conds);
        d_segs = merge_conds(d_conds);

        // test the new conditions

        // 1
        // 20 10 2
        // 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
        // I 1 3
        // I 3 5
        // I 2 3
        // I 8 10
        // D 11 14
        // D 12 13
        // D 14 15
        // D 17 19
        // D 11 19
        // D 12 18

        cout << "SEGS" << endl;

        for (auto e : i_segs) {
            cout << e.first << " " << e.second << endl;
        }

        for (auto e : d_segs) {
            cout << e.first << " " << e.second << endl;
        }

        cout << endl;

        // above tested works

        // find if the increasing and the decreasing overlap

        int ans = 1;

        int i = 0, j = 0;

        vector < pair <int, int> > all_segs;

        while (i < i_segs.size() && j < d_segs.size()) {
            if (i_segs[i] < d_segs[j]) {
                all_segs.push_back(i_segs[i]);
                i++;
            } else {
                all_segs.push_back(d_segs[i]);
                j++;
            }
        }

        // push rest of the segments
        while (i < i_segs.size()) {
            all_segs.push_back(i_segs[i]);
            i++;
        }

        while (j < d_segs.size()) {
            all_segs.push_back(d_segs[j]);
            j++;
        }

        // check if there are any overlaps

        for (i = 0 ; i < all_segs.size()-1 ; i++) {
            auto one = all_segs[i];
            auto two = all_segs[i+1];

            if (two.first < one.second) {
                ans = 0;
                goto end;
            }
        }

        // now check if the segements are feasible
        for (i = 1 ; i <= N ; i++) {
            int start = i;
            int end = i;

            while(dx[end]) ++end;

            bool found_const = false;

            for (int k = start ; k <= end ; k++) {
                if (A[k] != -1) {
                    // found a constant
                    found_const = true;
                    int current = A[k];
                    for (int v = k-1; v >= start ; v--) {
                        current -= dx[v];
                        if (current < 1 or current > K) {
                            ans = 0;
                            goto end;
                        }

                        if (A[k] != -1 and A[k] != current) {
                            ans = 0;
                            goto end;
                        }
                    }

                    for (int v = k+1 ; v <= end ; v++) {
                        current += dx [v-1];
                        if (current < 1 or current > K) {
                            ans = 0;
                            goto end;
                        }

                        if (A[k] != -1 and A[k] != current) {
                            ans = 0;
                            goto end;
                        }
                    }
                }
            }

            if (found_const) {
                i = end;
                continue;
            }

            int mn = 0, mx = 0, current = 0;

            for (int v = start+1; v <= end ; v++) {
                current += dx[v-1];
                mx = max(current, mx);
                mn = min(current, mn);
            }

            int delta = mx-mn;

            if (delta + 1 > K) {
                ans = 0;
                goto end;
            } else {
                ans = (1LL * (K-delta)) % MOD;
            }

            i = end;
        }
        
end:
        cout << ans << endl;
    }
    return 0;
}