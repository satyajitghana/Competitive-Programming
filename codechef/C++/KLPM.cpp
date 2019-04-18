#include<bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define LL long long
using namespace std;
short dp[1000][1000];
void init(){
	for(int i=0;i<1000;i++){
		for(int j=0;j<1000;j++)
			dp[i][j]=-1;
	}
}
bool chk(string s,int arr[][2],int i,int j){
	int si=arr[i][1]+arr[j][1]-arr[i][0]-arr[j][0];
	if(dp[arr[i][0]][arr[j][1]-1]==0)
		return 0;
	int a=arr[i][0],b=arr[j][1]-1;
	while(a<b){
		if(s[a]!=s[b]){
			if(dp[arr[i][0]][arr[j][1]-1]==-1 && si==2)
				dp[arr[i][0]][arr[j][1]-1]=0;
			return 0;
		}
		a+=1;
		b-=1;
		if(a==arr[i][1])
			a=arr[j][0];
		if(b==arr[j][0]-1)
			b=arr[i][1]-1;
	}
	if(dp[arr[i][0]][arr[j][1]-1]==-1 && si==2)
		dp[arr[i][0]][arr[j][1]-1]=1;
	return 1;
}
int main(){
    fastio
	string x;
	cin>>x;
	init();
	long n=x.length();
	int arr[n*(n+1)/2][2];
	long k=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<n-i+1;j+=1){
			arr[k][0]=j;
			arr[k++][1]=j+i;
		}
	}
	n=n*(n+1)/2;
	LL count=0;
	for(long i=0;i<n;i++){
		for(long j=i+1;j<n;j++){
			if(arr[i][1]<=arr[j][0])
				count+=chk(x,arr,i,j);
			if(arr[i][0]>=arr[j][1])
				count+=chk(x,arr,j,i);
		}
	}
	cout<<count<<endl;
}