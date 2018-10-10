import java.util.Scanner;

public class FLOW001 {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		
		int lg = sc.nextInt();
		int a, b;
		
		for(int i = 0; i < lg; i++) {
			a = sc.nextInt();
			b = sc.nextInt();
			System.out.println(a+b);
		}
		
		sc.close();
	}
}
