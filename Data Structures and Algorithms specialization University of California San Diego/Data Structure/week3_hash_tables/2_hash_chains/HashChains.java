
import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.StringTokenizer;

public class HashChains {

    private FastScanner in;
    private PrintWriter out;
    // store all strings in one list
    private HashMap<Integer, ArrayList<String>> elemsMap;
    private HashMap<String, String> checkMap;
    // for hash function
    private int bucketCount;
    private int prime = 1000000007;
    private int multiplier = 263;

    public static void main(String[] args) throws IOException {
        new HashChains().processQueries();
    }

    private int hashFunc(String s) {
        long hash = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            hash = (hash * multiplier + s.charAt(i)) % prime;
        }
        return (int) hash % bucketCount;
    }
    private void processQuery(String query, String x) {
        switch (query) {
            case "add":
                int index=hashFunc(x);
                if (elemsMap.containsKey(index)) {
                    ArrayList<String> temp = elemsMap.get(index);   
                    if(!checkMap.containsKey(x)){
                        temp.add(x);
                        elemsMap.put(index, temp);
                        checkMap.put(x, "yes");
                    }
                } else {
                    ArrayList<String> temp = new ArrayList<>();
                    temp.add(x);
                    elemsMap.put(index, temp);
                    checkMap.put(x, "yes");
                }
                break;
            case "del":
                if (checkMap.containsKey(x)) {
                    ArrayList<String> temp = elemsMap.get(hashFunc(x));
                    temp.remove(x);
                    elemsMap.put(hashFunc(x), temp);
                    checkMap.remove(x);
                }
                break;
            case "find":
                System.out.println(checkMap.containsKey(x) ? "yes" : "no");
                break;
            case "check":
                ArrayList<String> arr = elemsMap.get(Integer.parseInt(x));
                //System.out.println(arr+"  "+ elemsMap+" "+x);
                if(arr!=null&&!arr.isEmpty()){
                    for (int i = arr.size()-1; i >= 0; i--) {                                   
                            System.out.print(arr.get(i)+" ");
                    }
                    System.out.println("");
                }else{
                    System.out.println("");
                }                    
                break;
        }
    }

    public void processQueries() throws IOException {
        elemsMap = new HashMap<>();
        checkMap = new HashMap<>();
        in = new FastScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        bucketCount = in.nextInt();
        int queryCount = in.nextInt();
        for (int i = 0; i < queryCount; ++i) {
            processQuery(in.next(), in.next());
        }

        out.close();
    }

    static class FastScanner {

        private BufferedReader reader;
        private StringTokenizer tokenizer;

        public FastScanner() {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
        }

        public String next() throws IOException {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(reader.readLine());
            }
            return tokenizer.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
    }
}
