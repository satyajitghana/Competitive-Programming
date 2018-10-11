#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int m;
    cin>>m;
    int b[m];
    int mn=10001;
    int mx=1;
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
        if(b[i]<mn)
            mn=b[i];
        if(b[i]>mx)
            mx=b[i];
    }
    int hash_b[mx-mn+1];
    int hash_a[mx-mn+1];
    int hash_ans[mx-mn+1];
    for(int i=0;i<mx-mn+1;i++)
    {
        hash_a[i]=0;
        hash_b[i]=0;
        hash_ans[i]=0;
    }
    for(int i=0;i<m;i++)
    {
        int x = b[i]-mn;
        hash_b[x]+=1;
    }
    for(int i=0;i<n;i++)
    {
        int x = a[i]-mn;
        hash_a[x]+=1;
    }
    for(int i=0;i<mx-mn+1;i++)
    {
        hash_ans[i]=hash_b[i]-hash_a[i];
        //cout<<i+mn<<" "<<hash_ans[i]<<" "<<hash_a[i]<<" "<<hash_b[i]<<endl;
    }
    for(int i=0;i<mx-mn+1;i++)
    {
        int x = i+mn;
        if(hash_ans[i]!=0)
            cout<<x<<" ";
    }
    return 0;
}
