import java.util.*;
import java.lang.*;

public class candies {
	public static void go(List <Integer> ratings) {
		List <Integer> candies = new ArrayList <Integer>();
		for (int i = 0 ; i < ratings.size() ; i++) 
			candies.add(1);
		for (int i = 0 ; i < ratings.size()-1 ; i++) {
			if (ratings.get(i+1) > ratings.get(i)) {
				candies.set(i+1, candies.get(i) + 1);
			}
		}
		//System.out.println(candies);
		for (int i = ratings.size()-1 ; i > 0 ; i--) {
			if (ratings.get(i-1) > ratings.get(i) && candies.get(i-1) <= candies.get(i)) {
				candies.set(i-1, candies.get(i) + 1);
			}
		}
		//Integer sum = candies.stream().mapToInt(Integer::intValue).sum();
		Long sum = 0L;
		for (int i = 0 ; i < candies.size() ; i++) {
			sum += candies.get(i);
		}
		System.out.println(sum);
		//System.out.println(candies);
	}
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		int N = input.nextInt();
		List<Integer> ratings = new ArrayList<Integer>();
		for (int i = 0 ; i < N ; i++) {
			ratings.add(input.nextInt());
		}
		go(ratings);
	}
}
