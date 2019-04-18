#include <boost/multiprecision/cpp_int.hpp>
#include <boost/algorithm/string.hpp>
#include <bits/stdc++.h>
#define mod 1000000007
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define pb push_back
#define pop pop_back
#define mp make_pair
#define cint cpp_int
#define fin(ii, nn) for (int i = ii; i < nn; i++)
#define lld long long int

using namespace boost::multiprecision;
using namespace std;

// BFS, C++, taken from GFG : https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/

class Graph{
	list<lld> *edges;

public:
	Graph(lld V) {
	    edges = new list<lld>[V];
    }

	void addEdge(lld u, lld v) {
        edges[u].push_back(v);
		edges[v].push_back(u);
    }
	lld dfs(lld v, lld p, lld x, lld a[]) {

        lld sum = 0;
    
        for (auto it = edges[v].begin() ; it != edges[v].end() ; it++) {
            if (*it != p) {
                sum += dfs(*it, v, x, a);
            }
        }

        sum += a[v];

        return max(sum, -x);
    }
};

int main() {
    fastio

    int T;
    cin >> T;
    while (T--) {
        int N; lld X;
        cin >> N >> X;
        lld A[N+1];
        A[0] = 0l;
        for (lld i = 1 ; i <= N ; i++) {
            cin >> A[i];
            // cout << A[i] << " ";
        }
        // cout << endl;
        // vector <vector <lld> > edges(10005);
        Graph gh(N+1);
        for (int i = 0 ; i < N-1 ; i++) {
            lld u, v;
            cin >> u >> v;
            gh.addEdge(u, v);
            // cout << u << " " << edges[u] << " " << endl;
        }
        lld ans;
        if (N == 1) {
            ans = max(-1l*X, A[1]);
            
        } else {
            ans = gh.dfs(1, 0, X, A);
        }
        cout << ans << endl;
    }

    return 0;
}