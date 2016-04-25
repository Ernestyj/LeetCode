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
     * 看到这题第一反应是DFS枚举查找，直到“探”到string尾部则算成功。但题目并不要求给出是如何break的，
     而只要判断是否能break。对这类判断“是”与“否”的可以用DFS暴力解决的题，
     可以尝试用DP做book keeping中间判断状态，避免DFS的反复搜索。
     * 定义t[i]为区间[0,i-1]能否被分割,注意初始状态t[0]=True.
     t[i+1]=True时应满足:1.s[k,i]在字典中,0<=k<=i;2.t[k]==True.
     * @param s
     * @param wordDict
     * @return
     */
    public boolean wordBreak(String s, Set<String> wordDict) {
        boolean[] t = new boolean[s.length()+1];
        t[0] = true;
        for (int i=0; i<s.length(); i++){
            for (int j=0; j<=i; j++){   //TODO 边界极易出错
                if (t[j] && wordDict.contains(s.substring(j, i+1))){
                    t[i+1] = true;
                    break;
                }
            }
        }
        return t[s.length()];
    }
    //基于给定字典遍历的DP,注意代码中if (t[end]) continue;部分易错
    public boolean wordBreak1(String s, Set<String> wordDict) {
        boolean[] t = new boolean[s.length()+1];
        t[0] = true;
        for (int i=0; i<s.length(); i++){
            if (!t[i]) continue;    //不能分割,跳过
            for (String word : wordDict){
                int end = i+word.length();
                if (end>s.length()) continue;   //超过字符串s长度
                //注意用例"programcreek", ["programcree","program","creek"]
                //下面的语句保证不会停在programcree,而是读完所有programcreek
                if (t[end]) continue;
                if (s.substring(i, end).equals(word)) t[end] = true;
            }
        }
        return t[s.length()];
    }

    //原始办法:回溯,超时
    public boolean wordBreak2(String s, Set<String> wordDict) {
        return wordBreakHelper(s, wordDict, 0);
    }
    //基于给定字典遍历
    private boolean wordBreakHelper(String s, Set<String> wordDict, int start){
        if (start==s.length()) return true;
        for (String word : wordDict){
            int len = word.length();
            int end = start+len;
            if (end > s.length()) continue; //超过字符串s长度
            if (s.substring(start, end).equals(word)){
                if (wordBreakHelper(s, wordDict, end)) return true;
            }
        }
        return false;
    }
    //基于给定字符串s遍历
    private boolean wordBreakHelper1(String s, Set<String> wordDict, int start){
        if (start==s.length()) return true;
        for (int i=start+1; i<s.length(); i++){
            String str = s.substring(start, i+1);
            if (!wordDict.contains(str)) continue;
            if (wordBreakHelper(s, wordDict, i+1)) return true;
        }
        return false;
    }

}
