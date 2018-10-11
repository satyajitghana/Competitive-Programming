#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    vector <int> v[n+1];
    int a[n+1];
    int p[n+1];
    int c[n+1];
    for(int i=1;i<=n;i++)
    {
        a[i]=0;
        p[i]=0;
        c[i]=0;
    }
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    /*for(int i=0;i<v[2].size();i++)
        {
        cout<<v[2][i]<<endl;
    }*/
    queue <int> q;
    stack <int> s;
    q.push(1);
    s.push(1);
    c[1]=1;
    while(!q.empty())
    {
        int x=q.front();
        //cout<<x<<endl;
        for(int i=0;i<v[x].size();i++)
        {
            if(c[v[x][i]]==0)
            {
                q.push(v[x][i]);
                s.push(v[x][i]);
                p[v[x][i]]=x;
                c[v[x][i]]=1;
            }
        }
        q.pop();
    }
    for(int i=1;i<=n;i++)
    {
        int x=s.top();
        int parent=p[x];
        //cout<<x<<parent<<endl;
        a[parent]=a[parent]+a[x]+1;
        s.pop();
    }
    int ans=0;
    for(int i=2;i<=n;i++)
    {
        if(a[i]%2!=0)
            ans+=1;
    }
    cout<<ans;
    return 0;
}
