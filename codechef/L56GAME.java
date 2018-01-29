import java.util.*;

public class L56GAME {
	public static void go(ArrayList<Integer> seq) {
		int odd = 0;
		for (int i = 0 ; i < seq.size() ; i++) {
			if (seq.get(i) %2 != 0) odd++;
		}
		int smallestSize = odd%2+1;
		System.out.println(smallestSize);
	}
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		while (T-- > 0) {
			int N = input.nextInt();
			ArrayList<Integer> seq = new ArrayList<Integer>();
			for (int i = 0 ; i < N ; i++) {
				seq.add(input.nextInt());
			}
			go(seq);
		}
	}
}
