import java.math.BigInteger;
import java.util.*;

public class HMAPPY2 {
    // public static int LCM(Long a, Long b) { return new Long((a*b)/GCD(a,b)); }
    public static Long GCD(Long a, Long b) {
        if (b == 0l)
            return a;
        return GCD(b, a%b);
    }
    public static void main(String [] args) {
        Scanner input = new Scanner(System.in);
        int T = input.nextInt();
        while (T-- > 0) {
            Long N = input.nextLong();
            Long A = input.nextLong();
            Long B = input.nextLong();
            Long K = input.nextLong();

            Long ans = 0l;
            ans += N/A;
            ans += N/B;
            Long lcm = (A*B) / GCD(A, B);
            Long extra = N / lcm;
            ans -= extra;
            ans -= extra;
            // ans -= 2 * (N * BigInteger.valueOf(A).gcd(BigInteger.valueOf(B)).longValue()/(A*B) );

            System.out.println((ans >= K ? "Win" : "Lose" ));
        }
    }
}