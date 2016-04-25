package leetcode111_120;

/**Given a string S and a string T, count the number of distinct subsequences of T in S.
 Here is an example:S = "rabbbit", T = "rabbit", Return 3.
 https://leetcode.com/problems/distinct-subsequences/
 * Created by eugene on 16/2/3.
 */
public class DistinctSubsequences {

    /**http://www.programcreek.com/2013/01/leetcode-distinct-subsequences-total-java/
     * 图解:http://blog.csdn.net/abcbc/article/details/8978146
     * 二维动态规划(与Interleaving String思路一致):W(i,j)表示S(0,i)的子串与T(0,j)相同的个数,
     递推式:W(i,j)=W(i-1,j-1)+W(i-1,j),当S(i)==T(j)时;
     W(i,j)=W(i-1,j),当S(i)!=T(j)时.
     边界条件:S,T均为空串,W(0,0)=1;
     仅S为空串,W(0,j)=0;
     仅T为空串,W(i,0)=1;
     * @param s
     * @param t
     * @return
     */
    public int numDistinct(String s, String t) {
        int lenS = s.length(), lenT = t.length();
        int[][] result = new int[lenS+1][lenT+1];
        result[0][0] = 1;
        //for (int j=1; j<=lenT; j++) result[0][j] = 0; //冗余
        for (int i=1; i<=lenS; i++) result[i][0] = 1;
        for (int i=1; i<=lenS; i++)
            for (int j=1; j<=lenT; j++){
                result[i][j] = result[i-1][j];
                if (s.charAt(i-1) == t.charAt(j-1)) result[i][j] += result[i-1][j-1];
            }
        return result[lenS][lenT];
    }

}
