#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector < vector <int> > aj;
    for(int a = 0; a < n+1; a++)
    {
        vector <int> row;
        aj.push_back(row);
        aj[a].push_back(0);
    }
    for(int a = 0; a < m; a++)
    {
        int u, v;
        cin >> u >> v;
        aj[v].push_back(u);
        aj[u][0]++;
    }
    deque <int> q;
    for(int a = 1; a < n+1; a++)
    {
        if(aj[a][0]==0)
        {
            aj[a][0] = -1;
            q.push_front(a);
        }
    }
    deque <int> res;
    vector <int> typ;
    int steps = 0;
    while(res.size()<n)
    {
        if(q.size()>1)
        {
            typ.push_back(2);
            for(int a = 1; a < aj[q.back()].size(); a++)
            {
                aj[aj[q.back()][a]][0]--;
                if(aj[aj[q.back()][a]][0] == 0)
                {
                    aj[aj[q.back()][a]][0] = -1;
                    q.push_front(aj[q.back()][a]);
                }
            }
            res.push_back(q.back());
            q.pop_back();
            for(int a = 1; a < aj[q.back()].size(); a++)
            {
                aj[aj[q.back()][a]][0]--;
                if(aj[aj[q.back()][a]][0] == 0)
                {
                    aj[aj[q.back()][a]][0] = -1;
                    q.push_front(aj[q.back()][a]);
                }
            }
            res.push_back(q.back());
            q.pop_back();
        }
        else if(q.size()==1)
        {
            typ.push_back(1);
            for(int a = 1; a < aj[q.back()].size(); a++)
            {
                aj[aj[q.back()][a]][0]--;
                if(aj[aj[q.back()][a]][0] == 0)
                {
                    aj[aj[q.back()][a]][0] = -1;
                    q.push_front(aj[q.back()][a]);
                }
            }
            res.push_back(q.back());
            q.pop_back();
        }
    }
    cout << typ.size() << endl;
    int ans = 0;
    for(int a = 0; a < typ.size(); a++)
    {
        if(typ[a]==1)
        {
            cout << "1 " << res[ans] << endl;
            ans++;
        }
        else if(typ[a]==2)
        {
            cout << "2 " << res[ans] << " " << res[ans+1] << endl;
            ans+=2;
        }
    }
}
