Problem Statement : https://codeforces.com/contest/1154/problem/A

#include<bits/stdc++.h>
 
#define ll long long
 
using namespace std;
 
int main()
{
    vector<int> a(4);
	for (int i = 0; i < 4; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	cout << a[3] - a[2] << " " << a[3] - a[1] << " " << a[3] - a[0] << endl;
 
 
    return 0;
}
