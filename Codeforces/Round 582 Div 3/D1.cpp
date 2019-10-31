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
    int n, k;
    cin >> n >> k;
    long long array[n];
    for(int i = 0; i < n; i++)  {
        cin >> array[i];
    }
    sort(array, array + n);
    vector<long long> v[200005];
    for(int i = 0; i < n; i++)  {
        v[array[i]].push_back(0);
        int x = 1;
        while(array[i] != 0)    {
            v[array[i] / 2].push_back(x);
            x++;
            array[i] = array[i] / 2;    
        }
    }
    vector<long long> ans;
    for(int i = 200003; i >= 0; i--)    {
        if(v[i].size() >= k)    {
            sort(v[i].begin(), v[i].end());
            int temp = 0;
            for(int j = 0; j < k; j++)  {
                temp += v[i][j];
            }
            ans.push_back(temp);
        }
        
    }
    sort(ans.begin(), ans.end());
    cout << ans[0];
    return 0;
}