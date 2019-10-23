import java.util.Scanner;

public class NExtgreaterNextSmaller {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int arr[] = { 5, 1, 9, 2, 5, 1, 7 };
		int n = arr.length;
		printNGE(arr, n);
	}

	private static void printNGE(int[] arr, int n) {
		// TODO Auto-generated method stub
		int next, i, j;
		for (i = 0; i < n; i++) {
			next = -1;
			for (j = i + 1; j < n; j++) {
				if (arr[i] > arr[j]) {
					next = arr[j];
					if (arr[i] < arr[j]) {
						next=arr[j];
						break;

					}
				}
			}

			System.out.println( next);
		}
	}

}
