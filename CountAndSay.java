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

    public String countAndSay(int n) {
        String s = "1";
        for(int i=1; i<n; i++) s = build(s);    //注意i<n而不是i<=n
        return s;
    }
    private String build(String s){
        StringBuilder sb = new StringBuilder();
        char preC = s.charAt(0);
        int count = 1;
        for(int i = 1; i < s.length(); i++){
            if(s.charAt(i)==preC) count++;
            else {
                sb.append(count).append(preC);
                preC = s.charAt(i);
                count = 1;
            }
        }
        sb.append(count).append(preC);
        return sb.toString();
    }
}
