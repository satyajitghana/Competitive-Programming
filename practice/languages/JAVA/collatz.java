import java.util.*;

public class collatz {
	public static void main(String []  args) {
	if (args.length == 1) {
		short count=0;
		while (n!=1) {
			if (n%2==0) {
				n = n/2;  
				count++;
			       	System.out.print(n + " ");	
				} 
			else {
				n=n*3+1;
				count++;
				System.out.print(n + " ");
				}
			}
		System.out.println();
		System.out.println("Total Iterations : " +  count);
		}
	else System.out.println("USAGE : collatz <any natural number>")
	}
}
