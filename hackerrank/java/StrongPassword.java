import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    static int minimumNumber(int n, String password) {
        int d=0,u=0,low=0,sc=0,ch,num;
        for(int i=0;i<n;i++)
        {
            char c=password.charAt(i);
            if(Character.isDigit(c)==true)
             {
                if(d<=0)
                d++;
                else
                    continue;                
            }
             
           if(Character.isUpperCase(c)==true)
               {
                if(u<=0)
                u++;
                else
                    continue;                
            }
           if(Character.isLowerCase(c)==true)
               {
                if(low<=0)
                low++;
                else
                    continue;                
            }
            if(c==33||(c>=35&&c<=38)||(c>=40&&c<=43)||c==45||c==64||c==94)
            {
                if(sc<=0)
                sc++;
                else
                    continue;                
            }        
             }   
        num=sc+u+low+d;
        ch=4-num;
        if(ch==4&&n>=6)
            return 0;
        else if(ch==4&&n<6)
            return 1;
        else if(ch<4&&n>=6)
            return (ch);
        else if(ch<4&&n<6)
        {
            if((ch+n)>=6)
                return (ch);
                else
            return((ch+(6-(n+ch))));  
        }
        else return 0;       
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        String password = in.next();
        int answer = minimumNumber(n, password);
        System.out.println(answer);
        in.close();
    }
}
