import java.util.*;
 
public class iMain2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        Deque<Integer> deque = new LinkedList<>();
        HashSet<Integer> hashSet = new HashSet<>();
        for (int i = 0; i < n; i++) {
            int x = scanner.nextInt();
            if (!hashSet.contains(x)){
                if (deque.size() == k) {
                    int ss = deque.removeLast();
                    deque.addFirst(x);
                    hashSet.remove(ss);
                    hashSet.add(x);
                }else {
                    hashSet.add(x);
                    deque.addFirst(x);
                }
            }
        }
        System.out.println(deque.size());
        while (!deque.isEmpty())
            System.out.print(deque.poll() +  " ");
 
    }
}
