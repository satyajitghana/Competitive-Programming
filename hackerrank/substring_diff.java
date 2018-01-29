import java.util.*;

public class substring_diff {
	public static void go(String P, String Q, int S) {
		int maxL = 0;
		int L = P.length();
		for (int i = 0 ; i < L ; i++) {
			for (int j = 0 ; j < P.length()-i ; j++) {
				for (int k = 0 ; k < Q.length()-i ; k++) {
					String PsubString = P.substring(j, j+i+1);
					String QsubString = Q.substring(k, k+i+1);
					int mismatches = mismatches(PsubString, QsubString);
					if (mismatches <= S) {
						if (i > maxL) maxL = i;
					}
					//System.out.println(PsubString + " " + QsubString + " " + mismatches);
				}
			}
		}
	System.out.println(maxL+1);
	}
	public static int mismatches(String A, String B) {
		int mismatches = 0;
		for (int i = 0 ; i < A.length() ; i++) {
			if (A.charAt(i) != B.charAt(i)) mismatches++;
		}
		return mismatches;
	}
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		while (T-- > 0) {
			int S = input.nextInt();
			String P = input.next();
			String Q = input.next();
			go(P, Q, S);
		}
	}
}
