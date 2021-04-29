
import java.util.*;
import java.io.*;

public class ConnectedComponents{
    static int[] visit ;
    static int result = 0;
    static ArrayList<Integer>[] adj ;
    static int c=0;
    public ConnectedComponents(int n) {
        adj = (ArrayList<Integer>[]) new ArrayList[n];
        visit = new int[n];
    }
    private static void reach(int x) {
        for (int i : adj[x]) {
            if (visit[i] == 0) {
                visit[i] = 1;
                reach(i);
            }           
        }
    }
    public static void main(String[] args) throws IOException {
        FastScanner scanner = new FastScanner();
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        ConnectedComponents r=new ConnectedComponents(n);
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
        for (int i = 0; i < visit.length; i++) {
           if(visit[i]==0) {
               visit[i]=1;
               reach(i);
               c++;
           }
        }
        System.out.println(c);
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
