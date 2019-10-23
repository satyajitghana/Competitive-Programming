#include <bits/stdc++.h>

using namespace std;

int main() {
	int t,n,s;
	cin>>t;
	vector<int>v;
	for(int i=0;i<t;i++){
		cin>>n;
			while(n>0){
				s=n%10;
				n=n/10;
				v.push_back(s);
			}
		cout<<v[0]+v[v.size()-1]<<endl;
		v.clear();
	}
	return 0;
}

