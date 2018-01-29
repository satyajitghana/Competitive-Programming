import java.util.*;
import java.util.stream.*;

class Cell implements Comparable<Cell> {
	public int x;
	public int y;
	public int time;

	public Cell(int x, int y, int time) {
		this.x = x;
		this.y = y;
		this.time = time;
	}
	public int getX() {return x;}
	public int getY() {return y;}
	public int getTime() {return time;}

	public int compareTo(Cell a) {
		return a.time - this.time;
	}
}

public class L56LABY {
	static boolean [][]escape;
	static int [][]laby;
	
	public static boolean isValidMove(int x, int y, int N, int M) {
		if (x >= 0 && x < N && y >= 0 && y < M) return true;
		return false;
	}

	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		while (T-- > 0) {
			laby = new int[input.nextInt()][input.nextInt()];
			for (int i = 0 ; i < laby.length ; i++) {
				for (int j = 0 ; j < laby[i].length ; j++) {
					laby[i][j] = input.nextInt();
				}
			}
		escape = new boolean[laby.length][laby[0].length];
		PriorityQueue <Cell> queue = new PriorityQueue <Cell>();

		for (int i = 0 ; i < laby.length; i++) {
			for (int j = 0 ; j < laby[i].length ; j++) {
				if (laby[i][j] > 0) queue.add(new Cell(i,j,laby[i][j]));
			}
		}
		int N = laby.length;
		int M = laby[0].length;
		while(!queue.isEmpty()) {
			Cell currCell = queue.poll();
			int i = currCell.getX();
			int j = currCell.getY();
			escape[i][j] = true;
			int time = currCell.getTime();
			time--;
			if ( time < 0 ) continue;

			//Move Right
			if (isValidMove(i+1,j,N,M) && !escape[i+1][j] && laby[i+1][j] != -1) {
				escape[i+1][j] = true;
				queue.add(new Cell(i+1,j,time));
			}
			//Move Down
			if (isValidMove(i,j+1,N,M) && !escape[i][j+1] && laby[i][j+1] != -1) {
				escape[i][j+1] = true;
				queue.add(new Cell(i,j+1,time));
			}
			//Move Left
			if (isValidMove(i-1,j,N,M) && !escape[i-1][j] && laby[i-1][j] != -1) {
				escape[i-1][j] = true;
				queue.add(new Cell(i-1,j,time));
			}
			//Move Up
			if (isValidMove(i,j-1,N,M) && !escape[i][j-1] && laby[i][j-1] != -1) {
				escape[i][j-1] = true;
				queue.add(new Cell(i,j-1,time));
			}
		}
		//Print the Grid
		StringBuilder string = new StringBuilder();
		for (int i = 0 ; i < N ; i++) {
			for (int j = 0 ; j < M ; j++) {
				if (escape[i][j]) string.append("Y");
				else if (laby[i][j] == -1) string.append("B");
				else string.append("N");
			}
			string.append("\n");
		}
		System.out.print(string);
		}
	}
}
