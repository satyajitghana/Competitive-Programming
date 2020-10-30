//Link to the question - https://www.hackerrank.com/challenges/fair-rations/problem
import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the fairRations function below.
    static int fairRations(int[] B) {
     int sum=0;
     int cnt=0;
     for(int i=0;i<B.length;i++){
         sum=sum+B[i];
     }
     if(sum%2!=0) return -1;
     else{
         for(int i=0;i<B.length;i++){
             if(B[i]%2!=0){
                 B[i]++;
                 B[i+1]++;
                cnt=cnt+2;
             }
         }
         return cnt;
     }

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int N = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] B = new int[N];

        String[] BItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < N; i++) {
            int BItem = Integer.parseInt(BItems[i]);
            B[i] = BItem;
        }

        int result = fairRations(B);
        if(result!=-1) bufferedWriter.write(String.valueOf(result));
        else bufferedWriter.write("NO");
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
