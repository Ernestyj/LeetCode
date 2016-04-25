package leetcode131_140;

import java.util.ArrayList;
import java.util.List;
import java.util.Set;

/**Given a string s and a dictionary of words dict, add spaces in s
 to construct a sentence where each word is a valid dictionary word.
 Return all such possible sentences.
 For example, given
 s = "catsanddog",
 dict = ["cat", "cats", "and", "sand", "dog"].
 A solution is ["cats and dog", "cat sand dog"].
 * Created by eugene on 16/2/28.
 */
public class WordBreakII {

    /**
     * DP+回溯,与Word Break I不同在于用数组记录断词处有哪些单词,而不是简单记录布尔数组.
     DP之后再回溯得到所有可能的断词方式.
     http://www.programcreek.com/2014/03/leetcode-word-break-ii-java/
     * @param s
     * @param wordDict
     * @return
     */
    public List<String> wordBreak(String s, Set<String> wordDict) {
        List<String> result = new ArrayList<>();
        List<String> dp[] = new ArrayList[s.length()+1];
        dp[0] = new ArrayList<>();
        for (int i=0; i<s.length(); i++){
            if (dp[i]==null) continue;
            for (String word : wordDict){
                int end = i+word.length();
                if (end>s.length()) continue;
                if (s.substring(i, end).equals(word)){
                    if (dp[end]==null) dp[end] = new ArrayList<>();
                    dp[end].add(word);
                }
            }
        }
        if (dp[s.length()]==null) return result;
        dfs(dp, s.length(), result, new ArrayList<>());
        return result;
    }
    //回溯
    private void dfs(List<String>[] dp, int end, List<String> result, List<String> tmp){
        if (end<=0){
            String path = tmp.get(tmp.size()-1);
            for (int i=tmp.size()-2; i>=0; i--) path += " " + tmp.get(i);
            result.add(path);
            return;
        }
        for (String str : dp[end]){
            tmp.add(str);
            dfs(dp, end-str.length(), result, tmp);
            tmp.remove(tmp.size()-1);
        }
    }

    //回溯,但无法过大数据集(可以尝试引入剪枝函数提速)
    public List<String> wordBreak1(String s, Set<String> wordDict) {
        List<String> result = new ArrayList<>();
        wordBreakHelper(s, wordDict, 0, result, new StringBuilder());
        return result;
    }
    private void wordBreakHelper(String s, Set<String> wordDict, int start,
                                 List<String> result, StringBuilder builder){
        if (start==s.length()){
            result.add(builder.toString().trim());
            return;
        }
        for (int i=start+1; i<s.length(); i++){
            String str = s.substring(start, i+1);
            if (wordDict.contains(str)) {
                int len = builder.length();
                builder.append(" "+str);
                wordBreakHelper(s, wordDict, i+1, result, builder);
                builder.delete(len, len+str.length()+1);
            }
        }
    }

}
