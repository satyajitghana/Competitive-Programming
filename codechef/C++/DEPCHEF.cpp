#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a,d;
		for(int i=0;i<n;i++){
			int y;
			cin>>y;
			a.push_back(y);
		}
		for(int i=0;i<n;i++){
			int y;
			cin>>y;
			d.push_back(y);
		}
		int k=-1;
		for(int i=0;i<n;i++){
			if(i==0){
				if(d[i]>a[n-1]+a[i+1]){
				k=d[i];
				}
			}
			else{
				if(d[i]>a[(i+1)%n]+a[i-1]){
					if(k<d[i])
					k=d[i];
 
				}
			}
		}
		cout<<k<<"\n";
	}
	return 0;
}