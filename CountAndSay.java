package leetcode31_40;

/**
 * The count-and-say sequence is the sequence of integers beginning as follows:
 1, 11, 21, 1211, 111221, ...

 1 is read off as "one 1" or 11.
 11 is read off as "two 1s" or 21.
 21 is read off as "one 2, then one 1" or 1211.
 Given an integer n, generate the nth sequence.

 Note: The sequence of integers will be represented as a string.
 * Created by DCLab on 11/21/2015.
 */
public class CountAndSay {
    public static void main(String[] args) {
        System.out.println("*****RESULT*****");
        String s = new CountAndSay().countAndSay(5);
        System.out.println(s);
    }

    public String countAndSay(int n) {
        if (n < 1) return null;
        if (n == 1) return "1";
        return translate(countAndSay(n - 1));
    }
    private String translate(String s){
        char[] chars = s.toCharArray();
        StringBuilder builder = new StringBuilder();
        int count = 1;
        int i = 1;
        for ( ; i < chars.length; i++){
            if (chars[i - 1] != chars[i]){
                builder.append(count + String.valueOf(chars[i - 1]));
                count = 1;
            }
            else count++;
        }
        builder.append(count + String.valueOf(chars[i - 1]));
        return builder.toString();
    }
}
