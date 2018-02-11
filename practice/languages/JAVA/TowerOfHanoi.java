public class TowerOfHanoi{
	public static void tower(int number , String Source , String Temp , String Dest) {
		if (number == 1) {System.out.println("Moving Disk "+number+" from "+Source+" to "+Dest); return; }
		else {tower(number-1,Source,Dest,Temp);
		System.out.println("Moving Disk "+number+" from "+Source+" to "+Dest);
		tower(number-1,Temp,Source,Dest);}

	}
	public static void main(String [] args) {
	if (args.length == 1) {
		int size = Integer.parseInt(args[0]);

		tower(size,"Source","Temp","Dest");
	}
	else System.out.println("USAGE : TowerOfHanoi <any natural number>");
	}
}
