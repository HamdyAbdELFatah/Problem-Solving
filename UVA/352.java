import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;


public class Main{
    static HashMap<String, Integer> visit;
    static HashMap<String, ArrayList<String>> adj;
    static int c = 0;

    static String hash(int i, int j) {
        return i + "," + j;
    }

    private static void reach(String x) {
        for (String i : adj.get(x)) {
            if (visit.get(i) == 0) {
                visit.put(i, 1);
                reach(i);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        int num = 1;
        while (scanner.hasNextLine()) {
            int n = scanner.nextInt(); 
            String[] arr = new String[n];
            scanner.nextLine();
            for (int i = 0; i < n; i++) {
                arr[i] = scanner.nextLine();
            }
            visit = new HashMap<>();
            adj = new HashMap<>();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < arr[0].length(); j++) {
                    int f = 0;
                    if (arr[i].charAt(j) == '0') {
                        continue;
                    }
                    String key = i + "," + j;

                    if (!adj.containsKey(key)) {
                        adj.put(key, new ArrayList<>());
                    }
                    visit.put(key, 0);
                    if (j > 0) {
                        if (arr[i].charAt(j - 1) == '1') {
                            adj.get(key).add(hash(i, j - 1));
                            f++;
                        }
                        if (i > 0 && arr[i - 1].charAt(j - 1) == '1') {
                            adj.get(key).add(hash(i - 1, j - 1));
                            f++;
                        }
                        if (i < n - 1 && arr[i + 1].charAt(j - 1) == '1') {
                            adj.get(key).add(hash(i + 1, j - 1));
                            f++;
                        }
                    }
                    if (j < arr[0].length() - 1) {
                        if (arr[i].charAt(j + 1) == '1') {
                            adj.get(key).add(hash(i, j + 1));
                            f++;
                        }
                        if (i > 0 && arr[i - 1].charAt(j + 1) == '1') {
                            adj.get(key).add(hash(i - 1, j + 1));
                            f++;
                        }
                        if (i < n - 1 && arr[i + 1].charAt(j + 1) == '1') {
                            adj.get(key).add(hash(i + 1, j + 1));
                            f++;
                        }
                    }
                    if (i > 0 && arr[i - 1].charAt(j) == '1') {
                        adj.get(key).add(hash(i - 1, j));
                        f++;
                    }
                    if (i < n - 1 && arr[i + 1].charAt(j) == '1') {
                        adj.get(key).add(hash(i + 1, j));
                        f++;
                    }
                    if (f == 0) {
                        c++;
                    }
                }
            }

            for (String k : adj.keySet()) {
                if (visit.get(k) == 0 && adj.get(k).size() > 0) {
                    visit.put(k, 1);
                    reach(k);
                    //System.out.println(i);

                    c++;
                }
            }
            System.out.println("Image number " + num + " contains " + c + " war eagles.");
            num++;
            c = 0;
        }
    }

}
