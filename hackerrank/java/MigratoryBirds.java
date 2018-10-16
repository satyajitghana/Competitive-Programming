/* Link to problem on Hackerrank is https://www.hackerrank.com/challenges/migratory-birds/problem */

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the migratoryBirds function below.
    static int migratoryBirds(List<Integer> arr, int n) {
    int[] a=new int[5];
    for(int i=0;i<n;i++)
    {
        int no=arr.get(i);
        a[(no-1)]++;
    }
        int max=a[0];
        int fix=0;
    for(int k=0;k<5;k++)
    {
        if(a[k]>max)
        {
            fix=k;
            max=a[k];
        }
        else if(a[k]==max)
        {
            if(fix>k)
                fix=k;
        }
    }
        return (fix+1);

    }

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int arrCount = Integer.parseInt(bufferedReader.readLine().trim());

        String[] arrItems = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        List<Integer> arr = new ArrayList<>();

        for (int i = 0; i < arrCount; i++) {
            int arrItem = Integer.parseInt(arrItems[i]);
            arr.add(arrItem);
        }

        int result = migratoryBirds(arr, arrCount);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
