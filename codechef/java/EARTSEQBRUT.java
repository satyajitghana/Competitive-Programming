public class EARTSEQBRUT {
    public static int gcd(int a, int b) { 
      if (b == 0) 
        return a; 
      return gcd(b, a % b);  
    }

    public static void main(String [] args) {
        int N = 10;
        int A[] = new int[10];
        A[0] = 6;
        A[1] = 15;
        A[2] = 10;
        A[3] = 14;
        //A[2] = 15;
        //A[2] = 35;
        // A[3] = 77;
        // A[4] = 55;
        int n = 3;
        int prev2 = A[n-2];
        int prev = A[n-1];
        int next = A[0];
        int next2 = A[1];
        for (int i = 2 ; i < 1000 ; i++) {
            if (    (gcd(prev, i) != 1) &&
                    (gcd(i, next) != 1) &&
                    (gcd(prev2, gcd(prev, i)) == 1) &&
                    (gcd(prev, gcd(i, next)) == 1) &&
                    (gcd(i, gcd(next, next2)) == 1)) {
                System.out.println(i);
                break;
            }
        }
    }
}