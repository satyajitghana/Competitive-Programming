/*
    Problem 7:
    By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

    What is the 10 001st prime number?
    Link: https://projecteuler.net/problem=7
*/

public class projectEuler7
{
    public boolean isPrime(int p)
    {
        int fac=0;
        for(int i=1;i<=p;i++)
        {
            if(p%i==0)
                fac++;
        }
        if(fac==2)
            return true;
        else
            return false;
    }
    public static void main(String args[])
    {
        projectEuler7 obj = new projectEuler7();
        int c =1, p=2;
        do
        {
            p=p+1;
            if(obj.isPrime(p))
                c++;
        }while(c<10001);
        System.out.println(p);
    }
}
