#include<boost/multiprecision/cpp_int.hpp>
#include<bits/stdc++.h>
#define mod 1000000007
using namespace boost::multiprecision;
using namespace std;
cpp_int power(cpp_int a,cpp_int b)
{
	//Program to find power
	cpp_int an=1;
	cpp_int a11=a;
	cpp_int b11 = b;
	while(b11!=0)
	{
		if(b11&1==1)
		an=an*a11;
		a11=a11*a11;
		b11=b11/2;
	}
	return an;
}
cpp_int gcd(cpp_int a,cpp_int b)
{
	//Program to find gcd
	if(a==0)
	return a;
	return gcd(b%a,a);
}
cpp_int gcdExtended(cpp_int a,cpp_int b,cpp_int *x,cpp_int *y)
{
	//gcdExtended
	if(a==0)
	{
		*x=0, *y=1;
		return b;
	}
	cpp_int x1,y1;
    cpp_int gcd_ = gcdExtended(b%a,a,&x1,&y1);
    *x=y1-(b/a)*x1;
    *y=x1;
    return gcd_;
}
cpp_int modInverse(cpp_int a)
{
cpp_int x,y;
cpp_int g = gcdExtended(a,mod,&x,&y);
if(g!=1)
cout<< "I";
else
{
	cpp_int res = (x%mod + mod)%mod;
	return res;
}	
}
// int main()
// {
// 	int t;
// 	cin >> t;
// 	while(t--)
// 	{
// 		cpp_int n,m,k,i;
// 		cin >> n >> k >> m;
// 		cpp_int va=(m-1)/2;
// 		cpp_int su=0;
// 		cpp_int highest;
// 		cpp_int h1 = power(n,(m+1)/2);
// 		cpp_int d = power(n-1,(m+1)/2);
// 		cpp_int h;
// 		if(m%2!=0)
// 		{
// 			h = h1-d;
// 		}
// 		if(m%2==0)
// 		{
// 			h = (h1-d)*(n+k)+d;
// 			h1 = h1*(n+k);
// 		}
//         cout << h1 << " ";
// 		h1 = modInverse(h1);
// 		cpp_int ans = ((h%mod)*(h1%mod))%mod;
// 		/*if(m&1==1)
// 		{
// 			highest=power(n,va+1);
// 			for(i=0;i<=va;i++)
// 			su+=(power((n-1),i)*(power(n,(va-i))));
// 		}
// 		else if(m%2==0)
// 		{
// 			highest=power(n,va+1)*(n+k);
// 			for(i=0;i<=va;i++)
// 			su+=(power((n-1),i)*power(n,va-i)*(n+k));
// 			su+=power(n-1,va+1);
// 		}
// 		cpp_int hcf = gcd(su,highest);
// 		su=su/hcf;
// 		highest=highest/hcf;
// 		highest=modInverse(highest);
// 		cpp_int ans=((su%mod)*(highest%mod)%mod);*/
//         cout << d << " " << h1 << " ";
// 		cout << ans << "\n"; //Final answer
// 	}
// 	return 0;
// }

#define ll long long
# define Modulo 1000*1000*1000 + 7

ll fast_gcd(ll a, ll b){
    if (a==0) return b;
    return fast_gcd(b%a, a);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t, N, K, M, tn, td;
    ll fn, fd, ansn, ansd, rn, rd, multn, multd;
    cin >> t;
    while (t--){
        cin >> N >> K >> M;
        fn = 1, fd = N, ansn=  1, ansd = N, rn = N-1, rd = N, multn = N-1, multd = N;
        M--;
        // cout << "At t value "<<t<<endl;
        while (M>1){
            tn = (multn*fn)%Modulo;
            td = (multd*fd)%Modulo;
            multn = (multn*rn)%Modulo;
            multd =  (multd*rd)%Modulo;
            ansn = (ansn*td + ansd*tn)%Modulo;
            ansd = (ansd*td)%Modulo;
            // cout << ansn  <<"\t" << ansd <<"\t" <<multn <<"\t"<<multd<<endl;
            M -= 2;
        }
        if (M==1){
            tn = (multn *fn) % Modulo;
            td = (multd *(N+K)) % Modulo;
            ansn = (ansn*td+ansd*tn)%Modulo;
            ansd = (ansd*td)%Modulo;
        }
        ll gcd = fast_gcd(ansn, ansd);
        ansn /= gcd; ansd /= gcd;
        //cout << ansn  <<"\t" << ansd <<"\t" <<multn <<"\t"<<multd<<endl;
        //cout <<"answer is " << ansn <<"/" <<ansd<<endl;
 
        cpp_int modres = modInverse(static_cast<cpp_int>(ansd));
        cpp_int ansd_ = static_cast<cpp_int>(ansd);
        cout << (ansd * modres) % mod << endl;
        // cout << (ansn*mod_inverse(ansd, Modulo))%Modulo <<endl;
    }
}