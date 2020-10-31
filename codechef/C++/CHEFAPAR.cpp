#include <iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	 {   int n,sum=0,f=0;
	     cin>>n;
	     int N[n];
          for(int j=0;j<n;j++)
           {

             cin>>N[j];
           }
           for(int k=0;k<n;k++)
             {
               if(N[k]==0)
               {
               sum+=1100;
               f++;
               }
               else if(N[k]==1&&f>0)
               {
                 sum=sum+100;
               }




             }



      cout<<sum<<"\n";
	 }

	return 0;
}
