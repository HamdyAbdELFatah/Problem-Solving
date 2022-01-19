import static java.lang.Math.abs;
import static java.lang.Math.ceil;
import static java.lang.Math.pow;
import static java.lang.Math.sqrt;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
import javafx.util.Pair;

public class JavaApplication2 {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt(), m = s.nextInt(), x = s.nextInt(), q, sum = 0, f = 0;
        HashMap<Character, ArrayList< Pair<Integer, Integer>>> map = new HashMap<>();
        HashMap<Character, Integer> result = new HashMap<>();

        for (int i = 0; i < n; i++) {

            String keyboard = s.next();
            for (int j = 0; j < m; j++) {
                char c = keyboard.charAt(j);
                ArrayList< Pair<Integer, Integer>> arr = map.get(c);
                if (arr == null) {
                    arr = new ArrayList<>();
                }
                arr.add(new Pair(i, j));
                map.put(c, arr);
            }
        }
        for (char i = 'a'; i <= 'z'; i++) {
            int temp = 0;
            ArrayList< Pair<Integer, Integer>> arr = map.get(i);
            ArrayList< Pair<Integer, Integer>> shift = map.get('S');
            if (shift != null && arr != null) {
                int min = Integer.MAX_VALUE;
                for (int j = 0; j < arr.size(); j++) {
                    for (int k = 0; k < shift.size(); k++) {
                        int x1 = arr.get(j).getKey();
                        int y1 = arr.get(j).getValue();
                        int x2 = shift.get(k).getKey();
                        int y2 = shift.get(k).getValue();
                        min = Math.min(min, (int) ceil(sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))));
                    }
                }
                if (min > x) {
                    temp++;
                }
                result.put(i, temp);
            }
        }
        q = s.nextInt();
        String qq = s.next();
        for (int i = 0; i < q; i++) {
            char c = qq.charAt(i);
            if ((map.get(c) == null && c == Character.toLowerCase(c)) || (c == Character.toUpperCase(c) && map.get(Character.toLowerCase(c)) == null) || (c == Character.toUpperCase(c) && map.get('S') == null)) {
                f = 1;
                break;
            } else if (c == Character.toUpperCase(c)) {
                if (result.get(Character.toLowerCase(c)) != null) {
                    sum += result.get(Character.toLowerCase(c));
                }

            }
        }
        if (f == 1) {
            System.out.println(-1);
        } else {
            System.out.println(sum);
        }
    }
}