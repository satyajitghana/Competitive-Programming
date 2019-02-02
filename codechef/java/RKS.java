import java.util.*;

public class RKS {
    public static void main(String [] args) {
        Scanner input = new Scanner(System.in);
        int T = input.nextInt();
        while (T-- > 0) {
        int N = input.nextInt();
        int K = input.nextInt();
        
        int ROW[] = new int[N+1];
        int COL[] = new int[N+1];
        int ROW_SOL[] = new int[N+1];
        int COL_SOL[] = new int[N+1];

		for (int i = 0 ; i < K ; i++) {
            ROW[input.nextInt()] = 1;
            COL[input.nextInt()] = 1;
        }
        
        int i = 0;
        int j = 0;
        int k = 0;
		for(i = 1 ; i <= N ; i++) {
            if (ROW[i] == 0) {
                COL_SOL[j++] = i;
            }
            if (COL[i] == 0) {
                ROW_SOL[k++] = i;
            }
		}
        System.out.print(j+" ");
		for(i = 0 ; i < j ; i++) {
            System.out.print(COL_SOL[i]+" "+ROW_SOL[i]+" ");
        }
        System.out.println();
        }
    }
}