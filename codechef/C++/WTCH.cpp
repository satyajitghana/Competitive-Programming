#include<bits/stdc++.h>
using namespace std;
string S;
int N;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>N;
		cin>>S;
		int ans=0;
		for(int i=0;i<N;i++)
		{
			if(S[i]!='1'){
			bool l=true,r=true;
			if((i-1)>=0)
			{
				if(S[i-1]=='1')
				{
					l=false;
				}
			}
			if((i+1)<N)
			{
				if(S[i+1]=='1')
				{
					l=false;
				}
			}
			if(l&&r)
			{
				S[i]='1';
				//cout<<i<<" ";
				ans++;
			}}
		}
		cout<<ans<<"\n";
	}
	return 0;
}