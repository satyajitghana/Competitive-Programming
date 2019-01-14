import java.util.*;

public class EARTSEQ {

    public static ArrayList<Long> sieveN(int n) { 
        boolean prime[] = new boolean[n+1];

        for(int i = 0 ; i < n ; i++) 
            prime[i] = true; 
          
        for(int p = 2 ; p*p <= n ; p++) { 
            if(prime[p] == true) { 
                for(int i = p*p; i <= n; i += p) 
                    prime[i] = false; 
            } 
        } 
        
        ArrayList<Long> primes = new ArrayList<>();

        for(int i = 2; i <= n; i++) { 
            if(prime[i] == true) 
                primes.add(new Long(i)); 
        }

        return primes;
    } 

    public static void main(String [] args) {
        Scanner input = new Scanner(System.in);
        int T = input.nextInt();
        ArrayList<Long> primes = sieveN(2100);
        while (T-- > 0) {
            int N = input.nextInt();
            Long []A = new Long[50000];

            boolean exceeded = false;

            // one formed sequence : [6, 10, 55, 77, 91, 143, 187, 221, 247, 323, 51]
            // another form of seq : [6, 10, 55, 77, 91, 143, 275, 175, 637, 1573, 363]
            // one more : [6, 10, 55, 77, 91, 143, 187, 119, 35, 65, 221, 85, 95, 323, 391, 437, 247, 299, 253, 209, 133, 161, 115, 145, 87]

            int i;
            for (i = 0 ; i < N-1; i++) {
                A[i] = primes.get(i)*primes.get(i+1);
            }
            A[i] = 2 * primes.get(i);

            // A[0] = 6l;
            // A[1] = 10l;
            // A[2] = 35l;
            // A[3] = 77l;
            // A[4] = 55l;
            // A[5] = 65l;

            // if (N <= 6) {
            //     if (N == 3) {
            //         A[2] = 15l;
            //     } else if (N == 4) {
            //         A[3] = 21l;
            //     } else if (N == 5) {
            //         A[4] = 33l;
            //     } else if (N == 6) {
            //         A[5] = 15l;
            //     }
            // }
            // int j = 0;
            // int curr;
            // // if N > 6 then compute until N-1 terms
            // int i = 6;
            // for (; i < N-1 ; i++) {
            //     curr = i-6;
            //     if (curr%7 == 0) {
            //         j += 2;
            //         A[i] = primes.get(j+2) * primes.get(j+3);
            //     } else if (curr%7 == 1) {
            //         A[i] = primes.get(j+2) * primes.get(j+4);
            //     } else if (curr%7 == 2) {
            //         A[i] = primes.get(j+3) * primes.get(j+4);
            //     } else if (curr%7 == 3) {
            //         A[i] = primes.get(j+1) * primes.get(j+3);
            //     } else if (curr%7 == 4) {
            //         A[i] = primes.get(j+1) * primes.get(j+4);
            //     } else if (curr%7 == 5) {
            //         A[i] = primes.get(j) * primes.get(j+4);
            //     } else if (curr%7 == 6) {
            //         A[i] = primes.get(j) * primes.get(j+5);
            //     }

            //     // System.out.print("("+i+","+j+") ");

            //     if (A[i] > 1000000000) {
            //         //System.out.println(primes.get(j)+" "+A[i]);
            //         exceeded = true;
            //         break;
            //     }
            // }

            // //System.out.print("("+i+","+j+") ");

            // curr = i-6;

            // if (curr%7 == 0) {
            //     j += 2;
            //     A[i] = primes.get(1) * primes.get(j+3);
            // } else if (curr%7 == 1) {
            //     A[i] = primes.get(j+2) * primes.get(1);
            // } else if (curr%7 == 2) {
            //     A[i] = primes.get(1) * primes.get(j+4);
            // } else if (curr%7 == 3) {
            //     A[i] = primes.get(1) * primes.get(j+3);
            // } else if (curr%7 == 4) {
            //     A[i] = primes.get(1) * primes.get(j+1);
            // } else if (curr%7 == 5) {
            //     A[i] = primes.get(1) * primes.get(j+4);
            // } else if (curr%7 == 6) {
            //     A[i] = primes.get(1) * primes.get(j);
            // }

            if (!exceeded) {
                for (i = 0 ; i < N ; i++)
                    System.out.print(A[i]+" ");
                System.out.println();
            } else {
                System.out.println(-1);
            }
        }
    }
}