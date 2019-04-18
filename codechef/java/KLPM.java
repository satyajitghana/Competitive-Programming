import java.io.BufferedReader; 
import java.io.IOException; 
import java.io.InputStreamReader; 
import java.util.Scanner; 
import java.util.StringTokenizer; 

public class KLPM {
    // https://www.geeksforgeeks.org/fast-io-in-java-in-competitive-programming/
    static class FastReader { 
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    } 

    public static short [][]dp = new short[1000][1000];

    public static short check(String s, int val[][], int i, int j) {
        if (dp[val[i][0]][val[j][1] - 1] == 0) {
            return 0;
        }
        
        int s_i = val[i][1] +val[j][1] - val[i][0] - val[j][0];
        int a = val[i][0];
        int b = val[j][1] - 1;
        while (a < b) {
            if (s.charAt(a) != s.charAt(b)) {
                if (dp[val[i][0]][val[j][1] - 1] == -1 && s_i == 2) {
                    dp[val[i][0]][val[j][1] - 1] = 0;
                }
                return 0;
            }
            a += 1; b -= 1;
            if (a == val[i][1]) {
                a = val[j][0];
            }
            if (b == val[j][0] - 1) {
                b = val[i][1] - 1;
            }
        }
        if (dp[val[i][0]][val[j][1] - 1] == -1 && s_i == 2) {
            dp[val[i][0]][val[j][1] - 1] = 1;
        }
        return 1;
    }
    public static void main(String [] args) {
        // Scanner input = new Scanner(System.in);
        FastReader input = new FastReader();
        String s = input.next();
        s = s.trim();
        for (int i = 0 ; i < 1000 ; i++) {
            for (int j = 0 ; j < 1000 ; j++) {
                dp[i][j] = -1;
            }
        }
        long len = s.length();
        long tot = len * (len + 1) / 2;
        int [][]val = new int[(int)tot][2];
        int k = 0;
        for (int i = 1 ; i <= len ; i++) {
            for (int j = 0 ; j < len-i+1 ; j++) {
                val[k][0] = j;
                val[k++][1] = j + i;
            }
        }
        long count = 0;
        for (int i = 0 ; i < tot ; i++) {
            for (int j = i+1 ; j < tot ; j++) {
                if (val[i][1] <= val[j][0]) {
                    count += check(s, val, i, j);
                }
                if (val[i][0] >= val[j][1]) {
                    count += check(s, val, j, i);
                }
            }
        }

        System.out.println(count);
    }
}