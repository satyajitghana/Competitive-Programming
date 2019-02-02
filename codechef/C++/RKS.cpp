#include <bits/stdc++.h> 
using namespace std;
 
int main() {
	int T,N,K;
	cin>>T;
	while(T--)
	{
		cin>>N>>K;
		int i=0,j=0,k=0;
		int row[N+1], col[N+1],rol[N+1],cow[N+1];
		for(int i=1;i<=N;i++)
		{
			row[i]=0;
			col[i]=0;
		}
		while(K--)
		{   int a,b;
			cin>>a>>b;
			row[a]=1;
			col[b]=1;
		}
		for(int i=1;i<=N;i++)
		{
			if(row[i]==0)
			{
				cow[j]=i;
				j++;
			}
			if(col[i]==0)
			{
				rol[k]=i;
				k++;
			}
		}
		cout<<j<<" ";
		for(int i=0;i<j;i++)
		{
			cout<<cow[i]<<" "<<rol[i]<<" ";
		}
 
 cout << endl;
 
 
	}
	return 0;
}