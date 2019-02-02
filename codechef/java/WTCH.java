import java.util.*;

public class WTCH {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int T = input.nextInt();
        while (T-- > 0) {
            int N = input.nextInt();
            String str1 = input.next();
            str1 = str1.trim();
            StringBuilder str = new StringBuilder(str1);
            int count = 0;
            boolean left, right;
            //System.out.println(str.length());
            for (int i = 0; i < str.length(); i++) {
                if (str.charAt(i) != '1') {
                    left = right =  true;
                    if ( ((i - 1) >= 0) && str.charAt(i-1) == '1') {
                        left = false;
                    }
                    if ( ((i + 1) < str.length()) && str.charAt(i+1) == '1') {
                        left = false;
                    }
                    if (left && right) {
                        str.setCharAt(i, '1');
                        count++;
                    }
                }
            }
            System.out.println(count);
        }
    }
}