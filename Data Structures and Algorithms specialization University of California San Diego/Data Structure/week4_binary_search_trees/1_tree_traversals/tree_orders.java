
import java.util.*;
import java.io.*;

public class tree_orders {

    static public class Node {

        long key;
        int leftIndex;
        int rightIndex;
        Node left;
        Node right;

        public Node(long key) {
            this.key = key;
        }

    }

    static public class TreeOrders {
        Node root;
        
        void inOrder(Node node) {
            if (node == null) {
                return;
            }
            inOrder(node.left);
            System.out.print(node.key + " ");
            inOrder(node.right);

        }

        void preOrder(Node node) {
            if (node == null) {
                return;
            }

            System.out.print(node.key + " ");
            preOrder(node.left);
            preOrder(node.right);

        }

        void postOrder(Node node) {
            if (node == null) {
                return;
            }
            postOrder(node.left);
            postOrder(node.right);
            System.out.print(node.key + " ");
        }

        private void print() {
            inOrder(root);
            System.out.println("");
            preOrder(root);
            System.out.println("");
            postOrder(root);
        }

        private void read() throws IOException {
            FastScanner s = new FastScanner();
            int n = s.nextInt();
            Node[] nodes = new Node[n];
            for (int i = 0; i < n; i++) {
                Node node = new Node(s.nextInt());
                node.leftIndex = s.nextInt();
                node.rightIndex = s.nextInt();
                nodes[i] = node;
            }
            TreeOrders tree = new TreeOrders();
            tree.root = nodes[0];
            for (int i = 0; i < n; i++) {
                if (nodes[i].leftIndex != -1) {
                    nodes[i].left = nodes[nodes[i].leftIndex];
                }
                if (nodes[i].rightIndex != -1) {
                    nodes[i].right = nodes[nodes[i].rightIndex];
                }
            }
            tree.print();
        }
    }

    static public void main(String[] args) throws IOException {
        new Thread(null, () -> {
            try {
                new tree_orders().run();
            } catch (IOException e) {
            }
        }, "1", 1 << 26).start();

    }

    public void run() throws IOException {
        TreeOrders tree = new TreeOrders();
        tree.read();
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
