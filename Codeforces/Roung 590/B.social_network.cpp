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
#include <list>

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
list<int> q;
stack<int> s;
map<int,int> mp;

int main()
{
	int n,k,aux;
	rii(n,k);
	FOR(i,0,n)
	{
		ri(aux);
		if ( q.size() < k )
		{
			if ( mp.find( aux ) == mp.end() || mp[aux] == 0 )
			{
				mp[aux] = 1;
				q.push_front( aux );
			}
		}
		else if ( mp[aux] == 0 )
		{
			mp[q.back()] = 0;
			q.pop_back();
			mp[aux] = 1;
			q.push_front(aux);
		}
	}
	printf("%d\n",(int)q.size() );
	for ( int x : q )
	{
		printf("%d ",x );
	}
	printf("\n");
	return 0;
}