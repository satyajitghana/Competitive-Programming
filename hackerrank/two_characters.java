import java.util.*;

public class two_characters {
	public static void go(String str) {
		String unique = createHashMap(str);
		//System.out.println(unique);
		System.out.println(permute(str, unique));
	}

	public static int permute(String str, String set) {
		int max = 0;
		if (str.length()==2) {
			if (str.charAt(0)!=str.charAt(1)) return 2;
		}
		for (int i = 0 ; i < set.length() ; i++) {
			for (int j = i+1 ; j < set.length() ; j++) {
				String twoChar = createTwoChar(str, set, set.charAt(i), set.charAt(j));
				//System.out.println(twoChar);
				if (checkString(twoChar)) {
					if (twoChar.length() > max) {
						max = twoChar.length();
					}
				}
			}
		}
		return max;
	}

	public static String createTwoChar(String str, String uni, Character a, Character b) {
		uni = uni.replaceAll(a.toString(),"");
		uni = uni.replaceAll(b.toString(),"");
		for (int i = 0 ; i < uni.length() ; i++) {
			Character toRemove = uni.charAt(i);
			str = str.replaceAll(toRemove.toString(), "");
		}
		return str;
	}

	public static String createHashMap(String str) {
		HashSet<Character> unique = new HashSet<Character>();
		for (int i = 0 ; i < str.length(); i++) {
			unique.add(str.charAt(i));
		}
		String uniqueStr = "";
		for (Character ch : unique) {
			uniqueStr += ch;
		}
		return uniqueStr;
	}
	
	public static boolean checkString(String str) {
		for (int i = 0 ; i < str.length()-1 ; i++) {
			if (str.charAt(i) == str.charAt(i+1)) return false;
		}
		return true;
	}

	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		String str = input.next();
		go(str);
	}
}
