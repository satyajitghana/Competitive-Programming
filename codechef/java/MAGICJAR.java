import java.util.*;
import java.util.stream.*;

public class MAGICJAR {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int T = input.nextInt();
        while (T-- > 0) {
            Long[] A = new Long[input.nextInt()];
            Long sum = 0l;
            for (int i = 0; i < A.length; i++) {
                A[i] = input.nextLong();
            }
            sum = Arrays.asList(A).stream().reduce(0l, (a, b) -> a + b);
            System.out.println(sum - A.length + 1);
        }
    }
}