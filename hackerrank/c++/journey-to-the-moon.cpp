#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int> v[],int i,int a[],int *z)
{
    //cout<<"ghf"<<v[i].size();
    a[i]=1;
    for(int j=0;j<v[i].size();j++)
    {
        if(a[v[i][j]]==0)
        {
            (*z)+=1;
            dfs(v,v[i][j],a,z);
        }
    }
}

int main()
{
    int n,p;
    cin>>n>>p;
    int a[n],cont[n];
    for(int i=0;i<n;i++)
        cont[i]=0;
    vector <int> v[n];
    for(int i=0;i<p;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=0;i<n;i++)
        a[i]=0;
    int comp=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            int u=1;
            int *z=&u;
            dfs(v,i,a,z);
            cont[comp]=*(z);
            comp+=1;
        }
    }
    long long int ans=0;
    long long int sum=0;
    for(int i=0;i<comp;i++)
    {
        sum+=cont[i];
        //cout<<cont[i]<<cont[j]<<endl;
        ans=ans+(sum*cont[i+1]);
    }
    cout<<ans;
    return 0;
}
