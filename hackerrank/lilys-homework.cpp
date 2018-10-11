#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    long long int n;
    cin>>n;
    map <long long int,long long int> a;//<value,index>
    long long int inp[n];
    long long int b[n];
    map <long long int,long long int> d;
    long long int c[n];
    long long int inp_c[n];
    for(long long int i=0;i<n;i++)
        {
        long long int x;
        cin>>x;
        a[x]=i;
        d[x]=i;
        b[i]=x;
        inp[i]=x;
        inp_c[i]=x;
    }
    sort(b,b+n);
    long long int j=0;
    for(long long int i=(n-1);i>=0;i--)
        {
        c[j]=b[i];
        j+=1;
        //cout<<b[i]<<endl;
    }
    long long int sw1=0;
    long long int sw2=0;
    for(long long int i=0;i<n;i++)
        {
        if(inp[i]!=b[i])
            {
            long long int t=a[b[i]];
            a[b[i]]=a[inp[i]];
            a[inp[i]]=t;
            inp[t]=inp[i];
            sw1+=1;
        }
    }
    //cout<<sw1<<endl;
    for(long long int i=0;i<n;i++)
        {
        if(inp_c[i]!=c[i])
            {
            long long int t=d[c[i]];
            d[c[i]]=d[inp_c[i]];
            d[inp_c[i]]=t;
            inp_c[t]=inp_c[i];
            sw2+=1;
        }
    }
    //cout<<sw2<<endl;
    if(sw1<sw2)
        cout<<sw1;
    else
        cout<<sw2;
    return 0;
}
