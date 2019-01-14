import java.util.*;

public class DIFFNEIGH {
    public static void main(String [] args) {
        int [][]A = new int[50][50];
        for (int i = 0 ; i < 50 ; i++) {
            for (int j = i ; j < 50 ; j++) {
                if (i%2 == 0) {
                    if ((j-i)%4 == 0 || (j-i)%4 == 1) {
                        A[i][j] = 1;
                    } else {
                        A[i][j] = 2;
                    }
                } else {
                    if ((j-i)%4 == 0 || (j-i)%4 == 1) {
                        A[i][j] = 3;
                    } else {
                        A[i][j] = 4;
                    }
                }
            }
        }

        for (int j = 0 ; j < 50 ; j++) {
            for (int i = j+1 ; i < 50 ; i++) {
                if (j%2 == 0) {
                    if ((i-j-1)%4 == 0 || (i-j-1)%4 == 1) {
                        A[i][j] = 2;
                    } else {
                        A[i][j] = 1;
                    }
                } else {
                    if ((i-j-1)%4 == 0 || (i-j-1)%4 == 1) {
                        A[i][j] = 4;
                    } else {
                        A[i][j] = 3;
                    }
                }
            }
        }

        Scanner input = new Scanner(System.in);
        int T = input.nextInt();
        while (T-- > 0) {
            int N = input.nextInt();
            int M = input.nextInt();
            if      (N==1 && M==1) System.out.println(1+"\n"+1);
            else if (N==1 && M==2) System.out.println(1+"\n"+"1 1");
            else if (N==1 && M==3) System.out.println(2+"\n"+"1 1 2");
            else if (N==2 && M==1) System.out.println(1+"\n"+"1\n1");
            else if (N==2 && M==2) System.out.println(2+"\n"+"1 1\n2 2");
            else if (N==2 && M==3) System.out.println(3+"\n"+"1 1 2\n2 3 3");
            else if (N==3 && M==2) System.out.println(3+"\n"+"1 2\n1 3\n2 3");
            else if (N==1 && M>3) {
                System.out.println(2);
                for(int i = 0 ; i < M; i++)
                    System.out.print(A[0][i]+" ");
                System.out.println();
            }
            else if (N>=3 && M==1) {
                System.out.println(2);
                for(int i = 0 ; i < N; i++)
                    System.out.println(A[0][i]);
            }
            else if (N==2 && M>3) {
                System.out.println(3);
                int [][]B = new int[N][M];
                for (int i = 0 ; i < N ; i++) {
                    for (int j = 0 ; j < M ; j++) {
                        if (i%2 == 0) {
                            if (j%6==0 || j%6==1)
                                B[i][j]=1;
                            else if (j%6==2 || j%6==3)
                                B[i][j]=2;
                            else
                                B[i][j]=3;
                        } else {
                            if (j%6==0 || j%6==5)
                                B[i][j]=2;
                            else if (j%6==1 || j%6==2)
                                B[i][j]=3;
                            else
                                B[i][j]=1;
                        }
                    }
                }

                for (int i = 0 ; i < N ; i++) {
                    for (int j = 0 ; j < M ; j++) {
                        System.out.print(B[i][j]+" ");
                    }
                    System.out.println();
                }
            }
            else if (N>3 && M==2) {
                System.out.println(3);
                int [][]B = new int[N][M];
                for (int j = 0 ; j < M ; j++) {
                    for (int i = 0 ; i < N ; i++) {
                        if (j%2 == 0) {
                            if (i%6==0 || i%6==1)
                                B[i][j]=1;
                            else if (i%6==2 || i%6==3)
                                B[i][j]=2;
                            else
                                B[i][j]=3;
                        } else {
                            if (i%6==0 || i%6==5)
                                B[i][j]=2;
                            else if (i%6==1 || i%6==2)
                                B[i][j]=3;
                            else
                                B[i][j]=1;
                        }
                    }
                }
                
                for (int i = 0 ; i < N ; i++) {
                    for (int j = 0 ; j < M ; j++) {
                        System.out.print(B[i][j]+" ");
                    }
                    System.out.println();
                }
            }
            else {
                System.out.println(4);
                for (int i = 0 ; i < N ; i++) {
                    for (int j = 0 ; j < M ; j++) {
                        System.out.print(A[i][j]+" ");
                    }
                    System.out.println();
                }
            }
        }
    }
}