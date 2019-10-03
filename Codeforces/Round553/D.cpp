#include<bits/stdc++.h>
 
#define ll long long
 
 
using namespace std;
 
int main()
{
    ll n,a,b,ans = 0;
    cin>>n;
    ll arr[n];
 
    for(int i=0;i<n;++i){
        cin>>a>>b;
        ans += b * n - a;
        arr[i] = a - b;
    }
 
    sort(arr,arr + n);
 
    for(int i=0;i<n;++i){
        ans += arr[i] * (n - i);
    }
 
    cout<<ans<<endl;
    return 0;
}
