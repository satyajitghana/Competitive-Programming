import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the minimumBribes function below.
    static void minimumBribes(int[] arr) {
        int swaps=0,flag=0;
        for(int i=arr.length-1; i>=0; i--)
        {
            if(arr[i]!=(i+1))
            {
                
                if((i+1)==arr[i-1])
                {
                    int temp=arr[i];
                    arr[i]=arr[i-1];
                    arr[i-1]=temp;
                    swaps++;
                }      
                else if((i+1)==arr[i-2])
                {
                    int temp=arr[i-2];
                    arr[i-2]=arr[i-1];
                    arr[i-1]=arr[i];
                    arr[i]=temp;
                    swaps+=2;
                }
                else
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag==0)
        {
            System.out.println(swaps);
        }
        else
        System.out.println("Too chaotic");

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int t = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int tItr = 0; tItr < t; tItr++) {
            int n = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            int[] q = new int[n];

            String[] qItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int i = 0; i < n; i++) {
                int qItem = Integer.parseInt(qItems[i]);
                q[i] = qItem;
            }

            minimumBribes(q);
        }

        scanner.close();
    }
}
