#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long int q;
    cin>>q;
    while(q--)
    {
        long long int n;
        long long int m;
        cin>>n>>m;
        long long int ans=0;
        long long int a[n];
        long long int pre[n+1];
        pre[0]=0;
        for(long long int i=0;i<n;i++)
        {
            cin>>a[i];
            pre[i+1] = pre[i]+a[i];
        }
        long long int p = m-1;
        long long int b[n+1];
        long long int c[n+1];
        long long int d[n+1];
        for(long long int i=0;i<n+1;i++)
        {
            b[i]=pre[i]%m;
            c[i]=m-b[i];
            d[i]=m-b[i];
        }
        sort(c,c+n+1);
        for(long long int i=1;i<n+1;i++)
        {
            long long int e = p-b[i];
            long long int index=0;
            long long int score=0;
            long long int *up;
            up=upper_bound(c,c+n+1,e);
            if((up-c-1)<0)
                index=i;
            else
                index=up-1-c;
            if(binary_search(d,d+i+1,c[index]))
                score = (c[index]+b[i])%m;
            else
                score = (m+b[i])%m;
            if( score > ans)
                ans=score;
            cout<<b[i]<<" "<<e<<" "<<c[index]<<" "<<score<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}
