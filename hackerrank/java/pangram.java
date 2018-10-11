import java.util.*;

public class pangram {
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		String str = input.nextLine();
		str = str.toLowerCase();
		str = str.replaceAll(" ", "");
		HashSet<Character> set = new HashSet<Character>();
		for (int i = 0 ; i < str.length() ; i++) {
			set.add(str.charAt(i));
		}
		//System.out.println(set);
		if (set.size() == 26) System.out.println("pangram");
		else System.out.println("not pangram");
	}
}
