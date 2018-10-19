/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hackerrank;

/**
 *
 * @author jai sudh
 */


/* Solution assumes we can't have the symbol "<" as text between tags */
import java.io.*; 
import java.util.*; 
import java.text.*; 
import java.math.*; 
import java.util.regex.*; 
 
public class End_Of_File { 
 
    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */ 
    Scanner userInput = new Scanner(System.in);
    int lineNum = 1;    
     
    while (userInput.hasNextLine() == true) {
    if (userInput.hasNext() == true) {
        System.out.println(lineNum + " " + userInput.nextLine());
        lineNum++;
    } 
    } 
     
    } 
}
