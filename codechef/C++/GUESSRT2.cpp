#include <bits/stdc++.h>
#include <boost/random/random_device.hpp>
#include <boost/random.hpp>
#include <boost/multiprecision/cpp_int.hpp>

#define pb push_back 
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mod 1000000007

using namespace std;

typedef boost::multiprecision::cpp_int cint;

// Source : https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-em1tended/

cint gcd_em1tended(cint a,cint b,cint *m1,cint *y) {
	if(a==0) {
		*m1=0, *y=1;
		return b;
	}
	cint m11,nm2;
    cint gcd_ = gcd_em1tended(b%a,a,&m11,&nm2);
    *m1=nm2-(b/a)*m11;
    *y=m11;

    return gcd_;
}

cint mod_inverse(cint a) {
    cint m1, y;
    gcd_em1tended(a, mod, &m1, &y);

    return ((m1%mod + mod) % mod);
}

cint mod_power(cint a, cint b, cint m) {
    cint res = 1;
    a = a % m;
    while (b > 0) {
        if (b % 2 != 0) {
            res = ( res * a ) % m;
        }
            b /= 2;
            a = ( a * a ) % m;
    }
    return res;
}

int main() {
    fastio
    cint T;
    cin >> T;
    while (T--) {
        cint N, K, M;
        cin >> N >> K >> M;
        int m1 = (M.convert_to<int>()+1)/2;
        cint nm1 = mod_power(N, m1, mod);
        cint nm2 = mod_power(N - 1, m1, mod);
        cint result = (((nm1 - nm2 + mod)%mod) * mod_power(nm1, mod - 2, mod))%mod;

        // cint highest = boost::multiprecision::pow(N, m1);
        // cint d = boost::multiprecision::pow(N-1, m1);
        // cint h;

        // if (M%2 == 0) {
        //     h = (highest-d)*(N+K)+d;
        //     highest = highest * (N+K);
        // } else {
        //     h = highest-d;
        // }

        // highest = mod_inverse(highest);
        // cint result = ((h%mod)*(highest%mod))%mod;
        if(M%2 == 0) {
            cint x = (((nm1)%mod)*((N + K)%mod))%mod;
            cint r = ((nm2)%mod) * mod_power(x, mod - 2, mod);
            result = (result + r%mod)%mod;
        }
        cout << result << std::endl;
    }
    return 0;
}