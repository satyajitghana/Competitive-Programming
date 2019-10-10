//Link: https://www.hackerrank.com/challenges/plus-minus/problem

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the plusMinus function below.
    static void plusMinus(int[] arr, int n) {
        
        double pos=0; 
        double neg=0;
        double zero=0;
        for(int i=0; i<n; i++)
        {
            if(arr[i]>0)
            {
                pos++;
            }
            else if (arr[i]<0)
            {
                neg++;
            }
            else
                zero++;
        }

        System.out.println((pos/n+"\n"+(neg/n)+"\n"+(zero/n)));
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] arr = new int[n];

        String[] arrItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int arrItem = Integer.parseInt(arrItems[i]);
            arr[i] = arrItem;
        }

        plusMinus(arr, n);

        scanner.close();
    }
}
