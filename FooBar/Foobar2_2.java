import java.util.HashMap;
import java.util.Map;
import java.util.Arrays;

public class Foobar2_2 {
    public static char[] subtract(char[] t2, char[] t1, int b) {
        char diff[] = new char[t1.length];
        for(int i = t1.length - 1; i > -1; i--) {
            if(t2[i] < '0') {
                t2[i] = (char)('0' + b - 1);
                t2[i - 1]--;
            }
            int temp = t2[i] - t1[i];
            if(temp >= 0)
                diff[i] = (char) ('0' + temp);
            else {
                diff[i] = (char) ('0' + b + temp);
                t2[i - 1]--; 
            }
        }
        return diff;
    }
    public static int solution(String n, int b) {
        //Your code here
        int k = 0;
        HashMap<String, Integer> map = new HashMap<String, Integer>();
        while(!map.containsKey(n)) {
            map.put(n, k++);
            char t1[] = n.toCharArray();
            Arrays.sort(t1);
            char t2[] = new char[t1.length];
            for(int i = 0; i < t1.length; i++)
                t2[i] = t1[t1.length - i - 1];
            char diff[] = Foobar2_2.subtract(t2, t1, b);
            n = new String(diff);
        }
        System.out.println("ANS : " + k + " " + map.get(n));
        return k - map.get(n);
    }
    public static void main(String[] args) {
        String s = "1211";
        Foobar2_2.solution(s, 10);
    }
}