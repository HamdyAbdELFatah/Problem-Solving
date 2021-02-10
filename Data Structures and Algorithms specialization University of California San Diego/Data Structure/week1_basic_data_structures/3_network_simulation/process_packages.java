import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;
class process_packages {
    int arrival,processing,out,index;

    public process_packages(int arrival, int processing, int out, int index) {
        this.arrival = arrival;
        this.processing = processing;
        this.out = out;
        this.index = index;
    }
    static class FastScanner {
            StringTokenizer tok = new StringTokenizer("");
            BufferedReader in;

            FastScanner() {
                    in = new BufferedReader(new InputStreamReader(System.in));
            }

            String next() throws IOException {
                    while (!tok.hasMoreElements())
                            tok = new StringTokenizer(in.readLine());
                    return tok.nextToken();
            }
            int nextInt() throws IOException {
                    return Integer.parseInt(next());
            }
    }
    public static void main(String[] args) throws IOException {
        FastScanner scan = new FastScanner();
        Queue<process_packages> q=new LinkedList<>();
        int out=0,time=0,size=0,a,p,s = scan.nextInt(),n = scan.nextInt();
        int[]arr=new int[n];
        for (int i = 0; i < n; i++) {
            a = scan.nextInt();
            p = scan.nextInt();
            if(i==0){
                time=a;
                out=a;
            }                     
            if(size<s){
                out+=p;                
                q.add(new process_packages(Math.max(time,a), p,out,i));
                //System.out.println("here  "+q.remove().arrival);
                arr[i]=Math.max(time,a);
                time+=p;
                size++;
            }else{
                //System.out.println("a  =  "+a+"  first  "+q.peek().out);
                if(a>=q.peek().out){
                    arr[i]=0;
                    out+=p;
                    q.add(new process_packages(Math.max(time,a), p,out,i));
                   // System.out.println("a  = "+a +" time "+time);
                    arr[i]=Math.max(time,a);
                    q.remove();
                    time+=p;

                }else{
                    //q.add(new process_packages(-1, p,out));
                    arr[i]=-1;

                }
            }
        }
        for (int i = 0; i < n; i++) {
            if(q.size()>0){
                if(i==q.peek().index)
                    System.out.println(q.remove().arrival);
                else
                    System.out.println(arr[i]);
            }else
                System.out.println(arr[i]);
        }

    } 
}
