#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define ri(a) scanf("%d", &a)
#define rii(a,b) scanf("%d %d", &a, &b)
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define rl(a) scanf("%lld", &a)
#define rll(a,b) scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM
int st[4*maxN];
char w[maxN+5];
int n;
int mx = 0;

int getcont( int x )
{
	int c = 0;
	while( x != 0 )
	{
		if ( x & 1 ) c++;
		x = x >> 1;
	}
	return c;
}

int make_st( int s , int e , int i )
{
	mx = max(mx,i);
	if ( s == e )
	{
		int aux = (int)( w[s] - 'a' );
		st[i] = 1 << aux;
		//printf("entre %d y %d dio %d\n", s,e,st[i]);
		return st[i];
	}

	int m = ( s + e )/2;
	st[i] = make_st(s , m , 2*i+1) | make_st(m+1 , e , 2*i+2);
	//printf("entre %d y %d dio %d\n", s,e,st[i]);
	return st[i];
}

int update( int s , int e , int pos , char c, int i)
{
	if ( s > pos || e < pos ) {return st[i];}
	if ( s == pos && s == e )
	{
		int aux = (int)( c - 'a' );
		st[i] = 1 << aux;
	//	printf("con %d y %d dio %d\n", s,e,st[i]);
		return st[i];
	}
	int m = ( s + e )/2;
	st[i] = update( s , m , pos , c , 2*i+1) | update( m+1,e,pos,c,2*i+2);
	//printf("con %d y %d dio %d\n", s,e,st[i]);
	return st[i];
}

int get_val( int s , int e , int qs , int qe , int i )
{
	if ( s > qe || e < qs ) return 0;
	if ( s >= qs && e <= qe ) return st[i];
	int m = ( s + e ) / 2;
	int ret = get_val(s,m,qs,qe,2*i+1) | get_val(m+1,e,qs,qe,2*i+2);
	return ret;
}

int main()
{
	scanf("%s",w);
	n = strlen(w);
	make_st(0,n-1,0);
	int q, aux, a1, a2;
	char c;
	ri(q);
	while( q-- )
	{
		//printf("\n");
		ri(aux);
		if (aux == 1)
		{
			//printf("UPDATE\n");
			scanf("%d %c", &a1, &c);
			a1--;
			update(0,n-1,a1,c,0);
		}
		else
		{
			scanf("%d %d", &a1, &a2);
			a1--;a2--;
			//printf("%d %d\n", a1,a2);
			int ans = get_val(0,n-1,a1,a2,0);
			//printf("%d\n", ans);
			ans = getcont(ans);
			printf("%d\n", ans);
		}
	}

	return 0;
}