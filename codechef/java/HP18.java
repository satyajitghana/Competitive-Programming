import java.util.*;

// public class HP18 {
//     public static void main(String [] args) {
//         Scanner input = new Scanner(System.in);
//         int T = input.nextInt();
//         while (T-- > 0) {
//             int []A = new int[input.nextInt()];
//             int a = input.nextInt();
//             int b = input.nextInt();
//             int counta = 0;
//             int countb = 0;
//             int countcommon = 0;
//             for (int i = 0 ; i < A.length ; i++) {
//                 A[i] = input.nextInt();
//                 if (A[i]%a == 0) counta++;
//                 if (A[i]%b == 0) countb++;
//                 if (A[i]%a == 0 & A[i]%b == 0) countcommon++;
//             }
//             // if a=b then BOB wins
//             System.out.println("ca"+counta+"cb"+countb+"cc"+countcommon);
//             if (a == b) {
//                 System.out.println("BOB");
//             } else {
//                 counta -= countcommon;
//                 countb -= countcommon;
//                 // now its ALICE's turn
//                 if (countb > counta) {
//                     System.out.println("ALICE");
//                 } else {
//                     System.out.println("BOB");
//                 }
//             }
//         }
//     }
// }

import java.util.*;

class HP18 {
    public static void main(String [] args) {
        Scanner input = new Scanner(System.in);
        int T = input.nextInt();
        while (T-- > 0) {
            int []A = new int[input.nextInt()];
            int a = input.nextInt();
            int b = input.nextInt();
            int counta = 0;
            int countb = 0;
            int countcommon = 0;
            for (int i = 0 ; i < A.length ; i++) {
                A[i] = input.nextInt();
                if (A[i]%a == 0 && A[i]!=0) counta++;
                if (A[i]%b == 0 && A[i]!=0) countb++;
                if (A[i]%a == 0 && A[i]%b == 0 && (A[i]!=0)) countcommon++;
            }
            // if the count is same i.e. a=b then BOB wins
            if (a == b) {
                System.out.println("BOB");
            } else {
                counta -= countcommon;
                countb -= countcommon;
                // now its ALICE's turn
                if((countcommon==0 && counta>countb)  || (counta>=countb && countcommon>0)) {
                    System.out.println("BOB");
                } else {
                    System.out.println("ALICE");
                }
            }
        }
    }
}