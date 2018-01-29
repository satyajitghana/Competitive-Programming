import java.util.*;

public class ZCO16001 {
  public static int skew(int []arr1, int []arr2, int k, int n) {
    int small,temp,a;
    small = max(arr2);
    for (int i = 1 ; i <= k ; i++) {
      temp = arr2[n-i];
      arr2[n-i]=arr1[i-1];
      arr1[i-1]=temp;
      a=max(arr2);
      if(a<small) small=a;
    }
    return small;
  }
  public static int max(int []arr) {
    int maxi = 0;
    for (int i = 0 ; i < arr.length ; i++) {
      if (arr[i] > maxi) maxi = arr[i];
    }
    return maxi;
  }
  public static void main(String [] args) {
    Scanner input = new Scanner(System.in);
    int N,K,ANS;
    N = input.nextInt();
    K = input.nextInt();
    int []A = new int[N];
    int []B = new int[N];

    for (int i = 0 ; i < N ; i++)
      A[i] = input.nextInt();
    for (int j = 0 ; j < N ; j++)
      B[j] = input.nextInt();
    Arrays.sort(A);
    Arrays.sort(B);
    int []C = Arrays.copyOf(A,A.length);
    int []D = Arrays.copyOf(B,B.length);
    if (A[A.length-1] > B[B.length-1]) {
      ANS = A[A.length-1] + Math.min( skew(A,B,K,N), skew(D,C,K,N) );
    }
    else {
      ANS = B[B.length-1] + Math.min( skew(A,B,K,N), skew(D,C,K,N) );
    }
    System.out.println(ANS);
  }
}
