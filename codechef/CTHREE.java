import java.util.*;
import java.math.*;

public class CTHREE {

	// Get all the divisors of N
	public static ArrayList <Long> getDivisors(long n) {
		ArrayList <Long> temp = new ArrayList <Long>();
		for (long i = 1 ; i <= Math.sqrt(n) + 1; i++ ) {
			if (n%i == 0) {
				if (n/i == i) temp.add(i);
				else {
					temp.add(i); temp.add(n/i);
				}
			}
		}
		return temp;
	}
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		while (T -- > 0) {
			long N = input.nextLong();
			long a = input.nextLong();
			long b = input.nextLong();
			long c = input.nextLong();
			long count = 0;
			ArrayList <Long> divisors = getDivisors(N);
			Collections.sort(divisors);
			for (int i = 0; i < divisors.size() && divisors.get(i) <= a ; i++) {
				for (int j = 0 ; j < divisors.size() && divisors.get(j) <= b ; j++) {
					long prod = divisors.get(i) * divisors.get(j);
					long z = N / prod;
					if (prod*z == N && z <= c) {
						count++;
					}
				}
			}
			System.out.println(count);
		}
	}
}
