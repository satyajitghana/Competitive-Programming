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
    int t;
    cin >> t;
    while(t--)  {
        long long n, m;
        cin >> n >>  m;
        long long array[10];
        long long sum = 0;
        for(int i = 0; i < 10; i++)  {
            array[i] = (m * (i+1)) % 10;
            sum += array[i];
        }
        long long y = n/m;
        long long ans = (y/10) * sum;
        y = y % 10;
        for(int i = 0; i < y; i++)  {
            ans += array[i];
        }
        cout << ans << "\n";

    }
    return 0;
}