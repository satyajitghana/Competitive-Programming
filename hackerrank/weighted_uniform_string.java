import java.util.*;

public class weighted_uniform_string {
	public static HashSet<Integer> go(String str) {
		HashSet<Integer> weights = new HashSet<Integer>();
		int count = 1;
		char lastChar = '-';
		for (int i = 0 ; i < str.length() ; i++) {
			char currChar = str.charAt(i);
			//System.out.println(currChar+" "+lastChar);
			if (currChar == lastChar) {
				count++;
			}
			else {
				count = 1;
			}
			weights.add(count*((int)currChar-96));
			lastChar = currChar;
		}
		//System.out.println(weights);
		return weights;
	}
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		String str = input.next();
		HashSet<Integer> weights = go(str);
		int T = input.nextInt();
		while (T-- > 0) {
			int query = input.nextInt();
			if (weights.contains(query)) System.out.println("Yes");
			else System.out.println("No");
		}
	}
}
