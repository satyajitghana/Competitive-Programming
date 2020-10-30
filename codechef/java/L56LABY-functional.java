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
		public static void go(List < List <Integer>> laby) {
		List < List <Boolean>> escape = Arrays.stream(new Boolean[laby.size()][laby.get(0).size()])
												 .map( i -> Arrays.stream(i)
																  .map(j -> false)
																  .collect(Collectors.toList()))
												 .collect(Collectors.toList());
		/*PriorityQueue <Cell> queue = new PriorityQueue <>(new Comparator<Cell>() {
			@Override
			public int compare(Cell a1, Cell a2) {
				return a2.getTime()-a1.getTime();
			}
		});*/

		PriorityQueue <Cell> queue = new PriorityQueue <Cell>();

		for (int i = 0 ; i < laby.size() ; i++) {
			for (int j = 0 ; j < laby.get(i).size() ; j++) {
				if (laby.get(i).get(j) > 0) queue.add(new Cell(i,j,laby.get(i).get(j)));
			}
		}
		int N = laby.size();
		int M = laby.get(0).size();
		while(!queue.isEmpty()) {
			Cell currCell = queue.poll();
			int i = currCell.getX();
			int j = currCell.getY();
			escape.get(i).set(j,true);
			int time = currCell.getTime();
			time--;
			if ( time < 0 ) continue;

			//Move Right
			if (isValidMove(i+1,j,N,M) && !escape.get(i+1).get(j) && laby.get(i+1).get(j) != -1) {
				escape.get(i+1).set(j,true);
				queue.add(new Cell(i+1,j,time));
			}
			//Move Down
			if (isValidMove(i,j+1,N,M) && !escape.get(i).get(j+1) && laby.get(i).get(j+1) != -1) {
				escape.get(i).set(j+1,true);
				queue.add(new Cell(i,j+1,time));
			}
			//Move Left
			if (isValidMove(i-1,j,N,M) && !escape.get(i-1).get(j) && laby.get(i-1).get(j) != -1) {
				escape.get(i-1).set(j,true);
				queue.add(new Cell(i-1,j,time));
			}
			//Move Up
			if (isValidMove(i,j-1,N,M) && !escape.get(i).get(j-1) && laby.get(i).get(j-1) != -1) {
				escape.get(i).set(j-1,true);
				queue.add(new Cell(i,j-1,time));
			}
		}
		//List < List <Character>> escapeGrid = escape.stream().map(i -> i.stream().map(j -> (if(j) return 'Y';)).collect(Collectors.toList())).collect(Collectors.toList());
		ArrayList < ArrayList <Character>> escapeGrid = new ArrayList < ArrayList <Character>>();
		for (int i = 0 ; i < N ; i++) {
			ArrayList <Character> temp = new ArrayList <Character>();
			for (int j = 0 ; j < M ; j++) {
				temp.add('N');
				if (escape.get(i).get(j)) temp.set(j, 'Y');
				if (laby.get(i).get(j) == -1) temp.set(j,'B');
			}
			escapeGrid.add(temp);
		}
		//Print the Grid
		for (int i = 0 ; i < N ; i++) {
			for (int j = 0 ; j < M ; j++) {
				System.out.print(escapeGrid.get(i).get(j));
			}
			System.out.println();
		}
	}

	public static boolean isValidMove(int x, int y, int N, int M) {
		if (x >= 0 && x < N && y >= 0 && y < M) return true;
		return false;
	}

	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		while (T-- > 0) {
			List <List <Integer>> laby = Arrays.stream(new Integer[input.nextInt()][input.nextInt()])
													.map(i -> Arrays.stream(i)
																	.map(j -> input.nextInt())
																	.collect(Collectors.toList()))
													.collect(Collectors.toList());
			go(laby);
		}
	}
}
