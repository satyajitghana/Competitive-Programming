//Link to question - https://www.hackerrank.com/challenges/between-two-sets/problem
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

public class Solution {

    /*
     * Complete the getTotalX function below.
     */
    static int getTotalX(int[] a, int[] b) {
        int l=a.length;
        int num=a[l-1];
        int cnt1=0;
        int cnt2=0;
        int cnt=0;
        for(int i=num;i<=b[0];i++){
            cnt1=0;
            cnt2=0;
            for(int j=0;j<l;j++){
                if(i%a[j]==0) cnt1++;
            }
            for(int j=0;j<b.length;j++){
                if(b[j]%i==0) cnt2++;
            }
            if(cnt1==l && cnt2==b.length) cnt++;
        }
        return cnt;
    }

    private static final Scanner scan = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nm = scan.nextLine().split(" ");

        int n = Integer.parseInt(nm[0].trim());

        int m = Integer.parseInt(nm[1].trim());

        int[] a = new int[n];

        String[] aItems = scan.nextLine().split(" ");

        for (int aItr = 0; aItr < n; aItr++) {
            int aItem = Integer.parseInt(aItems[aItr].trim());
            a[aItr] = aItem;
        }

        int[] b = new int[m];

        String[] bItems = scan.nextLine().split(" ");

        for (int bItr = 0; bItr < m; bItr++) {
            int bItem = Integer.parseInt(bItems[bItr].trim());
            b[bItr] = bItem;
        }

        int total = getTotalX(a, b);

        bw.write(String.valueOf(total));
        bw.newLine();

        bw.close();
    }
}
