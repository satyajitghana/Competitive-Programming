#pragma GCC optimize("O3")
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

//#include <ext/pb_ds/assoc_container.hpp>

#define fi first
#define se second
#define th third

#define en "\n"
#define sqrt(n) sqrt((long double)n)
#define ALL(c) (c).begin(), (c).end()
#define MOD 1000000007
#define MEM0(a) memset(a, 0, sizeof(a))
#define FAST()                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define FILES(name) name != "" ? freopen(name ".in", "r", stdin), freopen(name ".out", "w", stdout) : 0
#define elif else if
#define SORT(x) sort(ALL(x))
#define REVERSE(x) reverse(ALL(x))
#define SZ(a) ((long long)((a).size()))
#define WHAT_IS(x) cerr << #x << " is " << x << en
#define TIMER (clock() * 1.0 / CLOCKS_PER_SEC)
#define sq(x) x *x
#define int long long

using namespace std;

template <class A, class B, class C>
struct triple {
    A first;
    B second;
    C third;
    bool operator<(const triple &t) const {
        if (first != t.first) return first < t.first;
        if (second != t.second) return second < t.second;
        return third < t.third;
    }
};

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef set<int> seti;
typedef long double ld;
typedef pair<ld, ld> pdd;
typedef triple<int, int, int> tiii;

const ld EPS = 0.000000001;
const ld INFD32 = 1000000000;
const ll INF64 = 1000000000000000000;
const ll INF32 = 1000000000;
const ll one = 1;

bool iss_ll(ll __1, ll __2) { return 2 * INF64 / __1 >= __2; }
bool equal(double _1, double _2) { return (abs(_1 - _2) < EPS); }
bool iss_sqr(int &__1) {
    ll __2 = sqrt(__1);
    return __2 * __2 == __1;
};
bool iss_prime(ll __1) {
    for (int i = 2; i * i <= __1; ++i)
        if (!(__1 % i)) return 0;
    return 1;
}
int gcd(int __1, int __2) {
    while (__1 && __2)
        if (__1 > __2)
            __1 = __1 % __2;
        else
            __2 = __2 % __1;
    return __1 + __2;
}
int lcm(int __1, int __2) { return __1 * __2 / (gcd(__1, __2)); }
int sq_cube(ll x) {
    if (x == 0) return 1;
    int l = 0, r = 2e6;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (m * m * m > x)
            r = m;
        else
            l = m;
    }
    return l;
}
int bp(int a, int b, int md) {
    int res = 1;
    while (b) {
        if (b & 1) res *= a;
        a *= a;
        a %= md;
        res %= md;
        b >>= 1;
    }
    return res;
}

/*

int fact[maxN],rfact[maxN];

void bld(int md){
    fact[0]=1;
    for (int i=1; i<maxN; ++i){
        fact[i]=fact[i-1]*i%md;
    }
    rfact[maxN-1]=bp(fact[maxN-1],md-2,md);
    for (int i=maxN-2; i>=0; --i){
        rfact[i]=rfact[i+1]*(i+1)%md;
    }
}

int C(int n,int k,int md){
    if (k>n) return 0;
    int res=fact[n];
    res*=rfact[k];
    res%=md;
    res*=rfact[n-k];
    res%=md;
    return res;
}

int rev(int x,int md){
    return bp(x,md-2,md);
}

*/

vector<int> z_function(string &s) {
    int n = SZ(s);
    vector<int> ans(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        ans[i] = min(r - i + 1, ans[i - l]);
        while (ans[i] + i < n && s[ans[i]] == s[i + ans[i]]) {
            ++ans[i];
        }
        if (i + ans[i] - 1 > r) {
            l = i, r = i + ans[i] - 1;
        }
        r = max(r, i);
    }
    return ans;
}

#define maxN 500500

int rar[maxN];

vi lbr[maxN];

int signup[maxN];

int cnt[maxN];

bool used[maxN];

int st[maxN];
int stt[maxN];

vi res[maxN];
vector<int> VEC;

vi ans[maxN];
vi ANS;

int ansss;
int cnt_books, cnt_lbrs, d;
vi v;
void upd_ans() {
    ANS = v;
    for (int i = 1; i <= cnt_lbrs; ++i) {
        ans[i] = res[i];
    }
}

void ss() {
    freopen("a_example.txt", "r", stdin);
    cin >> cnt_books >> cnt_lbrs >> d;
    for (int i = 1; i <= cnt_books; ++i) cin >> rar[i];
    for (int i = 1; i <= cnt_lbrs; ++i) {
        int n;
        cin >> n >> signup[i] >> cnt[i];
        lbr[i].resize(n);
        for (int j = 0; j < n; ++j) cin >> lbr[i][j];
        SORT(lbr[i]);
        REVERSE(lbr[i]);
    }
    for (int i = 0; i < cnt_lbrs; ++i) VEC.push_back(i + 1);
    int qqq = 0;
    while (TIMER < 1) {
        random_shuffle(ALL(VEC));
        int l = 0;
        MEM0(used);
        MEM0(stt);
        int resss = 0;
        for (int i = 1; i <= cnt_lbrs; ++i) st[i] = d + 1;
        for (int j = 1; j <= cnt_lbrs; ++j) {
            if (l + signup[VEC[j - 1]] > d) break;
            l += signup[VEC[j - 1]];
            st[VEC[j - 1]] = l + 1;
            v.push_back(VEC[j - 1]);
        }
        for (int j = 1; j <= d; ++j) {
            for (int q : v) {
                if (st[q] > j) break;
                for (int qq = 0; qq < cnt[q]; ++qq) {
                    while (stt[q] < lbr[q].size()) {
                        if (!used[lbr[q][stt[q]]]) {
                            resss += rar[lbr[q][stt[q]]];
                            res[q].push_back(lbr[q][stt[q]]);
                            used[lbr[q][stt[q]]] = 1;
                            ++stt[q];
                            break;
                        }
                        ++stt[q];
                    }
                }
            }
        }
        if (resss > ansss) upd_ans();
        v.clear();
        for (int j = 1; j <= cnt_lbrs; ++j) res[j].clear();
    }
    int c = 0;
    for (int i = 1; i <= cnt_lbrs; ++i)
        if (ans[i].size()) ++c;
    cout << c << en;
    for (int i = 1; i <= c; ++i) {
        cout << ANS[i - 1] << " " << ans[ANS[i - 1]].size() << en;
        for (int j : ans[ANS[i - 1]]) cout << j << " ";
        cout << en;
    }
}
signed main(void) {
    //look at the end
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin>>t;
    while (t--) {
        ss();
    }
    return 0;
}
//check special cases for example (n==1)
//check size  arrays