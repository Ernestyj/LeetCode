
/**Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it.
 * Find and return the shortest palindrome you can find by performing this transformation.
 For example:
 Given "aacecaaa", return "aaacecaaa".
 Given "abcd", return "dcbabcd".
 * Created by eugene on 16/4/10.
 */
//回文串的其他的题目有 Palindrome Number，Validate Palindrome，Palindrome Partitioning，Palindrome Partitioning II 和 Longest Palindromic Substring
class Solution {
public://TODO 较难理解，多记忆
    //使用双指针来找出字符串s的最长回文前缀的大概范围，指针i和j分别指向s串的开头和末尾，若 s[i] 和 s[j] 相等，则i自增1，j自减1，否则只有j自减1。
    // 这样遍历一遍后，最长回文前缀就在范围 [0, i) 中，但不保证这个本身就是最大回文前缀，我们只能确定后面剩余的部分肯定不属于，
    // 此时我们提取出剩下的字符，翻转一下加到最前面，而对范围 [0, i) 内的子串再次递归调用本函数。
    // 这样，在子函数最终会组成最短的回文串，从而使得整个的回文串就是最短的
    string shortestPalindrome(string s) {
        int i = 0, n = s.size();
        for (int j = n - 1; j >= 0; --j) {
            if (s[i] == s[j]) ++i;
        }
        if (i == n) return s;
        string rem = s.substr(i);
        reverse(rem.begin(), rem.end());
        return rem + shortestPalindrome(s.substr(0, i)) + s.substr(i);
    }
};
//public class ShortestPalindrome {
//
//    /** 此解易理解,但3%接近超时
//     * https://leetcode.com/discuss/61416/my-9-lines-three-pointers-java-solution-with-explanation
//     * 寻找从第一个字符起的最长回文串,再逆转剩余部分并拼接到字符串首部
//     */
//    public String shortestPalindrome(String s) {
//        int i = 0, end = s.length()-1, j = end;
//        char chs[] = s.toCharArray();
//        while(i < j) {
//            if (chs[i] == chs[j]) {
//                i++; j--;
//            } else {    //重置
//                i = 0; end--; j = end;
//            }
//        }
//        return new StringBuilder(s.substring(end+1)).reverse().append(chs).toString();
//    }
//
//    /**TODO 待理解
//     * https://segmentfault.com/a/1190000003059361
//     * 思路：1.求字符串s的翻转s_rev
//     2.将两个字符串进行拼接：{s}#{s_rev}
//     3.找出新字符串中最长公共前缀后缀长度comLen
//     4. s_rev.substring(0, s.length() - comLen)就是在原字符串头部插入的子串部分
//     * @param s
//     * @return
//     */
//    public String shortestPalindrome1(String s) {
//        StringBuilder builder = new StringBuilder(s);
//        return builder.reverse().substring(0, s.length() - getCommonLength(s)) + s;
//    }
//    private int getCommonLength(String str) {
//        StringBuilder builder = new StringBuilder(str);
//        String rev = new StringBuilder(str).reverse().toString();
//        builder.append("#").append(rev);
//        int[] p = new int[builder.length()];
//        for (int i = 1; i < p.length; i++) {
//            int j = p[i - 1];
//            while (j > 0 && builder.charAt(i) != builder.charAt(j)) j = p[j - 1];
//            p[i] = j == 0 ? (builder.charAt(i) == builder.charAt(0) ? 1 : 0) : j + 1;
//        }
//        return p[p.length - 1];
//    }
//
//    //TODO 没看懂
//    //https://leetcode.com/discuss/76987/short-java-based-solution-with-explanation-need-extend-string
//    //KMP思路寻找从第一个字符起的最长回文串,再逆转剩余部分并拼接到字符串首部
//    public String shortestPalindrome2(String s) {
//        if (s.length()<=1) return s;
//        char[] chars = s.toCharArray();
//        // the next array stores the failure function of each position.
//        int[] next = new int[chars.length];
//        next[0] = -1;
//        int i = 0, j = -1;
//        while (i < chars.length-1) {
//            if (j==-1 || chars[j]==chars[i]) {
//                j++;
//                i++;
//                next[i] = j;
//                if (chars[i]==chars[j])
//                    next[i] = next[j];
//            } else j = next[j];
//        }
//        // match the string with its reverse.
//        i = chars.length-1; j = 0;
//        while (i>=0 && j<chars.length) {
//            if (j==-1 || chars[i]==chars[j]) {
//                i--;
//                j++;
//            } else j = next[j];
//        }
//        return new StringBuilder(s.substring(j)).reverse().append(chars).toString();
//    }
//}
