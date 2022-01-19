import java.util.Scanner;
public class JavaApplication1 {
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        String x=s.nextLine();
        String a=x.substring(0,x.indexOf('+'));
        String b=x.substring(x.indexOf('+')+1,x.indexOf('='));
        String c=x.substring(x.indexOf('=')+1);
        if(a.length()+b.length()-c.length()==0)
            System.out.println(a+"+"+b+"="+c);
        else if(a.length()+b.length()-c.length()==2&&a.length()>=b.length())
            System.out.println(a.substring(1)+"+"+b+"="+c+"|");
        else if(a.length()+b.length()-c.length()==2&&b.length()>=a.length())
            System.out.println(a+"+"+b.substring(1)+"="+c+"|");       
       else if(a.length()+b.length()-c.length()==-2)
            System.out.println(a+"|+"+b+"="+c.substring(0,c.length()-1));
        else
            System.out.println("Impossible");    
    }
}