#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long int n;
  cin>>n;
  string s = to_string(n);
  int min1=INT_MAX;
  int b=0;
  for(int i=0;i<s.size();i++)
  {
    for(int j=0;j<s.size();j++)
    {
      string s2 = s;
      int pos=0;
      if(i==j)
      continue;
      for(int k=i;k<s2.size()-1;k++)
      {
        swap(s2[k],s2[k+1]);
        ++pos;
      }
      for(int k=j-(i<j);k<s2.size()-2;k++)
      {
        swap(s2[k],s2[k+1]);
        ++pos;
      }
      int m = 0;
      for(int k=0;k<s2.size();k++)
        if(s2[k]!='0')
        {
          m=k;
          break;
        }
      for(int k=m;k>=1;k--)
      {
        swap(s2[k],s2[k-1]);
        ++pos;
      }
      if(atoll(s2.c_str())%25==0)
      {
      min1=min(min1,pos);

      }
    }
  }
  if(min1==INT_MAX)
    cout<<-1<<"\n";
  else
    cout<<min1<<"\n";
}
