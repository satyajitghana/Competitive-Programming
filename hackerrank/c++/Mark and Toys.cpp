#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;int prices[n];
    for(int i=0;i<n;i++)
    {
        cin>>prices[i];
    }
    sort(prices,prices+n);
    int sum=0;
    int count=0;
     for(int i=0;i<n;i++)
     {
         sum=sum+prices[i];
         if(sum<=k)
         {
             count++;
         }
         else
         break;

     }
     cout<<count;
}
