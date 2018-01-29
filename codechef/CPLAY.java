import java.util.*;
import java.io.*;

public class CPLAY {
	public static String after(String str) {
		//Sudden Death, evaluate next 10 shots
		int i;
		char expected = '0';
		for (i = str.length()/2 ; i < str.length() ; i++) {
			if (i%2==0) {
				if (str.charAt(i)=='1')
					expected = '1';
				else
					expected = '0';
			}
			else {
				if (str.charAt(i) == '1' & expected == '0')
					return ("TEAM-B " + Integer.toString(i+1));
				else if (str.charAt(i) == '0' & expected == '1')
					return ("TEAM-A " + Integer.toString(i+1));
			}
		}
		//no-one returned anything, hence it was a "TIE"
		return "TIE";
	}
	public static String go(String str) {
		int teamA=0,teamB=0;
		int remA=5,remB=5;
		//Evaluate first 10 shots
		int i;
		for (i = 0 ; i < str.length()/2 ; i++) {
			if (i%2==0) {
				if (str.charAt(i)=='1')
					teamA++;
				remA--;
			}
		       	else {
				if (str.charAt(i)=='1')
					teamB++;
				remB--;
			}
			if (teamA > teamB+remB) return ("TEAM-A " + Integer.toString(i+1));
			else if (teamB > teamA+remA) return("TEAM-B " + Integer.toString(i+1));
		}
		if (teamA == teamB)
		//Sudden Death Start
		return after(str);
		else if (teamA > teamB ) return ("TEAM-A " + Integer.toString(i+1));
		else return ("TEAM-B " + Integer.toString(i+1));
	}
	public static void main(String [] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String string;
	        while ((string = br.readLine()) != null ) {
			System.out.println(go(string));
		}
		
	}
}
