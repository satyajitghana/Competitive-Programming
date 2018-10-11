import java.util.*;

public class reduced_string {
	static String go(String str) {
		ArrayList<Character> string = new ArrayList<Character>();
		for (int i = 0 ; i < str.length() ; i++) {
			string.add(str.charAt(i));
		}
		for (int i = 0 ; i < string.size()-1 ;) {
			if (string.get(i)==string.get(i+1)) {
				string.remove(i);
				string.remove(i);
				if (string.isEmpty())
					return "Empty String";
				i = 0;
			}
			else i++;
		}
		String finalString = "";
		for (int i = 0 ; i < string.size() ; i++) {
			finalString += string.get(i);
		}
		//System.out.println(string);
		return finalString;
	}
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		String str = input.next();
		System.out.println(go(str));
	}
}
