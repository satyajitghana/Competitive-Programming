/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Main
{
	public static String longestPalindrome(String s) {
        if (s == null || s.length() == 0) return "";
        if (s.length() == 1) return s;
        String ans = "";
        
        for (int i = 0; i < s.length() - 1; i++) {
            String s1 = longPalin(s, i, i);
            if (s1.length() > ans.length()) ans = s1;
            String s2 = longPalin(s, i, i + 1);            
            if (s2.length() > ans.length()) ans = s2;
        }
        
        return ans;
    }
    
    private static String longPalin(String s, int i, int j) {
        while (i >= 0 && j < s.length()) {
            if (s.charAt(i) != s.charAt(j)) break;
            i--;
            j++;
        }
        return s.substring(i + 1, j);
    }
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner input = new Scanner(System.in);
		int N = input.nextInt();
		String myString;
		myString = input.next();
		//subStrings(myString);
		String longest  = longestPalindrome(myString);
		//System.out.println(longestPalindrome(myString));
		System.out.println(longest.length());
		System.out.println(longest);
	}
}
