#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        int a[n];
        int b[n];
        int d[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            b[i]=m-a[i];
            d[i]=a[i];
            //cout<<i+1<<" "<<a[i]<<endl;
        }
        sort(d,d+n);
        int index1=0;
        int index2=0;
        int num=0;
        for(int i=0;i<n;i++)
        {
            //cout<<i+1<<" "<<b[i]<<" "<<binary_search(d,d+n,b[i])<<endl;
            if(binary_search(d,d+n,b[i]))
            {
                index1 = i+1;
                num = b[i];
                if(!(m%b[i] ==0 && b[i]==m/2))
                    break;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(a[i]==num && i!=index1-1)
            {
                index2=i+1;
                break;
            }
        }
        if(index1>index2)
        {
            int t=index1;
            index1=index2;
            index2=t;
        }
        cout<<index1<<" "<<index2<<endl;
    }
    return 0;
}

