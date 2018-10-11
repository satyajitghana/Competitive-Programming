import java.util.*;
import java.lang.Math;

public class powersum {
  public static int sum(int number,int power,int currNum) {
    int remaining = number - (int)Math.pow(currNum,power);
    if (remaining < 0) {
      return 0;
    }
    else if (remaining == 0) {
      return 1;
    }
    else {
      return (sum(remaining,power,currNum+1)+sum(number,power,currNum+1));
    }
  }
  public static void main(String [] args) {
    Scanner input = new Scanner(System.in);
    int number = input.nextInt();
    int power = input.nextInt();
    System.out.println(sum(number,power,1));
  }
}
