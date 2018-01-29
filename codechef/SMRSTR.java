import java.util.Scanner;
import java.io.PrintWriter;

public class SMRSTR {
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		PrintWriter output = new PrintWriter(System.out);
		int T = input.nextInt();
		while (T-- > 0) {
			int divideByThese[] = new int[input.nextInt()];
			int divideThese[] = new int[input.nextInt()];
			boolean largeDivide = false;
			int finallyDivideBy = 1;
			for (int i = 0 ; i < divideByThese.length ; i++) {
				divideByThese[i] = input.nextInt();
				finallyDivideBy *= divideByThese[i];
				if (finallyDivideBy > 1000000000)
					largeDivide = true;
			}
			for (int i = 0 ; i < divideThese.length ; i++) {
				divideThese[i] = input.nextInt();
				if (largeDivide) output.print("0 ");
				else
				output.print(divideThese[i]/finallyDivideBy+" ");
			}
			output.println();
		}
		output.close();
		input.close();
	}
}
