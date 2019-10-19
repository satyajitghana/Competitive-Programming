import java.util.*;

public class CARPTUN {
	public static long max(long arr[]) {
		long max = arr[0];
		for (long e : arr) if (e > max) max = e;
		return max;
	}
	public static void calculate(long time[], int totalCars) {
		long maxProcessingTime = max(time);
		long processTimeTotal = (totalCars-1) * maxProcessingTime;
		System.out.println(processTimeTotal+".000000000");
	}
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		while (T-- > 0) {
			int N = input.nextInt();
			long []A = new long[N];
			for (int i = 0 ; i < A.length ; i++) {
				A[i] = input.nextLong();
			}
			int C = input.nextInt();
			int D = input.nextInt();
			int S = input.nextInt();
			calculate(A,C);
		}
	}
}
