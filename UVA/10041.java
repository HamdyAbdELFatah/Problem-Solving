import java.io.FileNotFoundException;
import static java.lang.Math.abs;
import java.util.ArrayList;
import java.util.Scanner;
public class WormsEvolution {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner se =new Scanner(System.in);
        int n=se.nextInt();
        se.nextLine();
        while(se.hasNextLine()){
            ArrayList<Integer> arr=new ArrayList<>();
            String line = se.nextLine();
            Scanner s = new Scanner(line);
            int m=s.nextInt();
            for (int i = 0; i < m; i++) {
                arr.add(s.nextInt());
            }
            arr.sort(null);
            int devaition = 0 ; 
            int median = arr.get(arr.size()/2);
            for (int i = 0; i < arr.size(); ++i)
            {
                devaition += abs(median-arr.get(i));
            }
            System.out.println(devaition);
        }
    }
}
