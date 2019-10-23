import java.util.*;

public class KCON {
	public static long sum(long arr[]) {
		long sum = 0L;
		for (int i = 0 ; i < arr.length ; i++) {
			sum += arr[i];
		}

		return sum;
	}
	public static void go(long arr[], int K) {
		long sum = sum(arr);
		if (sum > 0) {
			System.out.println(findMax(arr,1)+(K-1)*sum);
		}
		else { 
			System.out.println(findMax(arr,2));
		}
	}
	public static long findMax(long arr[], int K) {
		long currMax = 0, finalSum = Long.MIN_VALUE;
		for (int j = 0 ; j < K ; j++) {
		for (int i = 0 ; i < arr.length ; i++) {
			currMax += arr[i];
			if (currMax > finalSum) finalSum = currMax;

			if (currMax < 0) currMax = 0;
		}
		}
		return finalSum;
	}
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		while (T-- > 0) {
			int N = input.nextInt();
			int K = input.nextInt();
			long []arr = new long[N];
			for (int i = 0 ; i < arr.length ; i++) {
				arr[i] = input.nextInt();
			}
		go(arr, K);
		}
	}
}
