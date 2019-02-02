import java.util.*;

public class ADASCHOOL {
    public static void main(String [] args) {
        Scanner input = new Scanner(System.in);
        int T = input.nextInt();
        while(T-- > 0) {
            int N = input.nextInt();
            int M = input.nextInt();

            if ( (N%2 == 0) || (M%2 == 0) ) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}