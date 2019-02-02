import java.util.*;

public class ADAKING {
    public static void main(String [] args) {
        Scanner input = new Scanner(System.in);
        int T = input.nextInt();
        while (T-- > 0) {
            int R = input.nextInt();
            int C = input.nextInt();
            int K = input.nextInt();

            int total1 = 1;
            int total2 = 1;

            if ((R + K) < 8) {
                total1 += (R+K);
            } else {
                total1 += 8;
            }

            if ((R - K) < 1) {
                total1 -= 1;
            } else {
                total1 -= (R-K);
            }

            if ((C + K) < 8) {
                total2 += (C+K);
            } else {
                total2 += 8;
            }

            if ((C - K) < 1) {
                total2 -= 1;
            } else {
                total2 -= (C-K);
            }

            System.out.println(total1 * total2);
        }
    }
}