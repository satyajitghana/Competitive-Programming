
#include <bits/stdc++.h>

using namespace std;
#define sz(a) int(a.size())
#define ll long long
#define mod int(1e9 + 7)
#define endl '\n'
#define ENGZ                      \
    ios::sync_with_stdio(0);      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
#define pi (acos(-1))
#define S second
#define F first
ll fp(ll n, ll p) {
    if (p == 0)
        return 1;
    if (p == 1)
        return n;
    ll res = fp(n, p / 2);
    res = ((res) * (res));
    if (p % 2)
        res = (res * n);
    return res;
}

ll books, libararies, days, scores[100000];
struct lib {
    ll books, signup, bookpd;
    vector<ll> bookid;
    ll score = 0;
    int i = 0;
} libs[30000];
bool cmp(int a, int b) {
    return libs[a].signup > libs[b].signup;
}
int main() {
    freopen("f_libraries_of_the_world.txt", "r", stdin);
    freopen("f_sol.txt", "w", stdout);
    cin >> books >> libararies >> days;
    for (int i = 0; i < books; i++) {
        cin >> scores[i];
    }
    vector<int> hbd;
    for (int i = 0; i < libararies; i++) {
        hbd.push_back(i);
        cin >> libs[i].books >> libs[i].signup >> libs[i].bookpd;
        vector<pair<ll, int> > vp;
        for (int j = 0; j < libs[i].books; j++) {
            ll x;
            cin >> x;
            //vp.push_back({scores[x] , x});
            libs[i].bookid.push_back(x);
            libs[i].score += scores[x];
        }
        // sort(vp.begin(),vp.end());
        sort(libs[i].bookid.begin(), libs[i].bookid.end());
        /* for(int j=vp.size()-1 ; j>=0 ; j--)
        {
            libs[i].bookid.push_back(vp[j].S);
        }*/
    }
    sort(hbd.begin(), hbd.end(), cmp);
    vector<vector<int> > v;
    vector<pair<int, int> > vv;
    v.resize(libararies + 1);
    int i = 0, j = hbd.size() - 1;
    while (i <= days && j >= 0) {
        if (days - libs[hbd[j]].signup >= 0) {
            i += libs[hbd[j]].signup;
            vv.push_back({hbd[j], days - i});
        }
        j--;
    }
    map<int, bool> mp;
    int cnnt = vv.size();
    for (int i = 0; i < vv.size(); i++) {
        bool fin = 0;
        int k = 0;
        for (int j = 0; j < vv[i].S && k < libs[vv[i].F].bookid.size(); j++) {
            for (int l = 0; l < libs[vv[i].F].bookpd && k < libs[vv[i].F].bookid.size(); k++) {
                if (mp.count(libs[vv[i].F].bookid[k]) == 0) {
                    mp[libs[vv[i].F].bookid[k]] = 1;
                    v[vv[i].F].push_back(libs[vv[i].F].bookid[k]);
                    l++;
                }
            }
        }
        if (v[vv[i].F].size() == 0)
            cnnt--;
    }
    cout << cnnt << endl;
    for (int i = 0; i < vv.size(); i++) {
        if (v[vv[i].F].size() == 0)
            continue;
        cout << vv[i].F << " " << v[vv[i].F].size() << endl;
        for (int j = 0; j < v[vv[i].F].size(); j++) {
            cout << v[vv[i].F][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
