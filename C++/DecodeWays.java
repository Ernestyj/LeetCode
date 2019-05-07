package leetcode91_100;

/**A message containing letters from A-Z is being encoded to numbers using the following mapping:
 'A' -> 1 'B' -> 2 ... 'Z' -> 26
 Given an encoded message containing digits, determine the total number of ways to decode it.
 For example,
 Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
 The number of ways decoding "12" is 2.
 * Created by DCLab on 1/12/2016.
 */
public class DecodeWays {

    /**https://leetcode.com/discuss/83547/java-clean-dp-solution-with-explanation
     * 动态规划（类似Climbing Stairs问题，注意题目的输入是合法的encode，无需考虑不合法编码）：
     * 对于当前位i(number数组头部额外分配一个)，考察前两位i-1, i-2：
       递推式number[i] = number[i-1] + number[i-2]，但有以下限制：TODO 注意限制条件的思维方式，如何做到简明不易错
       1. s[i-1]!=0，否则number[i]=number[i-2]；
       2. 在s[i-1]!=0基础上，s[i-2]!=0 && (1<=s[i-2,i-1]<=26)，否则number[i]=number[i-1]。
     */
    public int numDecodings(String s) {
        if(s == null || s.length() == 0) return 0;
        int n = s.length();
        int[] dp = new int[n+1];
        dp[0] = 1;  //dp[0] means an empty string will have one way to decode
        dp[1] = s.charAt(0)!='0'? 1 : 0;
        for(int i=2; i<=n; i++) {
            int first = Integer.valueOf(s.substring(i-1, i));
            int second = Integer.valueOf(s.substring(i-2, i));
            if(1<=first && first<=9) dp[i] += dp[i-1];
            if(10<=second && second<=26) dp[i] += dp[i-2];
        }
        return dp[n];
    }

    public int numDecodings1(String s) {
        if(s==null || s.length()==0 || s.charAt(0)=='0') return 0;
        int[] dp = new int[s.length()+1];   //额外分配一个
        dp[0] = dp[1] = 1;  //额外分配的number[0]存初始值，i从1开始
        for (int i=2; i<=s.length(); i++){
            int x = Integer.parseInt(s.substring(i-1, i));
            if (x != 0) dp[i] = dp[i-1];
            if (s.charAt(i-2) != '0') {
                x = Integer.parseInt(s.substring(i-2, i));
                if (1<=x && x<=26) dp[i] += dp[i-2];
            }
        }
        return dp[s.length()];
    }

}
