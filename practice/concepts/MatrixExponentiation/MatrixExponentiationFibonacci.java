import java.util.*;

public class MatrixExponentiationFibonacci {
	public static long[][] matrixMultiply(long[][] A, long[][] B) {
		long[][] C = new long[A.length][B[0].length];
		for (int i = 0 ; i < A.length ; i++) {
			for (int j = 0 ; j < B[0].length ; j++) {
				for (int k = 0 ; k < B.length ; k++) {
					C[i][j] += A[i][k] * B[k][j];
				}
			}
		}
		return C;
	}
	
	public static long[][] power(long[][] A, int N) {
		if (N == 1) return A;
		
		long[][] R = power(A, N/2);

		if (N%2 == 0) {
			return matrixMultiply(R,R); 
		}

		return matrixMultiply(matrixMultiply(R,R),new long[][]{{1,1},{1,0}});
	}

	public static void fibonacci(int N) {
		long[][] fib = new long[][]{{1,1},{1,0}};
		System.out.print(N + "th fibonacci number is : ");
		if (N > 3) {
			long[][] ans = power(fib, N-3);
			System.out.println(ans[0][0] + ans[0][1]);
		}
		else {
			switch (N) {
				case 1: System.out.println(0); break;
				case 2: System.out.println(1); break;
				case 3: System.out.println(1); break;
			}
		}
	}

	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		System.out.print("Enter the value of N : ");
		int N = input.nextInt();
		fibonacci(N);
	}
}
