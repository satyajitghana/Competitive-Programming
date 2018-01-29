import java.util.*;

public class MAXSC {
	public static int findMax(ArrayList<ArrayList<Integer>> scores) {
		int i = scores.size()-1;
		while (i > 0) {
			if (scores.get(i-1).size() == 0) return -1;
			Integer currElement = scores.get(i).get(0);
			Integer prevElement = scores.get(i-1).get(0);
			if (!((prevElement < currElement) & (prevElement != currElement))) {
				scores.get(i-1).remove(0);
				i++;
			}
			i--;
		}

		return 0;
	}

	public static long findSum(ArrayList<ArrayList<Integer>> scores) {
		long sum = 0;
		for (int i = 0 ; i < scores.size(); i++) {
			sum += scores.get(i).get(0);
		}
		return sum;
	}
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		while (T-- > 0) {
			int N = input.nextInt();
			ArrayList<ArrayList<Integer>> score = new ArrayList<ArrayList<Integer>>();
			for (int i = 0 ; i < N ; i++) {
				ArrayList<Integer> inner = new ArrayList<Integer>();
				for (int j = 0 ; j < N ; j++) {
					inner.add(input.nextInt());
				}
				Collections.sort(inner, Collections.reverseOrder());
				score.add(inner);
			}
			//System.out.println(score);
			int status = findMax(score);
			if (status != -1) {
				long sum = findSum(score);
				System.out.println(sum);
			}
			else System.out.println(-1);
		}
	}
}
