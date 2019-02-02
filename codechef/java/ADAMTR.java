import java.io.DataInputStream; 
import java.io.FileInputStream; 
import java.io.IOException; 
import java.io.InputStreamReader; 
import java.util.Scanner; 
import java.util.StringTokenizer; 

public class ADAMTR {
    static class Reader 
    { 
        final private int BUFFER_SIZE = 1 << 16; 
        private DataInputStream din; 
        private byte[] buffer; 
        private int bufferPointer, bytesRead; 
  
        public Reader() 
        { 
            din = new DataInputStream(System.in); 
            buffer = new byte[BUFFER_SIZE]; 
            bufferPointer = bytesRead = 0; 
        } 
  
        public Reader(String file_name) throws IOException 
        { 
            din = new DataInputStream(new FileInputStream(file_name)); 
            buffer = new byte[BUFFER_SIZE]; 
            bufferPointer = bytesRead = 0; 
        } 
  
        public String readLine() throws IOException 
        { 
            byte[] buf = new byte[64]; // line length 
            int cnt = 0, c; 
            while ((c = read()) != -1) 
            { 
                if (c == '\n') 
                    break; 
                buf[cnt++] = (byte) c; 
            } 
            return new String(buf, 0, cnt); 
        } 
  
        public int nextInt() throws IOException 
        { 
            int ret = 0; 
            byte c = read(); 
            while (c <= ' ') 
                c = read(); 
            boolean neg = (c == '-'); 
            if (neg) 
                c = read(); 
            do
            { 
                ret = ret * 10 + c - '0'; 
            }  while ((c = read()) >= '0' && c <= '9'); 
  
            if (neg) 
                return -ret; 
            return ret; 
        } 
  
        public long nextLong() throws IOException 
        { 
            long ret = 0; 
            byte c = read(); 
            while (c <= ' ') 
                c = read(); 
            boolean neg = (c == '-'); 
            if (neg) 
                c = read(); 
            do { 
                ret = ret * 10 + c - '0'; 
            } 
            while ((c = read()) >= '0' && c <= '9'); 
            if (neg) 
                return -ret; 
            return ret; 
        } 
  
        public double nextDouble() throws IOException 
        { 
            double ret = 0, div = 1; 
            byte c = read(); 
            while (c <= ' ') 
                c = read(); 
            boolean neg = (c == '-'); 
            if (neg) 
                c = read(); 
  
            do { 
                ret = ret * 10 + c - '0'; 
            } 
            while ((c = read()) >= '0' && c <= '9'); 
  
            if (c == '.') 
            { 
                while ((c = read()) >= '0' && c <= '9') 
                { 
                    ret += (c - '0') / (div *= 10); 
                } 
            } 
  
            if (neg) 
                return -ret; 
            return ret; 
        } 
  
        private void fillBuffer() throws IOException 
        { 
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE); 
            if (bytesRead == -1) 
                buffer[0] = -1; 
        } 
  
        private byte read() throws IOException 
        { 
            if (bufferPointer == bytesRead) 
                fillBuffer(); 
            return buffer[bufferPointer++]; 
        } 
  
        public void close() throws IOException 
        { 
            if (din == null) 
                return; 
            din.close(); 
        } 
    } 
  
    public static void main(String [] args) throws IOException {
        //Scanner input = new Scanner(System.in);
        Reader input = new Reader();

        int T = input.nextInt();
        int N = input.nextInt();
        Long [][]A = new Long[N][N];
        Long [][]B = new Long[N][N];
        for (int i = 0 ; i < N ; i++) {
            for (int j = 0 ; j < N ; j++) {
                A[i][j] = input.nextLong();
            }
        }
        for (int i = 0 ; i < N ; i++) {
            for (int j = 0 ; j < N ; j++) {
                B[i][j] = input.nextLong();
            }
        }
        boolean flag = false;
        here:
        for (int i = 1 ; i < N ; i++) {
            for (int j = i+1 ; j < N ; j++) {
                Long sum1 = A[i][j]+A[j][i];
                Long sum2 = B[i][j]+B[j][i];
                if (A[i][j] != B[j][i] && A[i][j] != B[i][j]) {
                    flag = true;
                    break;
                }
                if (A[j][i] != B[j][i] && A[i][j] != B[i][j]) {
                    flag = true;
                    break;
                }
                if (sum1 != sum2) {
                    flag = true;
                    break here;
                }
            }
        }
        here1:
        for (int i = 0 ; i < N ; i++) {
                if (A[i][i] != B[i][i]) {
                    flag = true;
                    break here1;
                }
        }

        if (flag == true) {
            System.out.println("No");
        } else {
            System.out.println("Yes");
        }
    }
}