/*
 * Date Created : 1/10/2020
 * Have A Good Day !
 */

import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Arpit
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastReader in = new FastReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        Task solver = new Task();
        solver.solve(1, in, out);
        out.close();
    }
    
    static class Task {
        public void solve(int testNumber, FastReader r, OutputWriter out) {
            
            int n = r.nextInt();
            
            int[] x_ans = new int[(int) 1e6 + 2];
            int[] y_ans = new int[(int) 1e6 + 2];
            
            for (int i = 1; i <= n; i++) {
                int x1 = r.nextInt(), y1 = r.nextInt();
                int x2 = r.nextInt(), y2 = r.nextInt();
                int x3 = r.nextInt(), y3 = r.nextInt();
                int x_min = Math.min(x1, Math.min(x2, x3)), x_max = Math.max(x1, Math.max(x2, x3));
                int y_min = Math.min(y1, Math.min(y2, y3)), y_max = Math.max(y1, Math.max(y2, y3));
                x_ans[x_min + 1]++; x_ans[x_max]--;
                y_ans[y_min + 1]++; y_ans[y_max]--;
            }
            
            for (int i = 1; i <= 1000000; i++) {
                x_ans[i] += x_ans[i - 1];
                y_ans[i] += y_ans[i - 1];
            }
            
            int m = r.nextInt();
            
            for (int i = 1; i <= m; i++) {
                char axes = r.nextCharacter();
                char eq = r.nextCharacter();
                int c = r.nextInt();
//            out.debug("axes", axes); out.debugln("c", c);
                if (axes == 'x') out.println(x_ans[c]);
                else out.println(y_ans[c]);
            }
            
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
        
        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }
        
        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
        
        public char nextCharacter() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            return (char) c;
        }
        
        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);
            
        }
        
    }
}
