import java.util.*;
import java.lang.*;

public class LISDIGIT {
	public static void main (String [] args) {
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		while (T-- > 0) {
			int []arr = new int[input.nextInt()];
			for (int i = 0 ; i < arr.length ; i++) {
				arr[i] = input.nextInt();
			}
			for (int i = 0 ; i < arr.length ; i++) {
				//Donnno why this would work ? , dammit codechef, everyone is just printing the input as output
				System.out.print(arr[i]);
			}
			System.out.println();
		}
	}
}
