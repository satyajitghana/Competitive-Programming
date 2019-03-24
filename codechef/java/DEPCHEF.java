import java.util.*;

public class DEPCHEF {
    public static void main(String [] args) {
        Scanner input = new Scanner(System.in);
        int T = input.nextInt();
        while (T-- > 0) {
            int N = input.nextInt();
            ArrayList<Integer> A = new ArrayList<>();
            ArrayList<Integer> D = new ArrayList<>();
            for (int i = 0 ; i < N ; i++) {
                A.add(input.nextInt());
            }
            for (int i = 0 ; i < N ; i++) {
                D.add(input.nextInt());
            }
            
            int res = -1;
            for (int i = 0 ; i < N ; i++) {
                if ( i == 0) {
                    if (D.get(i) > A.get(N-1) + A.get(i+1)) {
                        res = D.get(i);
                    }
                } else {
                    if (D.get(i) > A.get((i+1)%N) + A.get(i-1)) {
                        if ( res < D.get(i)) {
                            res = D.get(i);
                        }
                    }
                }
            }
            System.out.println(res);
        }
    }
}