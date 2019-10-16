//Link to question - https://www.hackerrank.com/challenges/service-lane/problem
import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {
  public static void main(String args[]){
      Scanner s=new Scanner(System.in);
      int n=s.nextInt();
      int t=s.nextInt();
      int j=0;
      int k=0;
      int min=0;
      int arr[]=new int[n];
      for(int i=0;i<n;i++){
         arr[i]=s.nextInt();
      }
      for(int i=0;i<t;i++){
         j=s.nextInt();
         k=s.nextInt();
         min=arr[j];
         for(int p=j+1;p<=k;p++){
             if(min>=arr[p]) min=arr[p];
         }
         System.out.println(min);
      }
  }
 }
