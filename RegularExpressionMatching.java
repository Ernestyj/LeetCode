package leetcode1_10;

/**Implement regular expression matching with support for '.' and '*'.
 '.' Matches any single character.
 '*' Matches zero or more of the preceding element.
 The matching should cover the entire input string (not partial).

 The function prototype should be:
 bool isMatch(const char *s, const char *p)

 Some examples:
 isMatch("aa","a") → false
 isMatch("aa","aa") → true
 isMatch("aaa","aa") → false
 isMatch("aa", "a*") → true
 isMatch("aa", ".*") → true
 isMatch("ab", ".*") → true
 isMatch("aab", "c*a*b") → true
 * Created by eugene on 16/5/31.
 */
public class RegularExpressionMatching {

    /**TODO 有一定难度,注意理解记忆
     * https://leetcode.com/discuss/93024/easy-dp-java-solution-with-detailed-explanation
     * 1. If p[j]==s[i] :  dp[i][j] = dp[i-1][j-1];
     2. If p[j]=='.' : dp[i][j] = dp[i-1][j-1];
     3. If p[j]=='*': here are two sub conditions:
        (1) if p[j-1]!=s[i] : dp[i][j] = dp[i][j-2]  //in this case, a* only counts as empty
        (2) if p[i-1]==s[i] or p[i-1]=='.':
                dp[i][j] = dp[i-1][j]    //in this case, a* counts as multiple a
                    || dp[i][j-1]   // in this case, a* counts as single a
                    || dp[i][j-2]   // in this case, a* counts as empty
     * @param s
     * @param p
     * @return
     */
    public boolean isMatch1(String s, String p) {
        if (s == null || p == null) return false;
        boolean[][] dp = new boolean[s.length()+1][p.length()+1];
        dp[0][0] = true;
        for (int j=0; j<p.length(); j++) {
            if (p.charAt(j)=='*' && dp[0][j-1]) {
                dp[0][j+1] = true;
            }
        }
        for (int i=0 ; i<s.length(); i++) {
            for (int j=0; j<p.length(); j++) {
                if (p.charAt(j)=='.' || p.charAt(j)==s.charAt(i)) { //情况1,2
                    dp[i+1][j+1] = dp[i][j];
                }
                if (p.charAt(j) == '*') {   //情况3
                    if (p.charAt(j-1)!=s.charAt(i) && p.charAt(j-1)!='.') {
                        dp[i+1][j+1] = dp[i+1][j-1];
                    } else {
                        dp[i+1][j+1] = dp[i+1][j] || dp[i][j+1] || dp[i+1][j-1];
                    }
                }
            }
        }
        return dp[s.length()][p.length()];
    }


    /**http://harrifeng.github.io/algo/leetcode/regular-expression-matching.html
     * 递归,条件多易出错
     * @param s
     * @param p
     * @return
     */
    public boolean isMatch(String s, String p) {
        if (p.length() == 0) {
            return s.length() == 0;
        }
        if (p.length() == 1) {
            return s.length() == 1
                    && (p.charAt(0) == '.' || p.charAt(0) == s.charAt(0)) ;
        }
        // p.length() i bigger than 1 here
        if (p.charAt(1) == '*') {
            if (isMatch(s, p.substring(2))) {
                return true;
            }
            return s.length() > 0
                    && (p.charAt(0) == '.' || s.charAt(0) == p.charAt(0))
                    && isMatch(s.substring(1), p);
        } else {
            return s.length() > 0
                    && (p.charAt(0) == '.' || s.charAt(0) == p.charAt(0))
                    && isMatch(s.substring(1), p.substring(1));
        }
    }


}
