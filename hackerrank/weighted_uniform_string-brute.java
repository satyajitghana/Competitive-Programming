import java.util.*;

public class weighted_uniform_string {
	public static ArrayList<Integer> go(String str) {
		ArrayList<Integer> weights = new ArrayList<Integer>();
		HashSet<String> uniformString = new HashSet<String>();
		for (int i = 0 ; i < str.length() ; i++) {
			for (int j = i+1 ; j < str.length()+1 ; j++) {
				String subString = str.substring(i,j);
				//System.out.println(subString);
				if (checkUniform(subString)) {
					//System.out.println(subString);
					uniformString.add(subString);
				}
			}
		}
		for (String s : uniformString) {
			weights.add(getWeight(s));
		}
		//System.out.println(uniformString);
		//System.out.println(weights);
		return weights;
	}
	
	public static Integer getWeight(String str) {
		return ((int)str.charAt(0)-96)*str.length();
	}

	public static boolean checkUniform(String str) {
		for (int i = 0 ; i < str.length()-1 ; i++) {
			if (str.charAt(i) != str.charAt(i+1)) return false;
		}
		return true;
	}
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		String str = input.next();
		ArrayList<Integer> weights = go(str);
		int T = input.nextInt();
		while(T-- > 0) {
			Integer query = input.nextInt();
			if (weights.contains(query)) {
				System.out.println("YES");
			}
			else 
				System.out.println("NO");
		}
	}
}
