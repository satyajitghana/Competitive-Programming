/*
Problem 3:
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

https://projecteuler.net/problem=3
 */

public class primefactors 
{

	public static void main(String[] args)
	{
		long num = 600851475143L;
		while(num%2==0) //divides number until its no longer divisible by 2
			num=num/2;
		for(long i=3;i<num;i+=2)
		{
			while(num%i==0 && i<num)
			{
				num=num/i;
			}
		}
		System.out.println(num);
	}
   
}
