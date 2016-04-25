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

    public static void main(String[] args) {
        System.out.println("*****RESULT*****");
        System.out.println(new WildcardMatching().isMatch("aa", "a"));
    }

    /**TODO
     * http://www.cnblogs.com/x1957/p/3517096.html
     * @param s
     * @param p
     * @return
     */
    public boolean isMatch(String s, String p) {
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


    /**TODO 此实现未完成（参考代码较难理解)
     * http://blog.csdn.net/linhuanmars/article/details/21198049
     * 动态规划：
     * 维护一个布尔数组r[i],代表s的前i个字符和p的前j个字符是否匹配(这里因为每次i的结果只依赖于j-1的结果)。
     递推公式分两种情况：
     (1)p[j]不是'*'。情况比较简单，只要判断如果当前s的i和p的j上的字符一样（如果有p在j上的字符是'?'，
     也是相同），并且res[i]==true，则更新res[i+1]为true，否则res[i+1]=false;
     (2)p[j]是'*'。因为'*'可以匹配任意字符串，所以在前面的res[i]只要有true，
     那么剩下的res[i+1], res[i+2],...,res[s.length()]就都是true了。
     时间复杂度：两层循环，O(m*n)；空间复杂度：一个一维数组，O(n)。假设s的长度是n，p的长度是m。
     * @param s
     * @param p
     * @return
     */
    public boolean isMatch1(String s, String p) {
        if (p.length() == 0) return s.length() == 0;
        if (s.length() == 0) return p.charAt(0) == '*';
        boolean[] r = new boolean[s.length()];
        int i = 0, j = 0;
        if (s.charAt(0) == p.charAt(0) || p.charAt(0) == '*' || p.charAt(0) == '?') r[0] = true;
        for ( ; j < p.length(); j++){
            if (p.charAt(j) != '*'){
                if ((s.charAt(i) == p.charAt(j) || p.charAt(j) == '?') && r[i] == true){
                    if (i + 1 < s.length()) r[++i] = true;
                } else {
                    if (i + 1 < s.length()) r[++i] = false;
                }
            } else {    //p.charAt(j) == '*'
                int k = i;
                while (k >= 0){
                    if (r[k] == true) return true;
                    else k--;
                }
            }
        }
        return r[s.length() - 1];
    }
}
