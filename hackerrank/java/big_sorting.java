import java.util.*;
import java.math.*;
import java.util.stream.*;

public class big_sorting {
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		Arrays.stream(new BigInteger[input.nextInt()])
								.map(e -> input.nextBigInteger())
								.sorted((o1,o2) -> o1.compareTo(o2))
								.forEach(j -> System.out.println(j));
	}
}
