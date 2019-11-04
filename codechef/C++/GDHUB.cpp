#include<bits/stdc++.h>
using namespace std;

#define modulo 1000000007
long long dp[1008][1008];

int main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n, k;
    cin >> n >> k;
    int x;
    map<int, int> m;
    for(int i = 0; i < n; i++)  {
        cin >> x;
        m[x]++;
    } 
    vector<long long> v;
    for(auto i = m.begin(); i != m.end(); i++)  {
        v.push_back(i->second);
    }
    for(int i = 0; i < v.size(); i++)   {
        for(int j = 1; j <= v.size(); j++)  {
            dp[i][j] = 0;
        }
    }
    for(int i = 0; i < v.size(); i++)   {
        dp[i][0] = 1;
    }
    dp[0][1] = v[0];
    for(int i = 1; i < v.size(); i++)   {
        for(int j = 1; j <= v.size(); j++)  {
            dp[i][j] += dp[i - 1][j];
            dp[i][j] = dp[i][j] % modulo;
            dp[i][j] += (dp[i - 1][j - 1]) * v[i];
            dp[i][j] = dp[i][j] % modulo;
        }
    }
    long long ans[v.size() + 1];
    ans[0] = 1;
    for(int i = 1; i <= v.size(); i++)   {
        ans[i] = ans[i - 1] + dp[v.size() - 1][i];
        ans[i] = ans[i] % modulo;
    }
    /*for(int i = 0; i < v.size(); i++)   {
        for(int j = 0; j <= v.size(); j++)  {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    for(int i = 0; i <= v.size(); i++)  {
        cout << ans[i] << " ";
    }
    cout << "\n";*/
    if(k <= v.size())   {
        cout << ans[k];
    }
    else    {
        cout << ans[v.size()];
    }
    return 0;
}
