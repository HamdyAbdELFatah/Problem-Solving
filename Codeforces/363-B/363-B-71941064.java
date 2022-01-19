import java.util.Scanner;
public class JavaApplication1 {
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        int n=s.nextInt(),k=s.nextInt(),sum=0,c=0,min=Integer.MAX_VALUE,m=1;
        int x[]=new int[n];
        for (int i = 0; i < n; i++) {
            x[i]=s.nextInt();
            sum+=x[i];
            if(i>=k-1){
                if(sum<min){
                    m=i-k+2;
                    min=sum;
                }
                sum-=x[c];
                c++;
            }
        }
        System.out.println(m);
    }
}