import java.util.*;

public class SMANAGE {

    public static ArrayList<String> solve(ArrayList<String> names) {
        HashSet<String> s = new HashSet<>();
        HashMap<String, Integer> m = new HashMap<>();
        ArrayList<String> l = new ArrayList<>();

        for (String name: names) {
            if (m.containsKey(name)) {
                int n = m.get(name);
                m.put(name, n+1);
                l.add(name+" "+Integer.toString(n+1));
            } else {
                m.put(name, 1);
                String t = "";
                boolean inserted = false;
                for (char c : name.toCharArray()) {
                    t += c;
                    if (!inserted && !s.contains(t)) {
                        inserted = true;
                        l.add(t);
                    }
                    s.add(t);
                }
                if (!inserted) l.add(t);
            }
        }
        return l;
    }
    public static void main(String [] args) {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        ArrayList<String> S = new ArrayList<>();
        for (int i = 0 ; i < N ; i++) {
            S.add(input.next());
        }

        S = solve(S);

        for (String str: S) {
            System.out.println(str);
        }
    }
}