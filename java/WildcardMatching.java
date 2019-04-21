package leetcode41_50;

/**
 * Implement wildcard pattern matching with support for '?' and '*'.
 * Some examples:
 isMatch("aa","a") → false
 isMatch("aa","aa") → true
 isMatch("aaa","aa") → false
 isMatch("aa", "*") → true
 isMatch("aa", "a*") → true
 isMatch("ab", "?*") → true
 isMatch("aab", "c*a*b") → false
 * Created by DCLab on 11/27/2015.
 */
public class WildcardMatching {

    /**https://leetcode.com/discuss/54278/my-java-dp-solution-using-2d-table
     * DP TODO 理解状态转移
     dp[i][j] = dp[i-1][j-1]             当s.charAt(i-1)==p.charAt(j-1) || p.charAt(j-1)=='?'
     dp[i][j] = dp[i-1][j] || dp[i][j-1] 当p.charAt(j-1)=='*'
     * @param s
     * @param p
     * @return
     */
    public boolean isMatch(String s, String p) {
        int m = s.length(), n = p.length();
        boolean[][] dp = new boolean[m+1][n+1];
        dp[0][0] = true;
        for(int j=1; j<=n; j++) {
            if(p.charAt(j-1)=='*') dp[0][j] = true;
            else break;
        }
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if (p.charAt(j-1)!='*') {
                    if (s.charAt(i-1)==p.charAt(j-1) || p.charAt(j-1)=='?')
                        dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
            }
        }
        return dp[m][n];
    }

    /**TODO
     * http://www.cnblogs.com/x1957/p/3517096.html
     * @param s
     * @param p
     * @return
     */
    public boolean isMatch1(String s, String p) {
        int i = 0;
        int j = 0;
        int starIndex = -1;
        int iIndex = -1;
        while (i < s.length()) {
            //匹配就s++, p++
            if (j < p.length() && (p.charAt(j) == '?' || p.charAt(j) == s.charAt(i))) {
                ++i;
                ++j;
            //遇到*就记录当前*的位置和匹配到的s的位置
            } else if (j < p.length() && p.charAt(j) == '*') {
                starIndex = j;
                iIndex = i;
                j++;
            //不匹配的话就看p之前是否有*
            } else if (starIndex != -1) {
                //从*的下一位置匹配,开始匹配0个字符，如果ok往后走,
                j = starIndex + 1;
                i = iIndex + 1;
                //往后不ok则匹配1个字符...同理2,3,4个字符(有点回溯的感觉)
                iIndex++;
            } else {
                return false;   //不匹配返回false
            }
        }
        //跳过连续的*
        while (j < p.length() && p.charAt(j) == '*') ++j;
        return j == p.length();
    }

}
