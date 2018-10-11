import java.util.*;
import java.util.stream.*;

public class maxsubarray {
	public static boolean isAllNegative(Integer []arr) {
		for (Integer e : arr) if (e > 0 ) return false;
		return true;
	}
	public static void go(Integer []arr) {
		Integer maxSoFar = Integer.MIN_VALUE, maxHere = 0;
		for (int i = 0 ; i < arr.length ; i++) {
			maxHere += arr[i];
			if (arr[i] > maxHere) maxHere = arr[i]; 
			if (maxHere > maxSoFar) maxSoFar = maxHere;
		}
		Integer maxSubArray = 0;
		if (!isAllNegative(arr)) maxSubArray = Arrays.stream(arr)
												//.mapToInt(Integer::intValue)
												.filter( e -> e > 0)
												.mapToInt(Integer::intValue)
												//.collect()
												.sum();
		/*else maxSubArray = Collections.max(Arrays.stream(arr)
							.mapToInt(Integer::intValue)
							.collect(Collectors.toCollection(ArrayList::new)));
							//.max();*/
		else maxSubArray = Collections.max(Arrays.asList(arr));
		System.out.println(maxSoFar + " " + maxSubArray);
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
