package leetcode81_90;

/**
 * Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
 * Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
 * Created by DCLab on 1/8/2016.
 */
public class ScrambleString {

    public static void main(String[] args) {
        System.out.println("*****RESULT*****");
    }


    /** TODO 重温
     * http://blog.csdn.net/fightforyourdream/article/details/17707187
     * 递归解法：时间复杂度最差为O(3^n)，要通过OJ需要加上剪枝条件：把两个字符串的字符排序后，然后比较是否相同。
     * 三维动态规划解法：提出维护量res[i][j][n]，其中i是s1的起始字符，j是s2的起始字符，而n是当前的字符串长度，
      res[i][j][len]表示的是以i和j分别为s1和s2起点的长度为len的字符串是不是互为scramble。
     * 递推式：首先是把当前s1[i...i+len-1]字符串劈一刀分成两部分，然后分两种情况：
      第一种是左边和s2[j...j+len-1]左边部分是不是scramble，以及右边和s2[j...j+len-1]右边部分是不是scramble；
      第二种情况是左边和s2[j...j+len-1]右边部分是不是scramble，以及右边和s2[j...j+len-1]左边部分是不是scramble。
      如果以上两种情况有一种成立，说明s1[i...i+len-1]和s2[j...j+len-1]是scramble的。
     上面说的是劈一刀的情况，对于s1[i...i+len-1]我们有len-1种劈法，在这些劈法中只要有一种成立，那么两个串就是scramble的。
     总结：res[i][j][len] |= (res[i][j][k]&&res[i+k][j+k][len-k] || res[i][j+len-k][k]&&res[i+k][j][len-k]),1<=k<len，
     也就是对于所有len-1种劈法的结果求或运算。
     * 复杂度：因为信息都是计算过的，对于每种劈法只需要常量操作，因此求解递推式需要线性时间（因为len-1种劈法）。
     如此总时间复杂度因为是三维动态规划需要三层循环，加上每一步需要线行时间求解递推式，所以是O(n^4)。空间复杂度是O(n^3)。
     * @param s1
     * @param s2
     * @return
     */
    public boolean isScramble(String s1, String s2) {
        int len = s1.length();
        if(len != s2.length()) return false;
        boolean[][][] canScramble = new boolean[len][len][len+1];   // i,j with sub length
        for(int i=0; i<len; i++) {  // subLen=1
            for(int j=0; j<len; j++) {
                // substring start from i with length 1, compared with substring start from j with length 1
                canScramble[i][j][1] = s1.charAt(i) == s2.charAt(j);
            }
        }
        for(int subLen=2; subLen<=len; subLen++) {
            // (end_pos=i+subLen-1) <= len-1, so i <= len-subLen
            for(int i=0; i<=len-subLen; i++) {
                for(int j=0; j<=len-subLen; j++) {
                    for(int p=1; p<subLen; p++) {   // split position
                        canScramble[i][j][subLen] |= (canScramble[i][j][p] && canScramble[i+p][j+p][subLen-p]) ||
                                (canScramble[i][j+subLen-p][p] && canScramble[i+p][j][subLen-p]);
                    }
                }
            }
        }
        return canScramble[0][0][len];
    }

}
