#include <bits/stdc++.h> 
using namespace std;  
typedef long long int ll; 
int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b); 
} 
ll findlcm(int arr[], int n) 
{ 
    ll ans = arr[0]; 
    for (int i = 1; i < n; i++) 
        ans = (((arr[i] * ans)) / 
                (gcd(arr[i], ans))); 
  
    return ans; 
} 
int main()
{
    int t;cin>>t;while(t--)
    {
        int n;cin>>n;int arr[n];
        for(int i=0;i<n;i++)
        {
            arr[i]=i+1;
        }
        long long int s= findlcm(arr,n);
        cout<<s<<"\n";
    }
}
  

