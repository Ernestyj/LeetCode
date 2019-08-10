
/**Given a string S and a string T, count the number of distinct subsequences of T in S.
 Here is an example:S = "rabbbit", T = "rabbit", Return 3.
 https://leetcode.com/problems/distinct-subsequences/
 Input: S = "rabbbit", T = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from S.
(The caret symbol ^ means the chosen letters)
rabbbit
^^^^ ^^
rabbbit
^^ ^^^^
rabbbit
^^^ ^^^
 * Created by eugene on 16/2/3.
 */
/*
  Ø r a b b b i t
Ø 1 1 1 1 1 1 1 1
r 0 1 1 1 1 1 1 1
a 0 0 1 1 1 1 1 1
b 0 0 0 1 2 3 3 3
b 0 0 0 0 1 3 3 3
i 0 0 0 0 0 0 3 3
t 0 0 0 0 0 0 0 3
dp[i][j] 表示s中范围是 [0, j] 的子串中能组成t中范围是 [0, i] 的子串的子序列的个数.
 当 T[i-1] == S[j-1] 时，dp[i][j] = dp[i][j-1] + dp[i-1][j-1]，
 若不等，                dp[i][j] = dp[i][j-1]
 */
class Solution {
public:
    int numDistinct(string s, string t) {
        int ls = s.length();
        int lt = t.length();
        vector<vector<long>> dp(lt + 1, vector<long>(ls + 1));//用long, 否则溢出
        fill(begin(dp[0]), end(dp[0]), 1);
        for (int i = 1; i <= lt; ++i)
            for (int j = 1; j <= ls; ++j)
                dp[i][j] = dp[i][j-1] + (t[i-1] == s[j-1] ? dp[i-1][j-1] : 0);
        return dp[lt][ls];
    }
};
//public class DistinctSubsequences {
//
//    /**http://www.programcreek.com/2013/01/leetcode-distinct-subsequences-total-java/
//     * 图解:http://blog.csdn.net/abcbc/article/details/8978146
//     * 二维动态规划(与Interleaving String思路一致):W(i,j)表示S(0,i)的子串与T(0,j)相同的个数,
//     递推式:W(i,j)=W(i-1,j-1)+W(i-1,j),当S(i)==T(j)时;
//     W(i,j)=W(i-1,j),当S(i)!=T(j)时.
//     边界条件:S,T均为空串,W(0,0)=1;
//     仅S为空串,W(0,j)=0;
//     仅T为空串,W(i,0)=1;
//     */
//    public int numDistinct(String s, String t) {
//        int lenS = s.length(), lenT = t.length();
//        int[][] result = new int[lenS+1][lenT+1];
//        result[0][0] = 1;
//        //for (int j=1; j<=lenT; j++) result[0][j] = 0; //冗余
//        for (int i=1; i<=lenS; i++) result[i][0] = 1;
//        for (int i=1; i<=lenS; i++)
//            for (int j=1; j<=lenT; j++){
//                result[i][j] = result[i-1][j];
//                if (s.charAt(i-1) == t.charAt(j-1)) result[i][j] += result[i-1][j-1];
//            }
//        return result[lenS][lenT];
//    }
//
//}
