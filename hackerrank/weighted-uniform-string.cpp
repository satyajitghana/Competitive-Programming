#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main()
{
    string s;
    cin >> s;
    map <long long int,int> m;
    long long int a[26];
    for(int i=0;i<26;i++)
        a[i]=0;
    int count=0;
    int x= s[0]-97;
    m[x+1]=1;
    for(int i=1;i<s.size();i++)
    {
        int x= s[i]-97;
        if(s[i]==s[i-1] && count>=0)
        {
            count+=1;
            m[(x+1)*(count+1)]=1;
        }
        else
        {
            m[x+1]=1;
            count=0;
        }
    }
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        long long int x;
        cin >> x;
        if(m[x]==1)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
