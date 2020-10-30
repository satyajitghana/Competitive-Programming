#include <bits/stdc++.h>
using namespace std;
int main()
{
 int n,k,a,b;cin>>n>>k;
 vector<pair<int,int>>v;
 for(int i=0;i<n;i++)
 {
     cin>>a>>b;
     v.push_back(make_pair(a,b));

 }
 sort(v.begin(),v.end());
 reverse(v.begin(),v.end());
 int sum=0;
 int h=0;
 for(int i=0;i<n;i++)
 {
     if(v[i].second==0)
     sum=sum+v[i].first;
     else if(h<k)
     {h++;
     sum=sum+v[i].first;}
     else{
         sum=sum-v[i].first;
     }
}
 cout<<sum;

}

