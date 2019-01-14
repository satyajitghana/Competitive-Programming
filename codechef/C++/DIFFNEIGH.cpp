#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#include<vector>

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll i,j,t,a[50][50];
	// for(i=0;i<50;i++)
	// {
	// 	if(i%4==0)
	// 	{
	// 		for(j=0;j<50;j++)
	// 			if(j%4==1||j%4==2)
	// 				a[j][i]=1;
	// 		else
	// 				a[j][i]=2;			
	// 	}
	// 	else if(i%4==1)
	// 	{
	// 		for(j=0;j<50;j++)
	// 			if(j%4==1||j%4==0)
	// 				a[j][i]=3;
	// 		else
	// 				a[j][i]=4;			
	// 	}
	// 	else if(i%4==2)
	// 	{
	// 		for(j=0;j<50;j++)
	// 			if(j%4==3||j%4==0)
	// 				a[j][i]=1;
	// 		else
	// 				a[j][i]=2;			
	// 	}
	// 	else if(i%4==3)
	// 	{
	// 		for(j=0;j<50;j++)
	// 			if(j%4==1||j%4==0)
	// 				a[j][i]=4;
	// 		else
	// 				a[j][i]=3;			
	// 	}
	// }
    for (int i = 0 ; i < 50 ; i++) {
            for (int j = i ; j < 50 ; j++) {
                if (i%2 == 0) {
                    if ((j-i)%4 == 0 || (j-i)%4 == 1) {
                        a[i][j] = 1;
                    } else {
                        a[i][j] = 2;
                    }
                } else {
                    if ((j-i)%4 == 0 || (j-i)%4 == 1) {
                        a[i][j] = 3;
                    } else {
                        a[i][j] = 4;
                    }
                }
            }
        }
    for (int j = 0 ; j < 50 ; j++) {
            for (int i = j+1 ; i < 50 ; i++) {
                if (j%2 == 0) {
                    if ((i-j-1)%4 == 0 || (i-j-1)%4 == 1) {
                        a[i][j] = 2;
                    } else {
                        a[i][j] = 1;
                    }
                } else {
                    if ((i-j-1)%4 == 0 || (i-j-1)%4 == 1) {
                        a[i][j] = 4;
                    } else {
                        a[i][j] = 3;
                    }
                }
            }
        }
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		if(n==1&&m==1)
			cout<<1<<endl<<1<<endl;
		else if(n==1&&m==2)
			cout<<1<<endl<<"1 1"<<endl;
		else if(n==1&&m==3)
			cout<<2<<endl<<"1 1 2"<<endl;
		else if(n==2&&m==1)
			cout<<1<<endl<<1<<endl<<1<<endl;
		else if(n==2&&m==2)
			cout<<2<<endl<<"1 1"<<endl<<"2 2"<<endl;
		else if(n==2&&m==3)	
			cout<<3<<endl<<"1 1 2"<<endl<<"2 3 3"<<endl;
		else if(n==3&&m==2)
			cout<<3<<endl<<"1 2"<<endl<<"1 3"<<endl<<"2 3"<<endl;
		else if(n==1&&m>3)
		{
			cout<<2<<endl;
			for(i=0;i<m;i++)
				if(i%4==0||i%4==1)
					cout<<1<<" ";
				else
					cout<<2<<" ";
			cout<<endl;
		}
		else if(n>=3&&m==1)
		{
			cout<<2<<endl;
			for(i=0;i<n;i++)
				if(i%4==0||i%4==1)
					cout<<1<<endl;
				else
					cout<<2<<endl;
			cout<<endl;
		}
		else 
		{
			cout<<4<<endl;
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
					cout<<a[i][j]<<" ";
				cout<<endl;
			}
		}
	}
	return 0;
}