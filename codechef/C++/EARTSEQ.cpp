#include <bits/stdc++.h> 
#define pb push_back 
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define MAX 1000

using namespace std; 

vector<int> primes;

void sieve(int n) { 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) { 
        if (prime[p] == true) {  
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
          primes.pb(p); 
}

bool g[MAX][MAX] = {};
  
void edge(int a, int b) { 
    g[a][b] = true;
    g[b][a] = true; 
} 
  
int solve(int u, int size, int flag) {
    // cout << "*" << u << "*";
    for (int i = 0 ; i < size ; i++) {
        if (g[u][i] == false && u != i && (u != 1 && i != 1)) {
            if (!flag)
            cout << primes[i] * primes[u] << " ";
            else {
                int ans = 2 * primes[i] * primes[u];
                //if (ans%3 == 0)
                //    cout << 5 * ans << " ";
                //else
                    cout << 2 * ans << " ";
            }
            edge(i, u);
            return i;
        }
    }
} 

int main() { 
    fastio

    sieve(40000);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        if (N > 3333) {
        int n = sqrt(8 * N);

        int cnt = 0;

        for (int i = 0 ; i < MAX ; i++) {
            for (int j = 0 ; j < MAX ; j++) {
                g[i][j] = false;
            }
        }

        int i;
        for (i = 0 ; i < n-1 ; i++) {
            edge(i, i+1);
            cout << primes[i] * primes[i+1] << " ";
            cnt++;
        }

        int next = i;

        while (cnt != N-1) {
            next = solve(next, n, false);
            cnt++;
        }

        // cout << 2 * primes[next];
        solve(next, n, true);
        }
        else {
            for (int i = 0 ; i < N ; i++) {
                cout << primes[i%N] * primes[(i+1)%N] << " ";
            }
        }

        cout << endl;
    } 

    return 0; 
} 