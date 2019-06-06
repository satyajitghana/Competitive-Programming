#include <bits/stdc++.h>

using namespace std;

const int maxn = 20;
const int mod = 1e9 + 7;

int n, m, k;
int a[maxn];
int in_i[maxn], out_i[maxn];
int in_d[maxn], out_d[maxn];
int delta[maxn];

vector < pair <int, int> > merge(int in[maxn], int out[maxn]) {
    vector < pair <int, int> > segs;
    int cur = -1;
    int balance = 0;
    for(int i = 1; i <= n; ++i) {
        if (cur == -1 && in[i] == 0) continue;
        balance += in[i];
        if (balance > 0 && cur == -1) cur = i;
        balance -= out[i];
        if (balance == 0 && cur != -1) {
            segs.push_back(make_pair(cur, i));
            cur = -1;
        }
    }
    return segs;
}

int solve() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        in_i[i] = out_i[i] = 0;
        in_d[i] = out_d[i] = 0;
    }
    while(m--) {
        char d;
        int l, r;
        cin >> d >> l >> r;
        if (d == 'I') {
            in_i[l]++;
            out_i[r]++;
        } else {
            in_d[l]++;
            out_d[r]++;
        }
    }

    vector < pair <int, int> > inc = merge(in_i, out_i);
    vector < pair <int, int> > dec = merge(in_d, out_d);

        for (auto e : inc) {
            cout << e.first << " " << e.second << endl;
        }

        cout << endl;

        for (auto e : dec) {
            cout << e.first << " " << e.second << endl;
        }

        cout << endl;

    memset(delta, 0, sizeof delta);

    for(auto seg: inc) {
        delta[seg.first]++;
        delta[seg.second]--;
    }
    for(auto seg: dec) {
        delta[seg.first]++;
        delta[seg.second]--;
    }

    int s = 0;
    for(int i = 1; i <= n; ++i) {
        s += delta[i];
        if (s == 2) return 0;
    }
    memset(delta, 0, sizeof delta);
    for(auto seg: inc) {
        delta[seg.first]++;
        delta[seg.second]--;
    }
    for(auto seg: dec) {
        delta[seg.first]--;
        delta[seg.second]++;
    }

    for(int i = 1; i <= n; ++i) {
        delta[i] += delta[i - 1];
    }
    int res = 1;
    int c = n;
    for(int i = 1; i < n; ) {
        if (delta[i] == 0) {
            i++;
            continue;
        }
        int j = i;
        while(j < n && delta[j] != 0) j++;

        int idx = -1;
        for(int k = i; k <= j; ++k) {
            if (a[k] != -1) idx = k;
        }
        c -= j - i + 1;
        if (idx == -1) {
            for(int k = i; k <= j; ++k) a[k] = 1;
            int mx = 0, mn = 0, c = 0;
            for(int k = i; k < j; ++k) {
                c += delta[k];
                mx = max(mx, c);
                mn = min(mn, c);
            }
            if (mx - mn + 1 > k) res = 0;
            res = (1LL * res * (k - mx + mn)) % mod;
        } else {
            for(int k = idx - 1; k >= i; --k) {
                int x = a[k + 1] - delta[k];
                if (a[k] != -1 && a[k] != x) res = 0;
                a[k] = x;
                if (a[k] < 1 || a[k] > ::k) res = 0;
            }
            for(int k = idx + 1; k <= j; ++k) {
                int x = a[k - 1] + delta[k - 1];
                if (a[k] != -1 && a[k] != x) res = 0;
                a[k] = x;
                if (a[k] < 1 || a[k] > ::k) res = 0;
            }
        }
        i = j;
    }
    for(int i = 1; i <= n; ++i) {
        if (a[i] == -1) res = (1LL * res * k) % mod;
    }
    return res;
}

int main () {
    ios_base::sync_with_stdio(0);
   // freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    while(T--) {
        cout << solve() << endl;
    }
    return 0;
}