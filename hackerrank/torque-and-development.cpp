#include <vector>
#include <iostream>

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
    int q;
    cin>>q;
    while(q--)
    {
        long long int n,m,cr,cl;
        cin>>n>>m>>cl>>cr;
        vector <int> v[n+1];
        int a[n+1];
        //0-not visited
        //1-visited
        for(long long int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
            //cout<<v[x][0];
        }
        //printing
        /*for(int i=1;i<=n;i++)
        {
            for(int j=0;j<v[i].size();j++)
            {
                cout<<v[i][j];
            }
            cout<<endl;
        }*/
        for(int i=0;i<=n;i++)
            a[i]=0;
        int comp=0;
        long long int ans2=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0)
            {
                int u=1;
                int *z=&u;
                dfs(v,i,a,z);
                comp+=1;
                ans2+=(cr*((*z)-1));
                //cout<<*z<<endl;
            }
        }
        //cout<<comp;
        long long int ans1=cl*n;
        ans2+=(comp*cl);
        if(cl<cr || m==0)
            cout<<ans1<<endl;
        else
            cout<<ans2<<endl;
    }
    return 0;
}
