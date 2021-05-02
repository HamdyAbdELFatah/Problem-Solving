//============================================================================
// Author      : Hamdy Abd El Fattah $
// Code is like humor. When you have to explain it, it’s bad.
//============================================================================
import java.util.*;
import java.io.*;

public class Dijkstra {

    public static void main(String[] args) throws IOException {
        FastScanner scanner = new FastScanner();
        int n, m, u, v, w;
        int INF = 0x3f3f3f3f;
        n = scanner.nextInt();
        m = scanner.nextInt();
        ArrayList<Integer> dist=new ArrayList<>();
        ArrayList<Node>[] arr = (ArrayList<Node>[])new ArrayList[n+1];
        for (int i = 0; i < n+1; i++) {
            dist.add(INF);
            arr[i]= new ArrayList<Node>();
        }  
	for (int i = 0; i < m; i++) {
            u = scanner.nextInt();
            v = scanner.nextInt();
            w = scanner.nextInt();
            arr[u].add(new Node(v,w));
        }
        u = scanner.nextInt();
        v = scanner.nextInt();
        PriorityQueue<Node> q=new PriorityQueue<>(n+1,new Node());
        q.add(new Node(0,u));
        dist.set(u, 0);
        while (!q.isEmpty()) {
            u = q.remove().getValue();
            for (int i = 0; i < arr[u].size(); i++) {
                
                if (dist.get(arr[u].get(i).getKey()) > dist.get(u) + arr[u].get(i).getValue()) {
                    dist.set(arr[u].get(i).getKey(), dist.get(u) + arr[u].get(i).getValue());
                    q.add(new Node(dist.get(arr[u].get(i).getKey()),arr[u].get(i).getKey()));

                }
            }
        }
        if (dist.get(v) != INF) {
            System.out.println(dist.get(v));
        } else {
            System.out.println("-1");
        }
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
   static class Node implements Comparator<Node> {

        public int getKey() {
            return node;
        }

        public int getValue() {
            return cost;
        }
    public int node;
    public int cost;
  
    public Node()
    {
    }
  
    public Node(int node, int cost)
    {
        this.node = node;
        this.cost = cost;
    }
  
    @Override
    public int compare(Node node1, Node node2)
    {
        if (node1.cost < node2.cost)
            return -1;
        if (node1.cost > node2.cost)
            return 1;
        return 0;
    }
    }
}
