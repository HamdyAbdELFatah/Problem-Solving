import java.util.*;

public class Main {

    public static void main(String[] args) {
      Scanner in=new Scanner(System.in);
      long l=in.nextLong(),r=in.nextLong();
      if(l%2!=0)
          l++;
      if(Math.abs(l-r)<2)
            System.out.println("-1");
      else 
            System.out.println(l+" "+(l+1)+" "+(l+2));
    }
}