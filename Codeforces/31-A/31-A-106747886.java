import java.util.Scanner;

public class WormsEvolution {

    public static void main(String[] args) {
        Scanner s =new Scanner(System.in);
        int n=s.nextInt();
        int []arr=new int[n];
        int []find=new int[2002];
        for (int i = 0; i < n; i++) {
            int index=s.nextInt();
            arr[i]=index;
            find[index]=i;
        }
        String result ="-1";
        int stop=0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n&&stop==0; j++) {
                if(find[arr[i]+arr[j]]!=0){
                    result=(find[arr[i]+arr[j]]+1)+" "+(j+1)+" "+(i+1);
                    stop++;
                }else if(find[arr[i]+arr[j]]==0&&arr[i]+arr[j]==arr[0]){
                    result=(find[arr[i]+arr[j]]+1)+" "+(j+1)+" "+(i+1);
                    stop++;                }
            }
        }
        System.out.println(result);
    } 
}