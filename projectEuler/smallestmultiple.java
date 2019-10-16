/*
Problem 5
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

https://www.projecteuler.net/problem=5 
 */
public class smallestmultiple
{

	public static void main(String[] args)
	{
		boolean flag=false;
		int n=1;
		while(!flag)
		{
			boolean f=true;
			for(int i=1;i<=20;i++)
			{
				if(n%i!=0)
				{
					f=false;
					break;
				}
			}
			if(f==true)
			{
				System.out.println(n);
				flag=true;
				break;
			}
			n++;
		}
	}

}
