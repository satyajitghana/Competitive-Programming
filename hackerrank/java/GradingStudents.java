import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

public class Solution {

    /*
     * Complete the gradingStudents function below.
     */
    static int[] gradingStudents(int[] grades) {
        
        int len=grades.length;
        int[] newgrades=new int[len];
        int k=0;
        
        for(int i=0;i<len;i++)
        {
            int quotient=grades[i]/5;
            if(grades[i]<38)
            {
                newgrades[k]=grades[i];
                k++;
            }
            
            else if((grades[i]%5)>=3)
            {
                newgrades[k]=5*(quotient+1);
                k++;
            }
            
            else
            {
                newgrades[k]=grades[i];
                k++;
            }
        }
        return newgrades;
    }

    private static final Scanner scan = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = Integer.parseInt(scan.nextLine().trim());

        int[] grades = new int[n];

        for (int gradesItr = 0; gradesItr < n; gradesItr++) {
            int gradesItem = Integer.parseInt(scan.nextLine().trim());
            grades[gradesItr] = gradesItem;
        }

        int[] result = gradingStudents(grades);

        for (int resultItr = 0; resultItr < result.length; resultItr++) {
            bw.write(String.valueOf(result[resultItr]));

            if (resultItr != result.length - 1) {
                bw.write("\n");
            }
        }

        bw.newLine();

        bw.close();
    }
}
