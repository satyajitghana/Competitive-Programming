import java.util.*;
import java.util.stream.*;

public class L56LABY {
	public class Cell {
		int x;
		int y;
		int time;
	
		Cell(int x, int y, int time) {
			this.x = x;
			this.y = y;
			this.time = time;
		}
	}

	public static void go(ArrayList < ArrayList <Integer>> laby) {
		ArrayList < ArrayList <Boolean>> escape = Arrays.stream(new Boolean[laby.size()][laby.get(0).size()])
												 .map( i -> Arrays.stream(i)
																  .map(j -> false)
																  .collect(Collectors.toCollection(ArrayList::new)))
												 .collect(Collectors.toCollection(ArrayList::new));
	}
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		while (T-- > 0) {
			ArrayList <ArrayList <Integer>> laby = Arrays.stream(new Integer[input.nextInt()][input.nextInt()])
													.map(i -> Arrays.stream(i)
																	.map(j -> input.nextInt())
																	.collect(Collectors.toCollection(ArrayList::new)))
													.collect(Collectors.toCollection(ArrayList::new));
			go(laby);
		}
	}
}
