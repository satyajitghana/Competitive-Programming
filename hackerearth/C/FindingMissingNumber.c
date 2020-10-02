
#include <stdio.h>
 
int pickMissNumber(int *arr1, int ar_size) 
{
    int i, sum = 0, n = ar_size + 1; 
    for(i = 0; i < ar_size; i++)
	{
        sum = sum + arr1[i];
    }
   
    return (n*(n+1))/2 - sum;
}
 
int main()
{
    int i;
    int arr1[] = {1, 3, 4, 2, 5, 6, 9, 8};
 
    int ctr = sizeof(arr1)/sizeof(arr1[0]);
    printf("The given array is :  ");

	for(i = 0; i < ctr; i++)
	{
	printf("%d  ", arr1[i]);
    } 
    printf("\n");
 
 printf("The missing number is : %d \n", pickMissNumber(arr1, ctr));
 return 0;
}

/* Sample Output:_

The given array is :  1  3  4  2  5  6  9  8  
The missing number is : 7 */