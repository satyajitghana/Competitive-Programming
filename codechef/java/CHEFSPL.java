import java.util.*;

public class CHEFSPL {
	public static boolean go(String str1, String str2) {
		if (str1.length() == str2.length()) {
			return (str1.equals(str2));
		}
		else {
			if (str2.length() > str1.length()) {
				String str3 = str1;
				str1 = str2;
				str2 = str3;
			}
			int errors = 0;
			for (int i = 0, j = 0; i < str1.length() && j < str2.length();) {
				if (str1.charAt(i) == str2.charAt(j)) {
					i++; j++;
				}
				else {
					errors++;
					i++;
				}
			}
			if (errors <= 1) return true;
		       	else return false;	
		}
	}
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		while (T-- > 0) {
			String str = input.next();
			boolean isSpecial = false;
			if (str.length() == 1) ;
			else if (str.length()%2 == 0) {
				isSpecial = go(str.substring(0,str.length()/2), str.substring(str.length()/2));
			}

			else {
				if (go(str.substring(0,str.length()/2+1),str.substring(str.length()/2+1)) || go(str.substring(0,str.length()/2), str.substring(str.length()/2)))
				isSpecial = true;	
			}

			if (isSpecial) System.out.println("YES");
			else System.out.println("NO");
		}
	}
}
