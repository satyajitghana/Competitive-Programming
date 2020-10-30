import java.util.*;

public class CHEFPTNT {
	public static void go(int totalPatents, int maxMonths, int workers, int maxWorkers, String str) {
		if (maxWorkers <= 0) {
			System.out.println("no");
			return;
		}
		int []months = new int[12];
		int even = 0;
		int odd = 0;
		for (char ch : str.toCharArray()) {
			if (ch == 'E') even++;
			else odd++;
		}
		//System.out.println(even + " " + odd);
		for (int i = 0 ; i < maxMonths ; i++) {
			if (i%2 != 0) {
				if (even/maxWorkers > 0) {
					months[i] += maxWorkers;
					even -= maxWorkers;
				}
				else {
					months[i] += even;
					even = 0;
				}
			}
			else {
				if (odd/maxWorkers > 0) {
					months[i] += maxWorkers;
					odd -= maxWorkers;
				}
				else {
					months[i] += odd;
					odd = 0;
				}
			}
		}
		int sum = 0;
		for (int i = 0 ; i < maxMonths ; i++) {
			sum += months[i];
		}
		//System.out.println(Arrays.toString(months)+" "+sum);
		if (sum >= totalPatents) System.out.println("yes");
		else System.out.println("no");
	}
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		while (T-- > 0) {
			int N = input.nextInt();
			int M = input.nextInt();
			int X = input.nextInt();
			int K = input.nextInt();
			String S = input.next();
			go(N, M, K, X, S);
		}
	}
}
