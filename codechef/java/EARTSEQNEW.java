import java.util.*;

public class EARTSEQNEW {

    public static ArrayList<Integer> sieveN(int n) { 
        boolean prime[] = new boolean[n+1];

        for(int i = 0 ; i < n ; i++) 
            prime[i] = true; 
          
        for(int p = 2 ; p*p <= n ; p++) { 
            if(prime[p] == true) { 
                for(int i = p*p; i <= n; i += p) 
                    prime[i] = false; 
            } 
        } 
        
        ArrayList<Integer> primes = new ArrayList<>();

        for(int i = 2; i <= n; i++) { 
            if(prime[i] == true) 
                primes.add(i); 
        }

        return primes;
    }

    public static ArrayList<Integer> primes = sieveN(5000);

    public static int cnt = 0;

    public static void solve(boolean A[][], int curr, int size, int max) {
        int i = 0;

        for (; i < size ; i++) {
            if (cnt == max) return;
            if (!A[curr][i] && !A[i][curr] && (curr != i)) {
                A[curr][i] = true;
                cnt++;
                // System.out.print("*" + curr + " " + i + " " + primes.get(curr) * primes.get(i)+" "+"*");
                System.out.print(primes.get(curr) * primes.get(i) + " ");
                break;
            }
        }
        
        solve(A, i, size, max);
    }

    public static void main(String [] args) {
        Scanner input = new Scanner(System.in);
        int T = input.nextInt();
        while (T-- > 0) {
            int N = input.nextInt();
            boolean [][]A = new boolean[500][500];
            int n = (int)Math.sqrt(5*N);
            cnt = 0;
            int i;
            for (i = 0 ; i < n-1 ; i++) {
                A[i][i+1] = true;
                cnt++;
                System.out.print(primes.get(i)*primes.get(i+1)+" ");
            }

            solve(A, i, n, N);

            System.out.println();
        }
    }
}