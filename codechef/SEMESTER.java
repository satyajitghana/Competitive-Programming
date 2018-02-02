import java.util.*;
import java.util.stream.*;

public class SEMESTER {
	public static String findDay(int i) {
		if (i == 0) return "Monday";
		if (i == 1) return "Tuesday";
		if (i == 2) return "Wednesday";
		if (i == 3) return "Thursday";
		if (i == 4) return "Friday";
		if (i == 5) return "Saturday";
		return "Sunday";
	}
	public static void startStudy(int []week, int lastWeek) {
		for (int i = 0 ; i < 7; i++) {
			lastWeek -= week[i];
			if (lastWeek <= 0) {
				System.out.println(findDay(i));
				break;
			}
		}
	}
	public static void go(int []week, int totalTopics) {
		int totalPerWeek = IntStream.of(week).sum();
		int lastWeek = totalTopics%totalPerWeek;
		//System.out.println(totalPerWeek + " " + lastWeek);
		if (lastWeek == 0) startStudy(week, totalPerWeek);
		else 
		startStudy(week, lastWeek);
	}
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		while (T-- > 0) {
			int totalTopics = input.nextInt();
			int []week = new int[7];
			for (int i = 0 ; i < week.length ; i++) {
				week[i] = input.nextInt();
			}
			go(week, totalTopics);
		}
	}
}
