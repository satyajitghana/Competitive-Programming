import java.util.*;

public class mars_exploration {
	public static void go(String str) {
		int count = 0;
		for (int i = 0 ; i < str.length() ; i += 3) {
			String currSignal = str.substring(i,i+3);
			if (!(currSignal.equals("SOS"))) {
				if (currSignal.charAt(0)!= 'S') count++;
				if (currSignal.charAt(1)!= 'O') count++;
				if (currSignal.charAt(2)!= 'S') count++;
			}
		}
		System.out.println(count);
	}
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		String str = input.next();
		go(str);
	}
}
