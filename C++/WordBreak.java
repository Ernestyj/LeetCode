package leetcode131_140;

import java.util.Set;

/**Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
 For example, given
 s = "leetcode",
 dict = ["leet", "code"].
 Return true because "leetcode" can be segmented as "leet code".
 * Created by eugene on 16/2/27.
 */
public class WordBreak {

    /**http://www.programcreek.com/2012/12/leetcode-solution-word-break/
     * 回溯法超时. 看到这题第一反应是DFS枚举查找，直到“探”到string尾部则算成功。但题目并不要求给出是如何break的，
     而只要判断是否能break。对这类判断“是”与“否”的可以尝试用DP，避免DFS的反复搜索。
     * 定义dp[i]为区间[0,i-1]能否被分割,注意初始状态dp[0]=True.
     dp[i+1]=True时应满足:1.s[k,i]在字典中,0<=k<=i;2.dp[k]==True.
     * @param s
     * @param wordDict
     * @return
     */
    public boolean wordBreak(String s, Set<String> wordDict) {
        boolean[] dp = new boolean[s.length()+1];
        dp[0] = true;
        for (int i=0; i<s.length(); i++){
            for (int k=0; k<=i; k++){   //TODO 边界极易出错
                if (dp[k] && wordDict.contains(s.substring(k, i+1))){
                    dp[i+1] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }

}
