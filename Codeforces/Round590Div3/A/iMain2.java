import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;
 
public class iMain2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int q = scanner.nextInt();
        for (int i = 0; i < q; i++) {
            double n = scanner.nextInt();
            double sum = 0;
            for (int j = 0; j < n; j++) {
                sum += scanner.nextInt();
            }
            System.out.println((int) Math.ceil(sum / n));
        }
 
    }
}
