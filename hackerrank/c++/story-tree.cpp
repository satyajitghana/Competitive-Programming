#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int gcd(int a,int b)
{
    if(b>a)
    {
        int t=b;
        b=a;
        a=t;
    }
    if(b==0)
        return a;
    else if(b==1)
        return 1;
    else
        return gcd(b,a-b);
}

void dfs(vector<int> v[],int i,int a[],int score[],int u,int found)
{
    a[i]=1;
    if(found)
        score[i]+=1;
    for(int j=0;j<v[i].size();j++)
    {
        if(a[v[i][j]]==0)
        {
            if(v[i][j]==u)
                found=1;
            dfs(v,v[i][j],a,score,u,found);
        }
    }
}

int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        vector <int> v[n+1];
        int a[n+1];
        int score[n+1];
        for(int i=1;i<=(n-1);i++)
        {
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
            a[i]=0;
            score[i]=0;
        }
        a[n]=0;
        score[n]=0;
        int g,k;
        cin>>g>>k;
        int ans=0;
        for(int i=0;i<g;i++)
        {
            int u,z;
            cin>>u>>z;
            dfs(v,z,a,score,u,0);
        }
        for(int i=1;i<=n;i++)
        {
            if(score[i]==k)
                ans+=1;
        }
        if(ans==0)
            cout<<"0/1"<<endl;
        else if(ans==n)
            cout<<"1/1"<<endl;
        else
        {
            int cd=gcd(n,ans);
            cout<<ans/cd<<"/"<<n/cd<<endl;
        }
    }
    return 0;
}
