#include<bits/stdc++.h>
using namespace std;

mt19937::result_type seed = chrono::steady_clock::now().time_since_epoch().count();
auto rng = std::bind(std::uniform_real_distribution<double>(0,1), mt19937(seed));
#define watch(x) cout << (#x) << " = " << (x) << endl
#define PI double(2 * acos(0.0))
#define LL long long
#define MOD 1000000007
#define PB push_back 
#define MP make_pair
#define PII pair<int, int>
#define PLL pair<long long, long long>
#define PPIII pair < pair <int, int> , int>
#define PIPII pair < int, pair <int, int> >

int main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    string a, b, c, d, e, f;
    for(int i = 0; i < n; i++)  {
        a += 'a';
        b += 'a';
    }
    for(int i = 0; i < n; i++)  {
        a += 'b';
        b += 'c';
    }
    for(int i = 0; i < n; i++)  {
        a += 'c';
        b += 'b';
    }

    for(int i = 0; i < n; i++)  {
        c += 'b';
        d += 'b';
    }
    for(int i = 0; i < n; i++)  {
        c += 'a';
        d += 'c';
    }
    for(int i = 0; i < n; i++)  {
        c += 'c';
        d += 'a';
    }

    for(int i = 0; i < n; i++)  {
        e += 'c';
        f += 'c';
    }
    for(int i = 0; i < n; i++)  {
        e += 'a';
        f += 'b';
    }
    for(int i = 0; i < n; i++)  {
        e += 'b';
        f += 'a';
    }
    int flag = 0;
    for(int i = 0; i < (3*n) - 1; i++)  {
        if(a[i] == s[0] && a[i+1] == s[1])  {
            flag = 1;
        }
        if(a[i] == t[0] && a[i+1] == t[1])  {
            flag = 1;
        }
    }
    if(flag == 0)   {
        cout << "YES\n";
        cout << a;
        return 0;
    }

    flag = 0;
    for(int i = 0; i < (3*n) - 1; i++)  {
        if(b[i] == s[0] && b[i+1] == s[1])  {
            flag = 1;
        }
        if(b[i] == t[0] && b[i+1] == t[1])  {
            flag = 1;
        }
    }
    if(flag == 0)   {
        cout << "YES\n";
        cout << b;
        return 0;
    }

    flag = 0;
    for(int i = 0; i < (3*n) - 1; i++)  {
        if(c[i] == s[0] && c[i+1] == s[1])  {
            flag = 1;
        }
        if(c[i] == t[0] && c[i+1] == t[1])  {
            flag = 1;
        }
    }
    if(flag == 0)   {
        cout << "YES\n";
        cout << c;
        return 0;
    }

    flag = 0;
    for(int i = 0; i < (3*n) - 1; i++)  {
        if(d[i] == s[0] && d[i+1] == s[1])  {
            flag = 1;
        }
        if(d[i] == t[0] && d[i+1] == t[1])  {
            flag = 1;
        }
    }
    if(flag == 0)   {
        cout << "YES\n";
        cout << d;
        return 0;
    }

    flag = 0;
    for(int i = 0; i < (3*n) - 1; i++)  {
        if(e[i] == s[0] && e[i+1] == s[1])  {
            flag = 1;
        }
        if(e[i] == t[0] && e[i+1] == t[1])  {
            flag = 1;
        }
    }
    if(flag == 0)   {
        cout << "YES\n";
        cout << e;
        return 0;
    }

    flag = 0;
    for(int i = 0; i < (3*n) - 1; i++)  {
        if(f[i] == s[0] && f[i+1] == s[1])  {
            flag = 1;
        }
        if(f[i] == t[0] && f[i+1] == t[1])  {
            flag = 1;
        }
    }
    if(flag == 0)   {
        cout << "YES\n";
        cout << f;
        return 0;
    }
    string g, h, k, l, o, p;
    string g_temp = "abc";
    string h_temp = "acb";
    string k_temp = "bca";
    string l_temp = "bac";
    string o_temp = "cab";
    string p_temp = "cba";
    for(int i = 0; i < n; i++)  {
        g += g_temp;
        h += h_temp;
        k += k_temp;
        l += l_temp;
        o += o_temp;
        p += p_temp;
    }
    flag = 0;
    for(int i = 0; i < (3*n) - 1; i++)  {
        if(g[i] == s[0] && g[i+1] == s[1])  {
            flag = 1;
        }
        if(g[i] == t[0] && g[i+1] == t[1])  {
            flag = 1;
        }
    }
    if(flag == 0)   {
        cout << "YES\n";
        cout << g;
        return 0;
    }

    flag = 0;
    for(int i = 0; i < (3*n) - 1; i++)  {
        if(h[i] == s[0] && h[i+1] == s[1])  {
            flag = 1;
        }
        if(h[i] == t[0] && h[i+1] == t[1])  {
            flag = 1;
        }
    }
    if(flag == 0)   {
        cout << "YES\n";
        cout << h;
        return 0;
    }

    flag = 0;
    for(int i = 0; i < (3*n) - 1; i++)  {
        if(k[i] == s[0] && k[i+1] == s[1])  {
            flag = 1;
        }
        if(k[i] == t[0] && k[i+1] == t[1])  {
            flag = 1;
        }
    }
    if(flag == 0)   {
        cout << "YES\n";
        cout << k;
        return 0;
    }

    flag = 0;
    for(int i = 0; i < (3*n) - 1; i++)  {
        if(l[i] == s[0] && l[i+1] == s[1])  {
            flag = 1;
        }
        if(l[i] == t[0] && l[i+1] == t[1])  {
            flag = 1;
        }
    }
    if(flag == 0)   {
        cout << "YES\n";
        cout << l;
        return 0;
    }

    flag = 0;
    for(int i = 0; i < (3*n) - 1; i++)  {
        if(o[i] == s[0] && o[i+1] == s[1])  {
            flag = 1;
        }
        if(o[i] == t[0] && o[i+1] == t[1])  {
            flag = 1;
        }
    }
    if(flag == 0)   {
        cout << "YES\n";
        cout << o;
        return 0;
    }

    flag = 0;
    for(int i = 0; i < (3*n) - 1; i++)  {
        if(p[i] == s[0] && p[i+1] == s[1])  {
            flag = 1;
        }
        if(p[i] == t[0] && p[i+1] == t[1])  {
            flag = 1;
        }
    }
    if(flag == 0)   {
        cout << "YES\n";
        cout << p;
        return 0;
    }
    cout << "NO";
    return 0;

}