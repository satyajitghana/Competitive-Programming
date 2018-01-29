import java.util.*;
import java.math.*;

public class MUL {
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		while (T-- > 0) {
			String str1 = input.next();
			String str2 = input.next();
			BigInteger int1 = new BigInteger(str1);
			BigInteger int2 = new BigInteger(str2);
			BigInteger prod = int1.multiply(int2);
			System.out.println(prod);
		}		
	}
}
