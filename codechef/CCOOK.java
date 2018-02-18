import java.util.*;

public class CCOOK {
	public static void go(int N) {
		if (N == 0) System.out.println("Beginner");
		if (N == 1) System.out.println("Junior Developer");
		if (N == 2) System.out.println("Middle Developer");
		if (N == 3) System.out.println("Senior Developer");
		if (N == 4) System.out.println("Hacker");
		else System.out.println("Jeff Dean");
	}
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		while (T-- > 0) {
			int count = 0;
			for (int i = 0 ; i < 5 ; i++) {
				int temp = input.nextInt();
				if (temp == 1) count++;
			}
			go(count);
		}
	}
}
