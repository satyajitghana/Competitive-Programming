import java.util.*;

public class UCL {
    public static void main(String [] args) {
        Scanner input = new Scanner(System.in);
        int T = input.nextInt();
        while(T-- > 0) {
            String x, y, z;
            int a, b;
            HashMap <String, Integer> m1 = new HashMap<>();
            HashMap <String, Integer> m2 = new HashMap<>();

            for (int i = 0 ; i < 12 ; i++) {
                x = input.next();
                a = input.nextInt();
                z = input.next();
                b = input.nextInt();
                y = input.next();

                m1.putIfAbsent(x, 0);
                m1.putIfAbsent(y, 0);
                m2.putIfAbsent(x, 0);
                m2.putIfAbsent(y, 0);

                if(a>b){
                    
                    // m1[x]+=3;
                    m1.replace(x, m1.get(x) + 3);
                    // m2[x]+=a-b;
                    m2.replace(x, m2.get(x) + a-b);
                    // m2[y]+=b-a;
                    m2.replace(y, m2.get(y) + b-a);
                } 
     
                else if( b>a){
                    // m1[y]+=3;
                    m1.replace(y, m1.get(y) + 3);
                    // m2[y]+=b-a;
                    m2.replace(y, m1.get(y) + b-a);
                    // m2[x]+=a-b;
                    m2.replace(x, m1.get(x) + a-b);
                } 
     
                else {
                    // m1[y]+=1;
                    m1.replace(y, m1.get(y) + 1);
                    // m1[x]+=1;
                    m1.replace(x, m1.get(x) + 1);
                }
            }
            ArrayList<HashMap<Integer, HashMap<Integer, String>>> vec = new ArrayList<>();

            // TreeMap <Integer, HashMap<Integer, String>> sorted = new TreeMap<>();
            for (String key : m1.keySet()) {
                HashMap<Integer, String> t = new HashMap<>();
                t.put(m2.get(key), key);
                HashMap<Integer, HashMap<Integer, String>> t2 = new HashMap<>();
                t2.put(m1.get(key), t);
                vec.add(t2);
                // sorted.put(m1.get(key), t);
            }
            System.out.println(m1);
            System.out.println(m2);
            System.out.println(vec);
        }
    }
}