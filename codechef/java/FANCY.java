import java.util.*;

public class FANCY {
    public static void main(String [] args) {
        Scanner input = new Scanner(System.in);
        int T = Integer.parseInt(input.nextLine());
        while(T-- > 0) {
            String str = input.nextLine();
            String[] splitted = str.trim().split("\\s+");
            boolean found = false;
            for (int i = 0 ; i < splitted.length ; i++) {
                if (splitted[i].equals("not")) {
                    System.out.println("Real Fancy");
                    found = true;
                    break;
                }
            }
            if (!found) {
                System.out.println("regularly fancy");
            }
        }
    }
}