import java.util.*;

public class hackerrank_in_a_string {
	public static boolean go(String str) {
		String toCheck = "hackerrank";
		for (int i = 0 ; i < toCheck.length() ; i++) {
			int index = str.indexOf(toCheck.charAt(i));
			if (index == -1) return false;
			str = str.substring(index+1);
		}
		return true;
	}
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		while (T-- > 0) {
			String str = input.next();
			if (go(str)) System.out.println("YES");
			else System.out.println("NO");
		}
	}
}
