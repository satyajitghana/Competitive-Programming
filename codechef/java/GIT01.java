import java.util.*;
import java.lang.*;

public class GIT01 {
	public static char change(char ch) {
		if (ch == 'R') return 'G';
		else return 'R';
	}

	public static int replace(String str[], char myCherry) {
		int cost = 0;
		char myCherryV = myCherry;
		for (int i = 0 ; i < str.length ; i++) {
			myCherry = myCherryV;
			for (int j = 0 ; j < str[0].length() ; j++) {
				if (str[i].charAt(j) != myCherry) {
					if (str[i].charAt(j) == 'R') cost += 5;
					else cost += 3;
				}
				myCherry = change(myCherry);
			}

			myCherryV = change(myCherryV);
		}
		return cost;
	}
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		// R -> G : 5 units; G -> R : 3 units
		while (T-- > 0) {
			String cake[] = new String[input.nextInt()];
			int BS = input.nextInt();
			int sum = 0;
			for (int i = 0 ; i < cake.length ; i++) {
				cake[i] = input.next();
			}
			sum = Math.min(replace(cake,'R'), replace(cake,'G'));
			System.out.println(sum);
			//System.out.println(replace(cake,'R') + " " + replace(cake,'G'));
		}
	}
}
