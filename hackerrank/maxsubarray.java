import java.util.*;
import java.util.stream.*;

public class maxsubarray {
	public static void go(Integer []arr) {
		Integer maxSoFar = Integer.MAX_VALUE, maxHere = 0;
		for (int i = 0 ; i < arr.length ; i++) {
			maxHere += arr[i];
			if ()
			if (maxHere > maxSoFar) maxSoFar = maxHere;
		}
	}
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		while (T-- > 0) {
			Integer []arr = Arrays.stream(new Integer[input.nextInt()])
								.map(i -> input.nextInt())
								.toArray(Integer[]::new);
			go(arr);
		}
	} 
}
