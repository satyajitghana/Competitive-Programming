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

int main() {
    fun();
int t;
cin>>t;
//cout<<t;
while(t--)
{
    int n;
    cin>>n;
  //  cout<<n;
    vector<int>adj[n+1];
    int *indegree=new int[n+1];
    for(int i=0;i<=n;i++)
    {
        indegree[i]=0;
    }
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        indegree[v]++;
       adj[u].push_back(v);
    }
    int count=0;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(indegree[i]==0&&count==1)
        {
         ans++;
        }
        else if(indegree[i]==0)
        {
            count=1;
        }
    }
    cout<<ans<<endl;
    delete [] indegree;
}
}
  
