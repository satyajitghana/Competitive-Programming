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
const int maxN = 1e5+5; // CAMBIAR ESTE

// GJNM
char path[2][2*maxN];
int n;
bool ans;

void get_path( char from , int i , int j )
{
	//printf("%d %d \n", i,j);
	if ( i == -1 || i == 2 ) return;
	if ( i == 1 && j == n+1 ) 
	{
		ans = true;
		return;
	}
	if ( j > n ) return;
	if ( from == 'i' )
	{
		if ( path[i][j] == '1' || path[i][j] == '2' )
		{
			get_path( 'i' , i , j+1 );
		}
		else
		{
			get_path( 'u' , i+1 , j);
			get_path( 'd' , i-1 , j);
		}
	}
	else if ( from == 'u' )
	{
		if ( path[i][j] == '1' || path[i][j] == '2' ) return;
		get_path('i', i , j+1);
	}
	else
	{
		if ( path[i][j] == '1' || path[i][j] == '2' ) return;

		get_path('i', i , j+1);
	}
}

int main()
{
	int q;
	ri(q);
	while( q-- )
	{
		ans = false;
		ri(n);
		scanf("%s",path[0]+1);
		scanf("%s",path[1]+1);
		if ( path[0][1] == '1' || path[0][1] == '2' )
		{
			get_path('i' , 0 , 2);
		}
		else
		{
			get_path('a' , 1 , 1);
		}
		if ( ans ) printf("YES\n");
		else printf("NO\n");

	}

	return 0;
}