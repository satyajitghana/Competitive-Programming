#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define endl "\n"

ll findSubarraySum(ll arr[], ll n, ll sum) 
{ 
    unordered_map<ll, ll> pSum; 
    ll wapas = 0;
    ll csum = 0; 
    for (ll i = 0; i < n; i++) 
    { 
        csum += arr[i]; 
        if (csum == sum)  
            wapas++;         
        if (pSum.find(csum - sum) !=  
                                  pSum.end())  
            wapas += (pSum[csum - sum]); 
        pSum[csum]++; 
    } 
  
    return wapas; 
} 

int main() 
{
    
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
	    ll x,m,i,j,res;
	    cin>>x;
	    ll num[x];
	    ll answer=0,total;
	    for(i=0;i<x;i++)
	        cin>>num[i];
	    total=(x*(x+1))/2;
	    ll sum=5;
	    for(i=0;i<x;i++)
	    {
	        if(num[i]%2==0 && num[i]%4!=0)
	            num[i]=5;
	        else if(num[i]%4==0)
	            num[i]=2;
	        else
	            num[i]=0;
	    }
	   // for(i=0;i<x;i++)
	   // {
	   //     cout<<num[i]<<" ";
	   // }
	   // cout<<endl;
	    answer=findSubarraySum(num,x,sum);
	    //cout<<total<<" "<<answer<<endl;
	    cout<<total-answer<<endl;
	}
	return 0;
}
