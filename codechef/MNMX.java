import java.util.*;
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner s=new Scanner(System.in);
		int a=s.nextInt();
		for(int j=0;j<a;j++){
		    int n=s.nextInt();
		int[] arr=new int[n];
		for(int i=0;i<n;i++){
		    arr[i]=s.nextInt();
		}
		int m=arr[0];
		for(int i=1;i<n;i++){
		    m=Math.min(m,arr[i]);
		}
		System.out.println((long)m*(long)(n-1));
	}}
}
