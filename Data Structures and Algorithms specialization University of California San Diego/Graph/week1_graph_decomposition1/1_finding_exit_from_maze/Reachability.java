
import java.util.*;
import java.io.*;

public class Reachability {

    static int[] visit = new int[1000];
    static int result = 0;
    static ArrayList<Integer>[] adj ;

    public Reachability(int n) {
        adj = (ArrayList<Integer>[]) new ArrayList[n];
    }

    private static int reach( int x, int y) {
        if (x == y) {
            result = 1;
        }
        for (int i : adj[x]) {
            if (visit[i] == 0) {
                visit[i] = 1;
                reach(i, y);
            } 
           
        }
        return result;
    }

    public static void main(String[] args) throws IOException {
        FastScanner scanner = new FastScanner();
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        Reachability r=new Reachability(n);
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<Integer>();
        }

        for (int i = 0; i < m; i++) {
            int x, y;
            x = scanner.nextInt();
            y = scanner.nextInt();
            adj[x - 1].add(y - 1);
            adj[y - 1].add(x - 1);
        }

        int x = scanner.nextInt() - 1;
        int y = scanner.nextInt() - 1;
        visit[x] = 1;
        System.out.println(reach( x, y));
    }

    static class FastScanner {

        StringTokenizer tok = new StringTokenizer("");
        BufferedReader in;

        FastScanner() {
            in = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() throws IOException {
            while (!tok.hasMoreElements()) {
                tok = new StringTokenizer(in.readLine());
            }
            return tok.nextToken();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
    }
}
