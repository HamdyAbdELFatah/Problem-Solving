import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class BuildHeap {
    private int[] arr;
    private FastScanner in;
    private PrintWriter out;
    int size=0;
    String result="";
    ArrayList<Integer> index=new ArrayList<>();
    ArrayList<Integer> valueMin=new ArrayList<>();
    public static void main(String[] args) throws IOException {
        new BuildHeap().solve();      
    }
    private void readData() throws IOException {
        int n = in.nextInt();
        arr = new int[n];
        for (int i = 0; i < n; ++i) {
          arr[i] = in.nextInt();
        }
    }
    void heapify(int i){
        int min=i; //2
        int l=2*i+1;//5
        int r=2*i+2;//6
        if(l<arr.length && arr[l]<arr[min])
            min=l;
        if(r<arr.length && arr[r]<arr[min])
            min=r;
        if(min!=i){
            int temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
            //result+=i+"  "+min+"\n";
            index.add(i);
            valueMin.add(min);
            size++;
            heapify(min);
        }
    }
    void buildHeap(){
        
        for (int i = arr.length/2-1; i >=0; i--) {                
            heapify(i); 
        } 
    }


    public void solve() throws IOException {
        in = new FastScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        readData();
        buildHeap();
        System.out.println(size);
        if(size>0){
            for (int i = 0; i < index.size(); i++) {
                System.out.println(index.get(i)+" "+valueMin.get(i));
            }
        }
//        for (int i = 0; i < arr.length; i++) {
//            System.out.print(arr[i]+" ");
//        }
//        System.out.println("");    
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
