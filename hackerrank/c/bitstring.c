#include<stdio.h>
#define MAX 100

/*int recursion(char* c, int *p) {
	if (*c != '\n') { recursion(getchar());}
}*/

int main() {
	int c,store[MAX]={},i,j;
	i=0;
	j=0;
	while ((c=getchar()) != '\n') {
	if (c=='0') {
		store[i] = j; i++;
	//printf("%d",j); i++;
	} j++; if(c!='0') i++;
	}
	for (int k = 0 ; k < i ; k++) 
	printf("%d ", store[k]-1);
	printf("\n");
}
