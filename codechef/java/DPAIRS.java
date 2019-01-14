import java.util.*;

// public class DPAIRS {
//     public static void main(String [] args) {
//         Scanner input = new Scanner(System.in);
//         int []A = new int[input.nextInt()];
//         int []B = new int[input.nextInt()];
//         for (int i = 0 ; i < A.length ; i++) {
//             A[i] = input.nextInt();
//         }
//         for (int i = 0 ; i < B.length ; i++) {
//             B[i] = input.nextInt();
//         }
//         int count = 0;
//         int max = A.length + B.length - 1;
//         Set<Integer> sums = new HashSet<>();
//         task:
//         for (int i = 0 ; i < A.length ; i++) {
//             for (int j = 0 ; j < B.length ; j++) {
//                 if (count >= max) break task;
//                 if (!(sums.contains(A[i]+B[j]))) {
//                     System.out.println(i+" "+j);
//                     sums.add(A[i]+B[j]);
//                     count++;
//                 }
//             }
//         }
//     }
// }
public class DPAIRS {
        public static void main(String [] args) {
            Scanner input = new Scanner(System.in);
            int []A = new int[input.nextInt()];
            int []B = new int[input.nextInt()];
            int maxInA = 0;
            int minInB = 0;
            for (int i = 0 ; i < A.length ; i++) {
                A[i] = input.nextInt();
                if (A[i] > A[maxInA])
                    maxInA = i;
            }
            for (int i = 0 ; i < B.length ; i++) {
                B[i] = input.nextInt();
                if (B[i] < B[minInB])
                    minInB = i;
            }

            for (int i = 0 ; i < B.length ; i++) {
                if (i != minInB)
                    System.out.println(maxInA+" "+i);
            }
            for (int i = 0 ; i < A.length ; i++) {
                System.out.println(i+" "+minInB);
            }
        }
    }