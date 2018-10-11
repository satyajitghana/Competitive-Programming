import java.util.*;
import java.util.stream.Collectors;

public class coin_change {
	/*public static void go(int sum, long[] change) {
		List<Long> coins = Arrays.stream(change).boxed().collect(Collectors.toList());
		Long count = count(coins, Long.valueOf(sum));
		System.out.println("final count : " + count);
	}
	
	public static Long count(List<Long> coins, Long sum) {
		System.out.println(coins.toString() + " " + sum);
		if (sum == 0) return 1L;
		if (sum < 0) return 0L;
		if (coins.size() == 0 && sum > 0) return 0L;

		return count(coins.subList(0,coins.size()-1), sum) + count(coins, sum-coins.get(coins.size()-1));
	}*/

	public static void go(int sum, long[] change) {
		List <Long> coins = Arrays.stream(change).boxed().collect(Collectors.toList());
		//Long count = count(coins, Long.valueOf(sum));
		ArrayList <ArrayList <Long>> store = new ArrayList <ArrayList <Long>>();
		for (int i = 0 ; i < change.length + 1 ; i++) {
			ArrayList <Long> curr = new ArrayList <Long>();
			for (int j = 0 ; j < sum + 1 ; j++) {
				curr.add(-1L);
			}
			store.add(curr);
		}
		//System.out.println(store);
		Long count = count(coins, Long.valueOf(sum), store);
		System.out.println(count);
	}

	public static Long count(List<Long> coins, Long sum, ArrayList <ArrayList <Long>> store) {
		if (sum == 0) return 1L;
		if (coins.size() == 0) return 0L;
		if (sum < 0) return 0L;
		if (store.get(coins.size()-1).get(Integer.valueOf(sum.intValue())) == -1) {
			store.get(coins.size()-1).set(Integer.valueOf(sum.intValue()), count(coins.subList(0, coins.size()-1), sum, store) + 
										count(coins, sum - coins.get(coins.size()-1), store));
		}
		return store.get(coins.size()-1).get(Integer.valueOf(sum.intValue()));
	}

	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		int N = input.nextInt();
		int M = input.nextInt();
		long []C = new long[M];
		for (int i = 0 ; i < C.length ; i++) C[i] = input.nextInt();
		go(N, C);
	}
}
