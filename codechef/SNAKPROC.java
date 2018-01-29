import java.util.*;

public class SNAKPROC {
	public static char change(char ch) {
		if (ch=='H') return 'T';
		else return 'H';
	}
	public static boolean go(String str) {
		char expected = 'H';
		for (int i = 0 ; i < str.length() ; i++) {
			if (str.charAt(i)!='.') {
				if (str.charAt(i)!=expected) return false;
				expected = change(expected);
			}
		}
		if (expected=='T') return false;
		return true;
				
	}
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		while (T-- > 0) {
			int BS = input.nextInt();
			String str = input.next();
			if (go(str)) System.out.println("Valid");
			else System.out.println("Invalid");
		}
	}
}
