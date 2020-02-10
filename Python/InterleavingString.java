package leetcode91_100;

/**Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
 For example,
 Given:
 s1 = "aabcc",
 s2 = "dbbca",
 When s3 = "aadbbcbcac", return true.
 When s3 = "aadbbbaccc", return false.
 * Created by eugene on 16/1/17.
 */
public class InterleavingString {

    public static void main(String[] args) {
        System.out.println("*****RESULT*****");
    }


    /**http://fisherlei.blogspot.in/2012/12/leetcode-interleaving-string.html
     * 二维动态规划:matched[l1][l2]表示s1取l1长度，s2取l2长度，是否能匹配s3的l1+12长度。
     递推式:matched[i][j] = s1.charAt(i-1)==s3.char(i+j-1) && matched[i-1][j] ||
                            s2.charAt(j-1)==s3.charAt(i+j-1) && matched[i][j-1];
     边界条件:l1=0 && l2=0时，matched[0][0] = true;
     i=0时，s3[j-1]==s2[j-1], matched[0][j] = matched[0][j-1]
            s3[j-1]!=s2[j-1], matched[0][j] = false;
     j=0时，s3[i-1]==s1[i-1], matched[i][0] = matched[i-1][0]
            s3[i-1]!=s1[i-1], matched[i][0] = false;
     * @param s1
     * @param s2
     * @param s3
     * @return
     */
    public boolean isInterleave(String s1, String s2, String s3) {
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        if (len1==0 && len2==0 && len3==0) return true;
        if (len1 + len2 != len3) return false;
        boolean[][] matched = new boolean[len1+1][len2+1];
        matched[0][0] = true;   //二维初始
        for (int j=1; j<=len2; j++){    //j一维初始
            if (s2.charAt(j-1) == s3.charAt(j-1)) matched[0][j] = matched[0][j-1];
        }
        for (int i=1; i<=len1; i++){    //i一维初始
            if (s1.charAt(i-1) == s3.charAt(i-1)) matched[i][0] = matched[i-1][0];
        }
        for (int i=1; i<=len1; i++){
            for (int j=1; j<=len2; j++){
                matched[i][j] = s1.charAt(i-1)==s3.charAt(i+j-1) && matched[i-1][j] ||
                                s2.charAt(j-1)==s3.charAt(i+j-1) && matched[i][j-1];
            }
        }
        return matched[len1][len2];
    }

}
