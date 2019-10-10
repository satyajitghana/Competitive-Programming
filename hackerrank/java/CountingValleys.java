// Link: https://www.hackerrank.com/challenges/counting-valleys/problem
import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the countingValleys function below.
    static int countingValleys(int n, String s) {
        int sealevel = 0;
        int valleys = 0;
        char ch1 = s.charAt(0);
        if( ch1 == 'D' ) {
            sealevel --;
            int original = sealevel;
            for(int i = 1; i<s.length(); i++) {
                char ch = s.charAt(i);
                if ( ch == 'U')
                {
                    original = sealevel;
                    sealevel ++;
                    if (sealevel == 0 && original<0)
                    {
                        valleys++;
                    }
                }
                else
                {
                    sealevel --;
                }
            } 
        }//i.e. started with D
        else {
            sealevel ++;
            int original = sealevel;
            for(int i = 1; i<s.length(); i++) {
                char ch = s.charAt(i);
                if ( ch == 'U')
                {
                    original = sealevel;
                    sealevel ++;
                    if (sealevel == 0 && original<0)
                    {
                        valleys++;
                    }
                }
                else
                {
                    sealevel --;
                }

            } //i.e. started with U
        }
        return valleys;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        String s = scanner.nextLine();

        int result = countingValleys(n, s);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
