#include <vector>
#include <iostream>
using namespace std;

void dfs(vector <int> g[],int a[],int index1,int index2,int * p,int * found)
{
    a[index2]=1;
    //cout<<index2<<endl;
    if(index2 == index1)
    {
       // cout<<index2<<"add"<<endl;
        *found=1;
        return;
    }
    else
    {
        if(g[index2].size() > 2)
            (*p)+=1;
        for(int i=0;i<g[index2].size();i++)
        {
            if((a[g[index2][i]] == 0) && (*found==0))
            {
                dfs(g,a,index1,g[index2][i],p,found);
            }
        }
        if((g[index2].size() > 2)&& (*found==0))
        {
            (*p)-=1;
            //cout<<index2<<"bre"<<endl;
        }
    }
}


int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        char a[n][m];
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            for(int j=0;j<m;j++)
            {
                a[i][j]=s[j];
            }
        }
        /*for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<a[i][j];
            }
            cout<<endl;
        } */
        int guess;
        cin>>guess;
        vector <int> g[n*m];
        //g[0].push_back(10);
        //cout<<g[0][0];
        int index1=0;
        int index2=0;
        int coun=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]=='*')
                    index1=coun;
                else if(a[i][j]=='M')
                    index2=coun;

                if(a[i][j] != 'X')
                {
                    if(j != 0)
                    {
                        if( (a[i][j-1] == '.') || (a[i][j-1] == '*') || (a[i][j-1] == 'M') )
                            g[coun].push_back(coun-1);
                        //cout<<coun<<"4"<<endl;
                    }
                    if(j!=(m-1))
                    {
                        if( (a[i][j+1] == '.') || (a[i][j+1] == '*') || (a[i][j+1] == 'M') )
                            g[coun].push_back(coun+1);
                        //cout<<coun<<"3"<<endl;
                    }
                    if(i!=0)
                    {
                        if( (a[i-1][j] == '.') || (a[i-1][j] == '*') || (a[i-1][j] == 'M') )
                            g[coun].push_back(coun-m);
                        //cout<<coun<<"2"<<endl;
                    }
                    if(i!=(n-1))
                    {
                        if( (a[i+1][j] == '.') || (a[i+1][j] == '*') || (a[i+1][j] == 'M') )
                            g[coun].push_back(coun+m);
                        //cout<<coun<<"1"<<endl;
                    }
                 }
                coun+=1;
            }
            //cout<<endl<<coun<<endl;
        }
        /*for(int i=0;i<coun;i++)
        {
            cout<<i<<" ";
            for(int j=0;j<g[i].size();j++)
            {
                cout<<g[i][j];
            }
            cout<<endl;
        }*/

        int visit[coun];
        for(int i=0;i<coun;i++)
        {
            visit[i]=0;
        }
        int c=0;
        int f=0;
        if((g[index2].size() > 1)&&(g[index2].size() <= 2))
        {
            c+=1;
        }
        dfs(g,visit,index1,index2,&c,&f);
        //cout<<c<<"end"<<endl;
        if(c==guess)
            cout<<"Impressed"<<endl;
        else
            cout<<"Oops!"<<endl;
    }
    return 0;
}
