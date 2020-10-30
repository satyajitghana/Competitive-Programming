import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastReader in = new FastReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        BNiceMatrix solver = new BNiceMatrix();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }
    
    static class BNiceMatrix {
        public void solve(int testNumber, FastReader r, OutputWriter out) {
            int n = r.nextInt(), m = r.nextInt();
            int[][] mat = r.nextIntMatrix(n, m);
            long ans = 0;
            int n_iter = (n & 1) != 0 ? n / 2 : n / 2 - 1;
            int m_iter = (m & 1) != 0 ? m / 2 : m / 2 - 1;
            for (int i = 0; i <= n_iter; i++) {
                for (int j = 0; j <= m_iter; j++) {
                    ArrayList<Integer> eles = new ArrayList<>();
                    eles.add(mat[i][j]);
                    if (j != m - j - 1) eles.add(mat[i][m - 1 - j]);
                    if (i != n - 1 - i) eles.add(mat[n - 1 - i][j]);
                    if (i != n - 1 - i && j != m - j - 1) eles.add(mat[n - 1 - i][m - 1 - j]);
                    Collections.sort(eles);
                    int median = eles.get((eles.size() - 1) / 2);
                    for (int k = 0; k < eles.size(); k++) ans += Math.abs(median - eles.get(k));
                }
            }
            out.println(ans);
        }
        
    }
    
    static class OutputWriter {
        private final PrintWriter writer;
        
        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }
        
        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }
        
        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                writer.print(objects[i]);
                if (i != objects.length - 1) writer.print(" ");
            }
        }
        
        public void println(Object... objects) {
            print(objects);
            writer.println();
        }
        
        public void close() {
            writer.close();
        }
        
    }
    
    static class FastReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private FastReader.SpaceCharFilter filter;
        
        public FastReader(InputStream stream) {
            this.stream = stream;
        }
        
        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }
        
        public int nextInt() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }
        
        public String nextString() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }
        
        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }
        
        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
        
        public String next() {
            return nextString();
        }
        
        public int[] nextIntArray(int n) {
            int[] array = new int[n];
            for (int i = 0; i < n; ++i) array[i] = nextInt();
            return array;
        }
        
        public int[][] nextIntMatrix(int n, int m) {
            int[][] mat = new int[n][m];
            for (int i = 0; i < n; ++i) mat[i] = nextIntArray(m);
            return mat;
        }
        
        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);
            
        }
        
    }
}
