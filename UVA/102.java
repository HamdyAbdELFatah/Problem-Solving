import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.TreeMap;
public class WormsEvolution {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner s =new Scanner(new File("C:\\Users\\hamdy\\OneDrive\\Desktop\\test.txt"));
        //Scanner s =new Scanner(System.in);
        while(s.hasNextLine()){
            int []bin1=new int[3];
            int []bin2=new int[3];
            int []bin3=new int[3];
            String [] temp=s.nextLine().split(" ");
            for (int i = 0; i < 3; i++) {
                bin1[i]=Integer.parseInt(temp[i]);  //1 2 3
                bin2[i]=Integer.parseInt(temp[i+3]);//4 5 6
                bin3[i]=Integer.parseInt(temp[i+6]);//7 8 9
            }
            //B=0 G=1 C=2
            int m1=bin1[1]+bin1[2]+bin2[0]+bin2[2]+bin3[0]+bin3[1];//BGC  
            int m2=bin1[1]+bin1[2]+bin2[0]+bin2[1]+bin3[0]+bin3[2];//BCG
            int m3=bin1[0]+bin1[1]+bin2[1]+bin2[2]+bin3[0]+bin3[2];//CBG
            int m4=bin1[0]+bin1[1]+bin2[0]+bin2[2]+bin3[1]+bin3[2];//CGB
            int m5=bin1[0]+bin1[2]+bin2[1]+bin2[2]+bin3[0]+bin3[1];//GBC
            int m6=bin1[0]+bin1[2]+bin2[0]+bin2[1]+bin3[1]+bin3[2];//GCB 
            TreeMap<Integer,String> map=new TreeMap<>();
            //then the alphabetically first    
            map.put(m6,"GCB");
            map.put(m5,"GBC");
            map.put(m4,"CGB");
            map.put(m3,"CBG");
            map.put(m1,"BGC");
            map.put(m2,"BCG");
            String result =map.get(map.firstKey())+" "+map.firstKey();
            System.out.println(result);
        }       
    }
}
