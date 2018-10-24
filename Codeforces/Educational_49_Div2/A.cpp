//Palindromic Twist
#include <bits/stdc++.h>

using namespace std;

#define pb push_back

#define ll long long int
#define endl "\n"

bool ispos(string s,ll len)
{
    ll l=0;
    ll r=len-1;
    
    bool f=true;
    
    while(l<=r)
    {
        ll v1=s[l]-'a';
        ll v2=s[r]-'a';
        
        if(s[l]!=s[r])
        {
            if(abs(v1-v2)>2 || abs(v1-v2)==1)
            {
                f=false;
                break;
            }
        }
        
        l++;
        r--;
    }
    
    return f;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll t;
    cin>>t;
    
    while(t--)
    {
        ll l;
        cin>>l;
        
        string s;
        cin>>s;
        
        if(ispos(s,l))
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
}