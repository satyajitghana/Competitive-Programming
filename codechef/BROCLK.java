import java.util.*;
import java.lang.*;

public class BROCLK {
	public static void calculate(double length, double distance, int time) {
		double speed = Math.PI - Math.asin(distance/length);
		double distanceFromX = length * Math.sin(Math.PI - time * speed);
		System.out.println(distanceFromX);
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
}
