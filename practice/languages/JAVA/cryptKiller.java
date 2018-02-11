import java.util.*;

public class cryptKiller {
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		while (T-- > 0) {
			ArrayList<String> string = new ArrayList<String>();
			String str;
			while (true) {
				str = input.nextLine();
				if (str.isEmpty()) break;
				string.add(str);
			}
			System.out.println(string);
		}
	}
}
