import java.util.*;

public class MGAME {
    public static void main(String [] args) {
        Scanner input = new Scanner(System.in);
        int T = input.nextInt();
        while (T-- > 0) {
            Long N = new Long(input.nextInt());
            Long P = new Long(input.nextInt());
            //int max = 0;
            // for (int i = 1 ; i <= P ; i++) {
            //     for (int j = 1 ; j <= P ; j++) {
            //         for (int k = 1 ; k <= P ; k++) {
            //                 System.out.print("("+i+","+j+","+k+") = "+((((N%i)%j)%k)%N) + ", ");
            //             if (((((N%i)%j)%k)%N) > max) {
            //                 max = ((((N%i)%j)%k)%N);
            //             }
            //         }
            //             System.out.println();
            //     }
            // }
            // max = (N-1)/2;
            // System.out.println("MAX : " + max);
            // int count = 0;
            // Set<Integer> ni = new HashSet<>();
            // Set<Integer> nj = new HashSet<>();
            // Set<Integer> nk = new HashSet<>();
            // for (int i = 1 ; i <= P ; i++) {
            //     for (int j = 1 ; j <= P ; j++) {
            //         for (int k = 1 ; k <= P ; k++) {
            //             if (((((N%i)%j)%k)%N) == max) {
            //                 //System.out.print("("+i+","+j+","+k+") = "+((((N%i)%j)%k)%N) + ", ");
            //                 count++;
            //                 ni.add(i);
            //                 nj.add(j);
            //                 nk.add(k);
            //             }
            //         }
            //     }
            // }
            //System.out.println(count);
            //System.out.println("("+ni.size()+","+nj.size()+","+nk.size()+")");
            Long ans = 0l;
            if (N == 1 || N == 2) {
                ans = P*P*P;
            } else {
                ans = ans + (P - (N-1)/2)*(P - (N-1)/2);
                ans = ans + (P-N)*(P - (N-1)/2);
                ans = ans + (P-N)*(P-N);
            }
            //System.out.println("Ans : "+ans);
            System.out.println(ans);
        }
    }
}