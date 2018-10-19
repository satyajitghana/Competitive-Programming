/** Project Euler.net
* 
* PROBLEM 1:
*    If we list all the natural numbers below 10 that are multiples of 3  
*    or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
*
*    Find the sum of all the multiples of 3 or 5 below 1000.
*
* ANSWER: 
*    The sum is: 233168
*
* @author ndkerby
*/

public class Multiples  {

    public static final int MAX = 1000;

    public static void main(String[] args) {
        int total=0;
        for( int number = 1; number < MAX; number++){
            if ( number %3 == 0 || number%5 == 0){
                total += number;
            }
        }
        System.out.println("The total is: " + total );   
    } 
}
