#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
void fun()
{
    #ifndef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
    #endif
}

int main() {
    //fun();
int n;
int t;
cin>>t;
while(t--)
    {
          cin>>n;
vector<int>v(n+1);
for(int i=1;i<=n;i++)
{
int temp=i;
// for(int j=2;j*j<=i;j++)
// {
//     if(temp%j==0)
//     {
//         while(temp%j==0)
//         {
//             temp/=j;
//         }
//     }
// }
v[i]=temp;
}
vector<int>B(n+1);
for(int i=1;i<=n;i++)
{
    cin>>B[i];
}
bool ans=true;
for(int i=1;i<=n;i++)
{
    if(B[i]==v[i]||B[i]==1)
    {
        continue;
    }
    else
    {
        if((__gcd(B[i],v[i])!=B[i]))
        {
            ans=false;
            break;
        }
    }
}
if(ans)
{
    cout<<"YES"<<endl;
}
else
{
    cout<<"NO"<<endl;

    }
  }
}
  
