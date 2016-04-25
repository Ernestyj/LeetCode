package leetcode1_10;

/**最长连续回文串
 * Given a string S, find the longest palindromic substring in S. You may assume that
 the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 * Created by DCLab on 11/25/2015.
 */
public class LongestPalindromicSubstring {

    /**
     * http://www.programcreek.com/2013/12/leetcode-solution-of-longest-palindromic-substring-java/
     * Time O(n^2), Space O(1)
     * @param s
     * @return
     */
    public String longestPalindrome(String s) {
        if (s==null) return null;
        if (s.length()<=1) return s;
        String longest = s.substring(0, 1);
        for (int i=0; i<s.length(); i++) {
            String tmp = helper(s, i, i);
            if (tmp.length() > longest.length()) longest = tmp;
            tmp = helper(s, i, i + 1);
            if (tmp.length() > longest.length()) longest = tmp;
        }
        return longest;
    }
    // get longest palindrome with center of (begin,end)
    private String helper(String s, int begin, int end) {
        while (begin>=0 && end<=s.length()-1 && s.charAt(begin)==s.charAt(end)) {
            begin--;
            end++;
        }
        return s.substring(begin + 1, end);
    }

    /**TODO 此法对于全是同一个字符的长字符串用例超时
     * http://www.programcreek.com/2013/12/leetcode-solution-of-longest-palindromic-substring-java/
     * Time O(n^2) Space O(n^2)
     * DP: dp[i,j] = 1 if dp[i+1,j-1]==1 && s[i]==s[j]
     初始条件有: dp[i,i] = 1
     dp[i,i+1] = 1 if s[i]==s[i+1]
     TODO 注意there exists one unique longest palindromic substring
     * @param s
     * @return
     */
    public String longestPalindrome1(String s) {
        if (s==null) return null;
        if (s.length()<=1) return s;
        String longestStr = null;
        int maxLen = 0;
        int len = s.length();
        int[][] dp = new int[len][len];
        for (int i=0; i<len; i++){
            dp[i][i] = 1;
            if (i+1<len){
                if (s.charAt(i)==s.charAt(i+1)) {
                    dp[i][i+1] = 1;
                    longestStr = s.substring(i, i+2);
                    maxLen = 2;
                }
            }
        }
        for (int l=3; l<=len; l++){ //最外层要从长度l开始
            for (int i=0; i<=len-l; i++){
                int j = i+l-1;
                if (j<len){
                    if (dp[i+1][j-1]==1 && s.charAt(i)==s.charAt(j)){
                        dp[i][j] = 1;
                        if (l>maxLen) {
                            longestStr = s.substring(i, j+1);
                            maxLen = l;
                        }
                    }
                }
            }
        }
        return longestStr;
    }

}
