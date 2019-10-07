#include<stdio.h>
int main()
{
int N,r;
scanf("%d%d",&N,&r);
while(N--)
{
int R;
scanf("%d",&R);
if(R>=r)
printf("Good boi\n");
else printf("Bad boi\n");
}return 0;
}
