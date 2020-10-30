import java.util.*;

public class LEXOPAL {
	public static StringBuilder go(StringBuilder str) {
		StringBuilder error = new StringBuilder("tumse-na-ho-payega");
		for (int i=0,j=str.length()-1; i<=j ; i++, j--) {
			if (str.charAt(i)=='.' && str.charAt(j)=='.') {
				str.setCharAt(i,'a');
				str.setCharAt(j,'a');
			}
			else if (str.charAt(i)=='.') {
				str.setCharAt(i,str.charAt(j));
			}
			else if (str.charAt(j)=='.') {
				str.setCharAt(j,str.charAt(i));
			}
			else if (str.charAt(i) != str.charAt(j)) return error;
		}
		return str;
	}
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		while (T-- > 0) {
			StringBuilder string = new StringBuilder(input.next());
			StringBuilder res = go(string);
			if (res.toString().equals("tumse-na-ho-payega".toString())) System.out.println(-1);
			else System.out.println(res);
		}
	}
}
