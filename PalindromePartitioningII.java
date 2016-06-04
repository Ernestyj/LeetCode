package leetcode131_140;

/**Given a string s, partition s such that every substring of the partition is a palindrome.
 Return the minimum cuts needed for a palindrome partitioning of s.
 For example, given s = "aab",
 Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
 * Created by eugene on 16/2/20.
 */
public class PalindromePartitioningII {

    //TODO 重温 hard
    /**http://www.programcreek.com/2014/04/leetcode-palindrome-partitioning-ii-java/
     * DP(双重二维),也可以用回溯法(参考Palindrome Partitioning).
     * 定义cutNum(i)为[0,i]间最小切割数, 有
     cutNum(0,i)=min[curNum(0,j-1)+curNum(j,i)],
     即cut[i] = min{cut[j-1]+1} (j<=i), if [j,i] is palindrome.
     核心思想在于"j从0到i的过程中每找到一个回文,若要切割则在前次切割的基础上加1次".
     * 判断[j,i]间是否为回文也是DP问题,定义palindrome(j,i)为[j,i]间是否为回文,
     palindrome(j,i)= str(j)==str(i) && (i-j<=1 || palindrome(j+1, i-1)).
     i-j<=1因为一个字符一定也是回文(这个条件使得边界情况初始化可以省略).
     * @param s
     * @return
     */
    public int minCut(String s) {
        int len = s.length();
        boolean[][] palindrome = new boolean[len][len];
        int[] cut = new int[len];

        for (int i=0; i<len; i++){
            cut[i] = i;
            for (int j=0; j<=i; j++){
                if (s.charAt(j)==s.charAt(i) && (i-j<=1 || palindrome[j+1][i-1])){
                    palindrome[j][i] = true;
                    if (j==0) cut[i] = 0;   //无需切割
                    else cut[i] = Math.min(cut[i], cut[j-1]+1);
                }
            }
        }
        return cut[len-1];
    }

}
