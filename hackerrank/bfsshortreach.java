import java.util.*;
import java.util.stream.*;

public class bfsshortreach {
	public static List <Integer> BFS(ArrayList< ArrayList <Integer>> graph, int source) {
		List <Boolean> visited = Arrays.stream(new Boolean[graph.size()])
									.map(e -> false)
									.collect(Collectors.toList());
		List <Integer> distance = Arrays.stream(new Integer[graph.size()])
									.map(e -> -1)
									.collect(Collectors.toList());
		Queue <Integer> queue = new LinkedList <Integer>();
		// add the source to the queue, set the distace from the source as zero,
		// set the visited node to true.
		queue.add(source);
		distance.set(source, 0);
		visited.set(source, true);
		while(!queue.isEmpty()) {
			// remove the head of the queue
			source = queue.poll();
			// go through the nodes attached to the source node
			// if the node connected is not visited and the distance is not calculated
			// then add the node to the queue
			for (int i : graph.get(source)) {
				if ( !visited.get(i) && distance.get(i) == -1) {
					//set the node to visited
					visited.set(i, true);
				//add 1 from the source to this node, since this node is directly to the source
					distance.set(i, distance.get(source) + 1);
					//now start to distance nodes from each of the 'i' nodes
					queue.add(i);
				}
			}
		}
	return distance;
	}
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		int Q = input.nextInt();
		while (Q-- > 0) {
			int nodes = input.nextInt();
			int edges = input.nextInt();
		ArrayList < ArrayList <Integer>> graph = new ArrayList < ArrayList <Integer>>(nodes+1);
			for (int i = 0 ; i < edges + 1 ; i++) {
				graph.add(new ArrayList <Integer>());
			}
			for (int i = 0 ; i < edges ; i++) {
				int x = input.nextInt();
				int y = input.nextInt();
				graph.get(x-1).add(y-1);
				graph.get(y-1).add(x-1);
			}
			int search = input.nextInt();
			List <Integer> distance = BFS(graph, search - 1);
			for (int i : distance) {
				if (i==-1) System.out.print(" ");
				else System.out.print((i*6) + " ");
			}
			System.out.println();
		}
	}
}
