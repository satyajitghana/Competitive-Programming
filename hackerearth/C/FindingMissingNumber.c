
//Find the missing number in the array of 1 to N

//Method 1: This method uses the technique of the summation formula. 

//Algorithm:- 
//Calculate the sum of first n natural numbers as sumtotal= n*(n+1)/2;
//Create a variable sum to store the sum of array elements.;
//Traverse the array from start to end.;
//Update the value of sum as sum = sum + array[i];
//Print the missing number as sumtotal – sum;

//Code:-

#include <stdio.h>

/* getMissingNo takes array and size of array as arguments*/
int getMissingNo(int a[], int n)
{
	int i, total;
	total = (n + 1) * (n + 2) / 2;
	for (i = 0; i < n; i++)
		total -= a[i];
	return total;
}

/*program to test above function */
int main()
{
	int a[] = { 1, 2, 4, 5, 6 };
	int miss = getMissingNo(a, 5);
	printf("%d", miss);
	getchar();
}

OUTPUT:   3

Complexity Analysis: 
Time Complexity: O(n). 
Only one traversal of the array is needed.
Space Complexity: O(1). 
No extra space is needed


//Method 2: This method uses the technique of XOR to solve the problem.
/*Approach: 
XOR has certain properties 
Assume a1 ^ a2 ^ a3 ^ …^ an = a and a1 ^ a2 ^ a3 ^ …^ an-1 = b
Then a ^ b = an

Algorithm: 
Create two variables a = 0 and b = 0
Run a loop from 1 to n with i as counter.
For every index update a as a = a ^ i
Now traverse the array from start to end.
For every index update b as b = b ^ array[i]
Print the missing number as a ^ b.*/

CODE:

#include <stdio.h>
 
/* getMissingNo takes array and size of array as arguments*/
int getMissingNo(int a[], int n)
{
    int i;
    int x1 = a[0]; /* For xor of all the elements in array */
    int x2 = 1; /* For xor of all the elements from 1 to n+1 */
 
    for (i = 1; i < n; i++)
        x1 = x1 ^ a[i];
 
    for (i = 2; i <= n + 1; i++)
        x2 = x2 ^ i;
 
    return (x1 ^ x2);
}
 
/*program to test above function */
int main()
{
    int a[] = { 1, 2, 4, 5, 6 };
    int miss = getMissingNo(a, 5);
    printf("%d", miss);
    getchar();
}

Output:   3


Complexity Analysis: 
Time Complexity: O(n). 
Only one traversal of the array is needed.
Space Complexity: O(1). 
No extra space is needed.