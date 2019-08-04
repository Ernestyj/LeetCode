
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
 isMatch("ab", "a*") → false
 isMatch("aa", ".*") → true
 isMatch("ab", ".*") → true
 isMatch("aab", "c*a*b") → true
 * Created by eugene on 16/5/31.
 */

class Solution {
public:
    //dp[i][j]表示s[0,i)和p[0,j)是否match TODO 有一定难度,注意理解记忆
    //1. P[i][j] = P[i - 1][j - 1], if p[j - 1] != '*' && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
    //2. P[i][j] = P[i][j - 2],     if p[j - 1] == '*' and the pattern repeats for 0 times;
    //3. P[i][j] = P[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'),
    //                              if p[j - 1] == '*' and the pattern repeats for at least 1 times.
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (j > 1 && p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] ||
                            (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                } else {
                    dp[i][j] = i > 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.') && dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }

    //1. 先来判断p是否为空，若为空则根据s的为空的情况返回结果。
    //2. 当p的第二个字符为*号时，2.1由于*号前面的字符的个数可以任意，可以为0，那么我们先用递归来调用为0的情况，就是直接把这两个字符去掉再比较，
    //2.2 或者当s不为空，且第一个字符和p的第一个字符相同时，我们再对去掉首字符的s和p调用递归，注意p不能去掉首字符，因为*号前面的字符可以有无限个；
    //3. 当p的第二个字符不为*号，那么我们就老老实实的比较第一个字符，然后对后面的字符串调用递归
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        if (p.size() > 1 && p[1] == '*') {
            return isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p));
        } else {
            return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
        }
    }
};
//public class RegularExpressionMatching {
//
//    /**TODO 有一定难度,注意理解记忆
//     * https://leetcode.com/discuss/93024/easy-dp-java-solution-with-detailed-explanation
//     * 1. If p[j]==s[i] :  dp[i][j] = dp[i-1][j-1];
//     2. If p[j]=='.' : dp[i][j] = dp[i-1][j-1];
//     3. If p[j]=='*': here are two sub conditions:
//        (1) if p[j-1]!=s[i] : dp[i][j] = dp[i][j-2]  //in this case, a* only counts as empty
//        (2) if p[i-1]==s[i] or p[i-1]=='.':
//                dp[i][j] = dp[i-1][j]    //in this case, a* counts as multiple a
//                    || dp[i][j-1]   // in this case, a* counts as single a
//                    || dp[i][j-2]   // in this case, a* counts as empty
//     * @param s
//     * @param p
//     * @return
//     */
//    public boolean isMatch1(String s, String p) {
//        if (s == null || p == null) return false;
//        boolean[][] dp = new boolean[s.length()+1][p.length()+1];
//        dp[0][0] = true;
//        for (int j=0; j<p.length(); j++) {
//            if (p.charAt(j)=='*' && dp[0][j-1]) {
//                dp[0][j+1] = true;
//            }
//        }
//        for (int i=0 ; i<s.length(); i++) {
//            for (int j=0; j<p.length(); j++) {
//                if (p.charAt(j)=='.' || p.charAt(j)==s.charAt(i)) { //情况1,2
//                    dp[i+1][j+1] = dp[i][j];
//                }
//                if (p.charAt(j) == '*') {   //情况3
//                    if (p.charAt(j-1)!=s.charAt(i) && p.charAt(j-1)!='.') {
//                        dp[i+1][j+1] = dp[i+1][j-1];
//                    } else {
//                        dp[i+1][j+1] = dp[i+1][j] || dp[i][j+1] || dp[i+1][j-1];
//                    }
//                }
//            }
//        }
//        return dp[s.length()][p.length()];
//    }
//
//
//    /**http://harrifeng.github.io/algo/leetcode/regular-expression-matching.html
//     * 递归,条件多易出错
//     * @param s
//     * @param p
//     * @return
//     */
//    public boolean isMatch(String s, String p) {
//        if (p.length() == 0) {
//            return s.length() == 0;
//        }
//        if (p.length() == 1) {
//            return s.length() == 1
//                    && (p.charAt(0) == '.' || p.charAt(0) == s.charAt(0)) ;
//        }
//        // p.length() i bigger than 1 here
//        if (p.charAt(1) == '*') {
//            if (isMatch(s, p.substring(2))) {
//                return true;
//            }
//            return s.length() > 0
//                    && (p.charAt(0) == '.' || s.charAt(0) == p.charAt(0))
//                    && isMatch(s.substring(1), p);
//        } else {
//            return s.length() > 0
//                    && (p.charAt(0) == '.' || s.charAt(0) == p.charAt(0))
//                    && isMatch(s.substring(1), p.substring(1));
//        }
//    }
//
//
//}
