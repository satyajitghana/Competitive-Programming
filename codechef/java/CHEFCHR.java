import java.util.*;

public class CHEFCHR {
	public static void go(String str, Set <Character> chef) {
		int count = 0;
		for (int i = 0 ; i < str.length()-3 ; i++) {
			HashSet <Character> currSet = new HashSet <Character>();
			String substr = str.substring(i, i+4);
			for (Character c : substr.toCharArray()) {
				currSet.add(c);
			}
			if (currSet.containsAll(chef)){
				//System.out.println(substr);
				count++;
			}
		}
		if (count == 0) System.out.println("normal");
		else System.out.println("lovely " + count);
	}
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		Set <Character> chef = new HashSet<Character>(Arrays.asList('c','h','e','f'));
		while (T-- > 0) {
			String str = input.next();
			go(str, chef);
		}
	}
}
