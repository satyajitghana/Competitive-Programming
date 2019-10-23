import java.util.*;

public class PERMPAL_NEW {
	public static int search(String str, boolean []visited, int start, char toSearch) {
		for (int i = start ; i < str.length(); i++) {
			//System.out.println(str.charAt(i) + " " + toSearch + " " + Arrays.toString(visited));
			if (str.charAt(i) == toSearch) {
				if (visited[i] == false)
					return i;
			}
			//if ((str.charAt(i) == toSearch) && (visited[i] == false)) return i;
		}
		return -1;
	}
	public static void go(String string) {
		int []firstHalf = new int[string.length()/2 + 1];
		int []secondHalf = new int[string.length()/2 + 1];
		boolean []visited = new boolean[string.length()];
		//System.out.println(Arrays.toString(visited));
		int firstSize = 0;
		int secondSize = 0;
		char aloneCharacter = ' ';
		int aloneIndex = -1;
		int aloneCharacters = 0;
		int i = 0;
		int deleted = 0;
		for (i = 0 ; i < string.length() ; i++) {
			if (visited[i] == true) continue;
			char curr = string.charAt(i);
			visited[i] = true;
			int search = search(string, visited, i+1, curr);
			if (search < 0) {
				aloneIndex = i;
				aloneCharacters++;
				if (aloneCharacters > 1) {
					System.out.println(-1);
					return;
				}
				continue;
			}
			visited[search] = true;
			firstHalf[firstSize++] = i + 1;
			secondHalf[secondSize++] = search + 1;
		}
		StringBuilder output = new StringBuilder("");
		for (int j = 0 ; j < firstSize ; j++) {
			output.append(firstHalf[j] + " ");
		}
		if (aloneIndex != -1) output.append(aloneIndex + 1 + " ");
		for (int j = secondSize -1 ; j >=0 ; j--) {
			output.append(secondHalf[j] + " ");
		}
		System.out.println(output);
	}
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		while (T-- > 0) {
			//StringBuilder str = new StringBuilder(input.next());
			String str = input.next();
			go(str);
		}
	}
}
