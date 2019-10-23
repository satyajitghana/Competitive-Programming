import java.util.*;

public class VILTRIBE {
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		while (T-- > 0) {
			String str = input.next();
			int A = 0;
			int B = 0;
			int N = 0;
			String belongsTo = new String("N");
			for (int i = 0 ; i < str.length(); i++) {
				if (str.charAt(i) == 'A') {
					if (belongsTo.equals("A")) {// give A all the villages and make N = 0
						A += N;
					}
					N = 0;
					A++;
					belongsTo = new String("A");
				}
				else if (str.charAt(i) == 'B') {
					if (belongsTo.equals("B")) {//give B all the villages and make N = 0
						B += N;
					}
					N = 0;
					B++;
					belongsTo = new String("B");
				}
				else {
					N++;
				}
			}
			System.out.println(A+" "+B);
		}
	}
}
