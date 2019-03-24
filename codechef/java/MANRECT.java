import java.util.*;

public class MANRECT {
    public static void solve() {
        int N = 100000;
        Scanner input = new Scanner(System.in);
        int x = 0, y = 0;
        int mx = N+1, my = N+1;
        here:
        for (int i = 0 ; i < N ; i++) {
            for (int j = 0 ; j < N ; j++) {
                System.out.println("Q "+(i+1)+" "+(j+1));
                String response = input.next();
                // if (Integer.parseInt(response) == 0) {
                //     break here;
                // }
                if (Integer.parseInt(response) != 1) {
                    x = Math.max(x, i);
                    y = Math.max(y, j);
                    mx = Math.min(i, mx);
                    my = Math.min(j, my);
                }
            }
        }
        // System.out.println("A "+x+" "+mx+" "+y+" "+my);
        System.out.println("A "+x+" "+y+" "+mx+" "+my);
        String response = input.next();
    }
    public static void main(String [] args) {
        Scanner input = new Scanner(System.in);
        int T = input.nextInt();
        while (T-- > 0) {
            solve();
        }
    }
}