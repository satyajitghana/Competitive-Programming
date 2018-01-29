import java.util.*;
import java.lang.*;

public class VK18 {
	public static long diamonds(long sum) {
		long even=0,odd=0;
		while (sum > 0) {
			long digit = sum%10;
			if ((sum&1) == 0) even += digit;
			else odd += digit;
			sum /= 10;
		}
		//System.out.println(even-odd);
		return Math.abs(even-odd);
	}
	public static void main(String [] args) {
		int MAX = 1000000;
		long diamondsAti[] = new long[MAX*2+1];
		long sum[] = new long[MAX+1];
		long sumConsecutive[] = new long[MAX*2+1];
		for (int i = 1 ; i < MAX*2+1 ; i++) {
			diamondsAti[i] = diamonds(i);
			sumConsecutive[i] = sumConsecutive[i-1] + diamondsAti[i]; 
		}
		sum[1] = 2;
		for (int i = 2 ; i< MAX+1 ; i++) {
			sum[i] = sum[i-1] + (sumConsecutive[2*i-1]-sumConsecutive[i])*2+diamondsAti[2*i];
		}
	
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		while (T-- > 0) {
			int N = input.nextInt();
		//previous attempt
			/*long sum = 0;
			int times = 1;
			for (int i = 2 ; i <= N*2 ; i++) {
				long sumAti = diamonds(i);
				sum += sumAti*times;
				//System.out.println(sumAti+"*"+times);
				if (i <= N ) times++;
				else times--;
			}
			if (N==1) System.out.println(1);
			else
			System.out.println(sum);*/
			System.out.println(sum[N]);
		}
	}
}
