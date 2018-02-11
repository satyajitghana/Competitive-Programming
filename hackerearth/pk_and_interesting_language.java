import java.util.*;
import java.math.*;

public class pk_and_interesting_language {
	public static long[][] multiply(long[][] A, long[][] B) {
		long[][] C = new long[A.length][B[0].length];
		for (int i = 0 ; i < A.length ; i++) {
			for (int j = 0 ; j < B[0].length ; j++) {
				//C[i][j] = new BigInteger("0");
				for (int k = 0 ; k < B.length ; k++) {
					C[i][j] += A[i][k] * B[k][j];
					if (C[i][j] >= 1000000007L)
						C[i][j] = C[i][j] % 1000000007L;
				}
			}
		}
		return C;
	}
	public static long[][] power(long[][]arr, int N) {
		if (N == 1) return arr;
		long[][] R = power(arr, N/2);
		if (N%2==0) return multiply(R,R);
		return multiply(multiply(R,R),arr);
	}
	public static void go(char C, int L, long[][] arr) {
		long[][] count = power(arr,L-1);
		//for (long[] a : count) System.out.println(Arrays.toString(a));
		long sum = 0L;
		for (int i = 0 ; i < count.length ; i++) {
			sum = (sum + count[i][(int)(C - 97)]) % 1000000007L ;
		}
		//long ans = sum % 1000000007L;
		System.out.println(sum);
	}
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		long[][] arr = new long[26][26];
		for (int i = 0 ; i < 26 ; i++) {
			for (int j = 0 ; j < 26 ; j++) {
				arr[i][j] = input.nextLong();
			}
		}
		int T = input.nextInt();
		while (T-- > 0) {
			char C = input.next().charAt(0);
			int L = input.nextInt();
			go(C,L,arr);
		}
	}
}
