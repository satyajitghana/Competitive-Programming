import java.util.*;
import java.util.stream.Collectors;

public class CHEFING {
    public static void main(String [] args) {
        Scanner input = new Scanner(System.in);
        int T = Integer.parseInt(input.nextLine());
        while (T-- > 0) {
            int N = Integer.parseInt(input.nextLine());
            int TString = N;
            HashMap<Character, Integer> counter = new HashMap<>(); 
            while (N-- > 0) {
                String str = input.nextLine().trim();
                Set<Character> myset = new HashSet<>();
                myset.addAll(str.chars().mapToObj(e -> (char)e).collect(Collectors.toList()));
                for (Character e : myset) {
                    if (counter.containsKey(e)) {
                        counter.replace(e, counter.get(e)+1);
                    } else {
                        counter.put(e, 1);
                    }
                }
            }
            Integer count = 0;
            for (Integer cnt : counter.values()) {
                if (cnt == TString) {
                    count++;
                }
            }
            System.out.println(count);
        }
    }
}