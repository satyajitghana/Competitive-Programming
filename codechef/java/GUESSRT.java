import java.math.BigInteger;
import java.util.*;

public class GUESSRT {
    static int mod = (BigInteger.valueOf(Integer.valueOf(10)).pow(9)).add(BigInteger.valueOf(Integer.valueOf(7)))
            .intValue();

    public static int temp;
    // Source : https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/
    // extended Euclidean Algorithm
    public static int gcdExtended(int a, int b, int x, int y) {
        // Base Case
        if (a == 0) {
            x = 0;
            temp = 0;
            y = 1;
            return b;
        }

        int x1 = 1, y1 = 1; // To store results of recursive call
        // temp = 1;
        int gcd = gcdExtended(b % a, a, x1, y1);

        // Update x and y using results of recursive
        // call
        x = y1 - (b / a) * x1;
        temp = y1 - (b / a) * x1;
        y = x1;

        return gcd;
    }

    public static int modInverse(int a) {
        gcdExtended(a, mod, 1, 1);
        return (temp % mod + mod) % mod;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int T = input.nextInt();
        while (T-- > 0) {
            Integer N = input.nextInt();
            BigInteger N_BI = BigInteger.valueOf(N.intValue());
            Integer K = input.nextInt();
            BigInteger K_BI = BigInteger.valueOf(K.intValue());
            Integer M = input.nextInt();
            BigInteger M_BI = BigInteger.valueOf(M.intValue());

            int va = (M - 1) / 2;
            // int h1 = N_BI.pow((M+1)/2).intValue();
            int h1 = (int) Math.pow(N, (M + 1) / 2);
            // int d =
            // BigInteger.valueOf(Integer.valueOf(N-1).intValue()).pow((M+1)/2).intValue();
            int d = (int) Math.pow(N - 1, (M + 1) / 2);
            int h;

            if (M % 2 == 0) {
                h = (h1 - d) * (N + K) + d;
                h1 = h1 * (N + K);
            } else {
                h = h1 - d;
            }

            // h1 =
            // BigInteger.valueOf(Integer.valueOf(h1)).modInverse(BigInteger.valueOf(Integer.valueOf(h1))).intValue();
            System.out.print(h1 + " ");
            h1 = modInverse(h1);
            int ans = ((h % mod) * (h1 % mod)) % mod;
            // System.out.println(mod);
            System.out.print(d + " " + h1 + " ");
            System.out.println(ans);
        }
    }
}