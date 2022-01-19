import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import static java.lang.Math.pow;
import java.util.StringTokenizer;

public class TrickySum {

    public static void main(String[] args) throws IOException {
        FastScanner s = new FastScanner();
        int n=s.nextInt();
        //int [] power={1,2,4,8,16,32,64,128,256,512,1024,2048};
        for (int i = 0; i < n; i++) {
            long x=s.nextLong();
            long temp =(x*(x+1))/2;
            for(int j=0;true;j++){
                long power=(long)pow(2,j);
                if(power>x)
                    break;
                temp-=power*2;
            }
            System.out.println(temp);
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
        long nextLong() throws IOException {
            return Long.parseLong(next());
        }
    }
}