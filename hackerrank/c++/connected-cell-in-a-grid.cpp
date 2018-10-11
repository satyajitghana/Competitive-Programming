https://www.hackerrank.com/challenges/connected-cell-in-a-grid
#include <vector>
#include <iostream>
using namespace std;

void dfs(vector <int> g[],int a[],int i,int *p)
{
    a[i]=1;
    (*p)+=1;
    for(int j=0;j<g[i].size();j++)
    {
        if((a[g[i][j]] == 0))
        {
            dfs(g,a,g[i][j],p);
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int a[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        vector <int> g[n*m];
        int index1=0;
        int index2=0;
        int coun=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j] == 1)
                {
                    if(j != 0)
                    {
                        if( (a[i][j-1] == '1') )
                            g[coun].push_back(coun-1);
                        if(i != 0)
                        {
                            if( (a[i-1][j-1] == '1') )
                                g[coun].push_back(coun-m-1);
                        }
                        if(i != (n-1))
                        {
                            if( (a[i+1][j-1] == '1') )
                                g[coun].push_back(coun-1+m);
                        }
                    }
                    if(j!=(m-1))
                    {
                        if( (a[i][j+1] == '1'))
                            g[coun].push_back(coun+1);
                        if(i != 0)
                        {
                            if( (a[i-1][j+1] == '1') )
                                g[coun].push_back(coun+1-m);
                        }
                        if(i != (n-1))
                        {
                            if( (a[i+1][j+1] == '1') )
                                g[coun].push_back(coun+1+m);
                        }
                    }
                    if(i!=0)
                    {
                        if( (a[i-1][j] == '1'))
                            g[coun].push_back(coun-m);
                    }
                    if(i!=(n-1))
                    {
                        if( (a[i+1][j] == '1'))
                            g[coun].push_back(coun+m);
                    }
                 }
                coun+=1;
            }
        }
        int visit[coun];
        for(int i=0;i<coun;i++)
        {
            visit[i]=0;
        }
        int ans=0;
        for(int i=0;i<coun;i++)
        {
            int c=0;
            if(visit[i]==0)
            {
                dfs(g,visit,i,&c);
            }
            if(c>ans)
                ans=c;
            cout<<c<<endl;
        }

    }
    return 0;
}
