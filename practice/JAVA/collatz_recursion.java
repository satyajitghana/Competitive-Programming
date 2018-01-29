public class collatz_recursion {

	public static int _collatz(int number) {
		int iterations;
		if (number==1) return 0;
		else if (number%2==0) iterations = 1+_collatz(number/2);
		else iterations = 1+_collatz(3*number+1);
		return iterations;
	}

	public static void main(String []  args) {
	if (args.length == 1) {
		System.out.println(_collatz(Integer.parseInt(args[0])));
		}
	else System.out.println("USAGE : collatz <any natural number>");
	}
}
