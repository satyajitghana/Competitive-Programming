//Numbers on the chessboard
#include <bits/stdc++.h>

using namespace std;

#define pb push_back

#define ll long long int
#define endl "\n"

ll n;

ll getans(ll x,ll y,ll ot,ll et)
{
    
      if(x==1)
        {
              ll a;
               
               if((y%2!=0))
                a=et+((y-1)/2);
               else
                a=ot+((y-2)/2);
                
                return a;
        }
        
        if((x+y)%2==0)
        {
            if(y%2==0)
            {
                
               if((n%2)!=0)
                 return (getans(x-1,y-1,ot,et) + (n/2) + 1);
               else
                   return (getans(x-1,y-1,ot,et) + (n/2));
                   
            }
            else
            {
               ll a;
               
             
                a=et+((y-1)/2);
               
                
              
                
                ll d=n;
                ll g=(x-1)/2;
                ll val=a+g*d;
                 
                return val;
            }
        }
        else
        {
            if(x%2==0)
            {
            
                return (getans(x-1,y+1,ot,et)+floor(n/2));
               
            }
            else
            {
               ll a;
               
             
                a=ot+((y-2)/2);
                
                ll d=n;
                ll g=(x-1)/2;
                
                ll val=a+g*d;
                
                return val;
            }
        }
        
        return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll q;
    cin>>n>>q;
    

      ll ot;
       ll et=1;
       
    if((n%2)==0)
      ot=floor((n*n)/2)+1;
    else
      ot=floor((n*n)/2)+2;
      
    while(q--)
    {
        ll x,y;
        cin>>x>>y;
       
      cout<<getans(x,y,ot,et)<<endl;
      
      
    }
}