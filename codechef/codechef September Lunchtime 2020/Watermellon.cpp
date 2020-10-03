#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
void fun()
{
    #ifndef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
    #endif
}
int Dynammic(ll sum,ll i,ll n,ll s,vector<int>&dp)
{
    if(s==sum)
    {
        return true;
    }
    if(i>n)
    {
        return false;
    }
    if(s>sum)
    {
        return false;
    }
    if(dp[sum]!=-1)
    {
        return dp[sum];
    }
    dp[sum]=Dynammic(sum,i,n,s+i,dp)||Dynammic(sum,i+1,n,s,dp);
    return dp[sum];
}
int main() {
 //   fun();
ll t;
cin>>t;
ll n;
while(t--)
{
    cin>>n;
    vector<int>v(n+1);
    ll sum=0;
    ll s;
    s=n*(n+1);
    s/=2;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        sum+=v[i];
    }
    if(sum==0)
    {
        cout<<"YES"<<endl;
    }
    else if(sum<0)
    {
        cout<<"NO"<<endl;
    }
    else
    {
   
        vector<int>dp(sum+1,-1);
        if(Dynammic(sum,1,n,0,dp))
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    
    }

}

  
}