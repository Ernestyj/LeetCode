package leetcode131_140;

import java.util.*;

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
    //TODO 重温
    /**https://leetcode.com/discuss/65692/my-concise-java-solution-based-on-memorized-dfs
     * Using DFS directly will lead to TLE,
     so used HashMap to save the previous results to prune duplicated branches
     * @param s
     * @param wordDict
     * @return
     */
    public List<String> wordBreak(String s, Set<String> wordDict) {
        return dfs(s, wordDict, new HashMap<>());
    }
    List<String> dfs(String s, Set<String> wordDict, HashMap<String, LinkedList<String>> map) {
        if (map.containsKey(s)) return map.get(s);  //TODO 重复情况直接返回,提速
        LinkedList<String> list = new LinkedList<>();
        if (s.length() == 0) {  //TODO 便于末尾情况处理
            list.add("");
            return list;
        }
        for (String word : wordDict) {
            if (s.startsWith(word)) {
                List<String> sublist = dfs(s.substring(word.length()), wordDict, map);
                for (String w: sublist)
                    list.add(word + (w.isEmpty()? "" : " ") + w);
            }
        }
        map.put(s, list);
        return list;
    }


    /**
     * DP+回溯,与Word Break I不同在于用数组记录断词处有哪些单词,而不是简单记录布尔数组.
     DP之后再回溯得到所有可能的断词方式.
     http://www.programcreek.com/2014/03/leetcode-word-break-ii-java/
     * @param s
     * @param wordDict
     * @return
     */
    public List<String> wordBreak1(String s, Set<String> wordDict) {
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

}
