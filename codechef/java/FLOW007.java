/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class FLOW007 {
	public static void main (String[] args) throws java.lang.Exception {
	    Scanner input = new Scanner(System.in);
        int N = Integer.parseInt(input.nextLine());
        while (N-- > 0) {
            StringBuilder str = new StringBuilder(input.nextLine().trim());
            str.reverse();
            System.out.println(Integer.parseInt(str.toString()));
        }
	}
}