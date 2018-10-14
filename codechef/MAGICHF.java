import java.util.*;
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		for(int i=0;i<t;i++){
		int n=sc.nextInt();
		int x=sc.nextInt();
		int s=sc.nextInt();
		    for(int j=0;j<s;j++){
		        int a=sc.nextInt();
		        int b=sc.nextInt();
		        if(a==x){
		            x=b;
		        }
		        else if(b==x){
		            x=a;
		        }
		        else{continue;}
		    }
		    System.out.println(x);
		}
		
	}
}
