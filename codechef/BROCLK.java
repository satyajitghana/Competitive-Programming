import java.util.*;
import java.lang.*;
import java.math.*;

public class BROCLK {
	public static void calculate(double length, double distance, int time) {
		double speed = Math.PI/2 - Math.asin(distance/length);
		double distanceFromX = length * Math.sin(Math.PI/2 - time * speed);
		//System.out.println(distanceFromX);
		BigDecimal result = new BigDecimal(distanceFromX);
		result = result.setScale(2, BigDecimal.ROUND_HALF_EVEN);
		String[] parts = result.toString().split("\\.");
		BigInteger out = new BigInteger(parts[0]);
		out = out.mod(new BigInteger("1000000007"));
		
		System.out.println(out);
		//int[] fraction = convertToFraction(result);
		//System.out.println(Arrays.toString(fraction));
	}
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		while (T-- > 0) {
			double length = input.nextDouble();
			double distance = input.nextDouble();
			int time = input.nextInt();
			calculate(length, distance, time);
		}
	}
	static int[] convertToFraction(BigDecimal number) {
		String[] parts = number.toString().split("\\.");
		if (parts.length <= 1) {int[] arr = {Integer.parseInt(parts[0])}; return arr;}
		BigDecimal denominator = BigDecimal.TEN.pow(parts[1].length());
		BigDecimal numerator = (new BigDecimal(parts[0]).multiply(denominator))
									.add(new BigDecimal(parts[1]));
		return reducedFraction(numerator.intValue(), denominator.intValue());
	}

	static int[] reducedFraction(int num, int den) {
		int gcd = BigInteger.valueOf(num).gcd(BigInteger.valueOf(den)).intValue();
		int[] fractionElements = {num/gcd, den/gcd};
		return fractionElements;
	}
}
