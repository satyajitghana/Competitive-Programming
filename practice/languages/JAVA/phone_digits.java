public class phone_digits {
	public static void digits(int n[], String [] key,String res, int i) {
		if (i==n.length-1) {
		System.out.print(res);
		return ;
		}
		for (int j = 0 ; j < key[n[j]].length() ; j++) {
			res += key[n[j]];
			digits(n,key,res,i+1);
			if (n[j]==0 | n[j]==1) return;
		}

	}

	public static void main(String [] args) {
	String []key = new String[9];
	key[0] ="";
	key[1] ="ABC";
	key[2] ="DEF";
	key[3] ="GHI";
	key[4] ="JKL";
	key[5] ="MNO";
	key[6] ="PQRS";
	key[7] ="TUV";
	key[8] ="WXYZ";
	//String []key = new String[]{"","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"}
	if (args.length == 1) {
		int number  = Integer.parseInt(args[0]);
		int []input = new int[args[0].length()];
		int i=0;
		while(number > 0) {
		input[input.length-i-1] = number%10; number = number/10;
		//System.out.println(input[input.length-i-1]);
		digits(input,key,"",0);
		}
	}
	else System.out.println("USAGE : java phone_digits <number between 0 and 9>");
	}
}
