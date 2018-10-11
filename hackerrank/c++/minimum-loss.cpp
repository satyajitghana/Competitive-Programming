#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    long long int n;
    cin>>n;
    long long int a[n];
    long long int b[n];
    long long int ans[n];
    map <long long int,long long int> m;
    for(long long int i=0;i<n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
        m[a[i]]=i;
        ans[i]=-1;
    }
    sort(b,b+n);
    for(long long int i=0;i<n;i++)
    {
        long long int * up;
        long long int index;
        up=upper_bound(b,b+n,a[i]);
        index=up-b-2;
        if(index>=0 && m[b[index]]>i)
            ans[i]=a[i]-b[index];
        //cout<<ans[i]<<endl;
    }
    sort(ans,ans+n);
    for(long long int i=0;i<n;i++)
    {
        if(ans[i]!=-1)
        {
            cout<<ans[i];
            break;
        }
    }
    return 0;
}
