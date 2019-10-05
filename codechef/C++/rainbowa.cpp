#include <stdio.h>

int main(void) {
	// your code goes here
	int t, n; 
	scanf("%d",&t) ;
	while(t--) 
	{
	    scanf("%d",&n) ;
	    int a[n],i,j,c=0;
	    for(i=0;i<n; i++)
	    scanf("%d",&a[i]);
	    int b[7]={0};
	    for(i=0;i<n; i++)
	    {
	        if(a[i]==1 && (a[i+1]==1||a[i+1]==2))
	        ++b[0];
	        else if(a[i]==2 && (a[i-1]==1||a[i-1]==2))
	        ++b[1];
	        else if(a[i]==3 && (a[i-1]==3||a[i-1]==2))
	        ++b[2];
	        else if(a[i]==4 && (a[i-1]==3||a[i-1]==4))
	        ++b[3];
	        else if(a[i]==5 && (a[i-1]==4||a[i-1]==5))
	        ++b[4];
	        else if(a[i]==6 && (a[i-1]==5||a[i-1]==6))
	        ++b[5];
	        else if(a[i]==7 && (a[i-1]==6||a[i-1]==7))
	        ++b[6];
	        else if(a[i]!=7 && a[i-1]==7)
	        break; 
	    }
	    for(j=i;j<n;j++)
	    {
	        if(a[j]==6 && (a[j-1]==7||a[j-1]==6))
	        --b[5];
	        else if(a[j]==5 && (a[j-1]==6||a[j-1]==5))
	        --b[4];
	        else if(a[j]==4 && (a[j-1]==5||a[j-1]==4))
	        --b[3];
	        else if(a[j]==3 && (a[j-1]==4||a[j-1]==3))
	        --b[2];
	        else if(a[j]==2 && (a[j-1]==3||a[j-1]==2))
	        --b[1];
	        else if(a[j]==1 && (a[j-1]==1||a[j-1]==2))
	        --b[0];
	    }
	    for(i=0;i<7;i++)
	    {
	        if(i<6 && b[i]!=0)
	        {
	            c=1;
	            break; 
	        }
	        else if(i==6 && b[i]==0)
	        c=1;
	    }
	    if(c==0&&a[0]==1) 
	    printf("yes\n");
	    else 
	    printf("no\n");
	}
	return 0;
}

