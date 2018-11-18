import java.util.*;

public class COOK100B {
    public static void main(String [] args) {
        Scanner input = new Scanner(System.in);
        int T = input.nextInt();
        while (T-- > 0) {
            ArrayList<Integer> ramTruth = new ArrayList<>();
            ArrayList<Integer> ramDare = new ArrayList<>();

            int ramT = input.nextInt();
            while(ramT -- > 0) {
                ramTruth.add(input.nextInt());
            }
            int ramD = input.nextInt();
            while(ramD -- > 0) {
                ramDare.add(input.nextInt());
            }

            ArrayList<Integer> sTruth = new ArrayList<>();
            ArrayList<Integer> sDare = new ArrayList<>();
            
            int sT = input.nextInt();
            while(sT -- > 0) {
                sTruth.add(input.nextInt());
            }
            int sD = input.nextInt();
            while(sD -- > 0) {
                sDare.add(input.nextInt());
            }
            // System.out.println(ramTruth+ "\n"+ramDare+"\n"+sTruth+"\n"+sDare);
            boolean win = true;
            for (Integer t: sTruth) {
                if (!ramTruth.contains(t)) {
                    win = false;
                    break;
                }
            }
            for (Integer d: sDare) {
                if (!ramDare.contains(d)) {
                    win = false;
                    break;
                }
            }

            if (win) System.out.println("yes");
            else System.out.println("no");
        }
    }
}