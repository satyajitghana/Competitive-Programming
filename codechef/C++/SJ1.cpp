#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using namespace std;
#define cint cpp_int
#define ll unsigned long long

vector<ll> fun(ll root,unordered_map<ll,vector<ll> > &mp,ll arrv[],ll visisted[],ll arrm[],vector<ll> &leaves){
      vector<ll> vx=mp[root];
      visisted[root]=1;
      vector<ll> smallans;
      vector<ll> residue;
      bool m=true;
      for(ll i=0;i<vx.size();i++){
          if(visisted[vx[i]]==1){ continue; }
          m=false;
          smallans=fun(vx[i],mp,arrv,visisted,arrm,leaves);
          for(ll j=0;j<smallans.size();j++){
              if(arrv[root]%arrm[smallans[j]]==0){
                  residue.push_back(smallans[j]);
              }
          }
      }
      if(m==true){
          if(arrv[root]%arrm[root]==0){
              residue.push_back(root);
          }
          leaves.push_back(root);
      }
      return residue;
}
int main() {
     ll t,n,x,u,p;
     ll arr[100001];
     ll arrm[100001];
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
      cin>>t;
     while(t--){
         cin>>n;
         unordered_map<ll,vector<ll>>mp;
         for(ll i=1;i<=n-1;i++){
             cin>>u>>p;
             if(mp.count(u)==0){
                 vector<ll> v;
                 v.push_back(p);
                 mp[u]=v;
             }
             else{
                 vector<ll> dc=mp[u];
                 dc.push_back(p);
                 mp[u]=dc;
             }
             if(mp.count(p)==0){
                 vector<ll> v;
                 v.push_back(u);
                 mp[p]=v;
             }
             else{
                 vector<ll> dc=mp[p];
                 dc.push_back(u);
                 mp[p]=dc;
             }
         }
         for(int i=1;i<=n;i++){
             cin>>arr[i];
         }
         for(int i=1;i<=n;i++){
             cin>>arrm[i];
         }
         ll visisted[100001]={0};
         vector<ll> leaves;
         vector<ll> ans;
         ans=fun(1,mp,arr,visisted,arrm,leaves);
         ll ans_arr[100001]={0};
         for(int ty=0;ty<ans.size();ty++){
             ans_arr[ans[ty]]++;
         }
         sort(leaves.begin(),leaves.end());
         for(int ty=0;ty<leaves.size();ty++){
              if(ans_arr[leaves[ty]]==1){
                  cout<<0<<" ";
              }
              else{
                  cint x=arrm[leaves[ty]];
                  cout<<x-1<<" ";
              }
         }
         cout<<"\n";
     }
	return 0;
}