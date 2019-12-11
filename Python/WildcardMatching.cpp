
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
//‘*’ 能代替任何字符串，注意跟另一道 Regular Expression Matching 正则匹配的题目区分开来。两道题的星号的作用是不同的
class Solution {
public:
    //dp[i][j] 表示s[0,i)和p[0,j)是否能匹配
    //dp[i][j] = dp[i-1][j-1]             当s[i-1]==p[j-1] || p[j-1]=='?'
    //dp[i][j] = dp[i-1][j] || dp[i][j-1] 当p[j-1]=='*'
    //解释：如果p中的前j-1个字符跟s中前i个字符匹配成功了（dp[i][j-1]==true）的话，那么dp[i][j]也能为 true；
    // 或者若p中的前j个字符跟s中的前i-1个字符匹配成功了（dp[i-1][j]==true）的话，那么dp[i][j]也能为 true.
    bool isMatch(string s, string p) {//TODO 理解状态转移
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int j = 1; j <= n; ++j) {//由于星号是可以代表空串的，所以只要s为空，那么连续的星号的位置都应该为 true
            if (p[j - 1] == '*') dp[0][j] = true;
            else break;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};
//public class WildcardMatching {
//
//    /**https://leetcode.com/discuss/54278/my-java-dp-solution-using-2d-table
//     * DP TODO 理解状态转移
//     dp[i][j] = dp[i-1][j-1]             当s.charAt(i-1)==p.charAt(j-1) || p.charAt(j-1)=='?'
//     dp[i][j] = dp[i-1][j] || dp[i][j-1] 当p.charAt(j-1)=='*'
//     */
//    public boolean isMatch(String s, String p) {
//        int m = s.length(), n = p.length();
//        boolean[][] dp = new boolean[m+1][n+1];
//        dp[0][0] = true;
//        for(int j=1; j<=n; j++) {
//            if(p.charAt(j-1)=='*') dp[0][j] = true;
//            else break;
//        }
//        for(int i=1; i<=m; i++) {
//            for(int j=1; j<=n; j++) {
//                if (p.charAt(j-1)!='*') {
//                    if (s.charAt(i-1)==p.charAt(j-1) || p.charAt(j-1)=='?')
//                        dp[i][j] = dp[i-1][j-1];
//                } else {
//                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
//                }
//            }
//        }
//        return dp[m][n];
//    }
//
//    /**TODO
//     * http://www.cnblogs.com/x1957/p/3517096.html
//     * @param s
//     * @param p
//     * @return
//     */
//    public boolean isMatch1(String s, String p) {
//        int i = 0;
//        int j = 0;
//        int starIndex = -1;
//        int iIndex = -1;
//        while (i < s.length()) {
//            //匹配就s++, p++
//            if (j < p.length() && (p.charAt(j) == '?' || p.charAt(j) == s.charAt(i))) {
//                ++i;
//                ++j;
//            //遇到*就记录当前*的位置和匹配到的s的位置
//            } else if (j < p.length() && p.charAt(j) == '*') {
//                starIndex = j;
//                iIndex = i;
//                j++;
//            //不匹配的话就看p之前是否有*
//            } else if (starIndex != -1) {
//                //从*的下一位置匹配,开始匹配0个字符，如果ok往后走,
//                j = starIndex + 1;
//                i = iIndex + 1;
//                //往后不ok则匹配1个字符...同理2,3,4个字符(有点回溯的感觉)
//                iIndex++;
//            } else {
//                return false;   //不匹配返回false
//            }
//        }
//        //跳过连续的*
//        while (j < p.length() && p.charAt(j) == '*') ++j;
//        return j == p.length();
//    }
//
//}
