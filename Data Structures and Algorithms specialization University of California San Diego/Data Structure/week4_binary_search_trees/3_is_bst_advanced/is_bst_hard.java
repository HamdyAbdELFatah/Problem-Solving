import java.util.*;
import java.io.*;

public class is_bst_hard {

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

    static public class TreeIsBST {

        Node root;
        Node temp;

        void checkIsBST() {
            System.out.println((isBST(root)) ? "CORRECT" : "INCORRECT");
        }

        Boolean isBST(Node node) {
            if (node != null) {
                if (!isBST(node.left)) {
                    return false;
                }
                if (temp != null && node.key < temp.key) {
                    return false;
                } else if (node.left != null && node.key == temp.key && node.left.key == temp.key) {
                    return false;
                }
                temp = node;
                return isBST(node.right);
            }
            return true;
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
            if (n > 0) {
                TreeIsBST tree = new TreeIsBST();
                tree.root = nodes[0];
                for (int i = 0; i < n; i++) {
                    if (nodes[i].leftIndex != -1) {
                        nodes[i].left = nodes[nodes[i].leftIndex];
                    }
                    if (nodes[i].rightIndex != -1) {
                        nodes[i].right = nodes[nodes[i].rightIndex];
                    }
                }
                tree.checkIsBST();
            } else {
                System.out.println("CORRECT");
            }

        }
    }

    static public void main(String[] args) throws IOException {
        new Thread(null, () -> {
            try {
                new is_bst_hard().run();
            } catch (IOException e) {
            }
        }, "1", 1 << 26).start();

    }

    public void run() throws IOException {
        TreeIsBST tree = new TreeIsBST();
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
