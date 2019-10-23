import java.util.*;

public class STRPALIN {
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		while (T-- > 0) {
			String str1 = input.next();
			String str2 = input.next();
			boolean flag = false;
			here:
			for (int i = 0 ; i < str1.length() ; i++) {
				for (int j = 0 ; j < str2.length() ; j++) {
					if (str1.charAt(i) == str2.charAt(j))
					{flag = true; break here;}
				}
			}
			if (flag) System.out.println("Yes");
			else System.out.println("No");
		}
	}
}
