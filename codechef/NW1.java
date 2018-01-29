import java.util.*;

public class NW1 {
	public static int getDay(String day) {
		if (day.equals("mon")) return 0;
		if (day.equals("tues")) return 1;
		if (day.equals("wed")) return 2;
		if (day.equals("thurs")) return 3;
		if (day.equals("fri")) return 4;
		if (day.equals("sat")) return 5;
		if (day.equals("sun")) return 6;
		return -1;

	}
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		while (T-- > 0) {
			int days = input.nextInt();
			String day = input.next();
			int dayCount[] = new int[7];
			int minDays = days/7;
			for (int i = 0 ; i < dayCount.length ; i++) {
				dayCount[i] = minDays;
			}
			int remDays = days%7;
			int currDay = getDay(day);
			for (int i = 0; i < remDays ; i++) {
				dayCount[currDay]++;
				currDay++;
				if (currDay == 7) currDay = 0;
			}
			for (int i = 0 ; i < dayCount.length ; i++) {
				System.out.print(dayCount[i] + " ");
			}

			System.out.println();
		}
	}
}
