/*
Problem 4
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

https://projecteuler.net/problem=4
 */
import java.io.*;
public class largestpali
{
	public static void main(String args[])
	{
		for(int i=999;i>=900;i--)
		{

			for(int j=999;j>=900;j--)
			{

				long c = j*i;
				boolean flag=false;
				String str=""+c;
				int len=str.length();
				if(len%2==0)//even
				{
					StringBuffer a=new StringBuffer(str.substring(0,len/2));
					StringBuffer b=new StringBuffer(str.substring(len/2,len));
					b.reverse();
					if(a.equals(b))
						flag= true;
					else
						flag= false;
				}
				else
				{
					StringBuffer a=new StringBuffer(str.substring(0,len/2));
					StringBuffer b=new StringBuffer(str.substring((len/2)+1,len));
					b.reverse();
					if(a.equals(b))
						flag= true;
					else
						flag= false;
				}
				
				if(flag)
				{
					System.out.println(c);
					break;
				}
			}
		}
	}	
	/*public static boolean isPalin(long c)
	{
		String str=""+c;
		int len=str.length();
		if(len%2==0)//even
		{
			StringBuffer a=new StringBuffer(str.substring(0,len/2));
			StringBuffer b=new StringBuffer(str.substring(len/2,len));
			b.reverse();
			if(a.equals(b))
				return true;
			else
				return false;
		}
		else
		{
			StringBuffer a=new StringBuffer(str.substring(0,len/2));
			StringBuffer b=new StringBuffer(str.substring((len/2)+1,len));
			b.reverse();
			if(a.equals(b))
				return true;
			else
				return false;
		}
		
	}*/

	
}
