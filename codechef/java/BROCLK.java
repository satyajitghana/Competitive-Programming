import java.util.*;
import java.lang.*;
import java.math.*;

public class BROCLK {
	public static void calculate(double length, double distance, int time) {
		/*double speed = Math.PI/2 - Math.asin(distance/length);
		double distanceFromX = length * Math.sin(Math.PI/2 - time * speed);	
		System.out.println(speed + " " + distanceFromX);*/
		double distanceFromX = length * Math.cos(time * Math.acos(distance/length));
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
