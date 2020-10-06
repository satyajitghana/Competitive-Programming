#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
 
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define ri(a) scanf("%d",&a)
#define rii(a,b) scanf("%d %d",&a,&b)
#define riii(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define lri(a) scanf("%lld",&a)
#define lrii(a,b) scanf("%lld %lld",&a,&b)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define debug true
#define dprintf debug && printf
#define all(v) v.begin(),v.end()
 
const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MAXN = 2e5+5;
const int MAXLOG = 18;
int MOD = 1e9+7;

 
#define MN 2 //matrix MNxMN
typedef vector<ll>  vll;
typedef vector<vll>  MAT;
MAT operator*(MAT &a, MAT &b) {
	MAT res(MN, vll(MN));
	FOR(i,0,MN) FOR(j,0,MN) FOR(k,0,MN)
		res[i][j] = (res[i][j] + (a[i][k] * b[k][j]) % MOD) % MOD;

	return res;
}
MAT pot(MAT b, int e){
	if(e==1) return b;
	if(e==2) return b*b;
	MAT r = pot(pot(b,e/2),2);
	if(e&1) return b*r;
	return r;
}
 
MAT F0(MN,vll(MN,1));
MAT F1(MN,vll(MN,1));
 
pair<ll,ll> f0(int n){
	if(!n) return {1,0};
	MAT R = pot(F0,n/2);
	return {R[0][0],R[1][0]};
}
 
ll f1(int n){
	if(!n) return 1;
	if(n==1) return 1;
	MAT R = pot(F1,n/2);
	return (R[0][0] + R[0][1])%MOD;
}
 
int solve(int m, int j){ //n==3
	if(j&1){
		pair<ll,ll> auxfa = f0(j-1);
		pair<ll,ll> auxfb = f0(m-j);
		ll f01 = auxfa.F, f02 = auxfb.F, f21 = auxfa.S, f22 = auxfb.S;
		return ( ((f01*f02)%MOD + (f01*f22)%MOD)%MOD + (f21*f02)%MOD )%MOD;
	}
	return (((f1(j-1)*f1(m-j))%MOD)*2)%MOD;
}
 
 
 
int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
 
	int T;
	ri(T);
 
	F0[0][0]=3; F0[0][1]=2;
	F1[0][0]=3; F1[1][0]=2;
 
	FOR(t,0,T){
		int n,m,i,j;
		rii(n,m); rii(i,j); ri(MOD);
 
		if(n&1 && m&1 && (i+j)%2==0){
			
			if(n==1 || m==1) printf("1\n");
			else printf("%d\n",solve(m,j));
		}else printf("0\n");
	}
 
    return 0;
}
