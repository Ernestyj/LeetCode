package leetcode131_140;

import java.util.ArrayList;
import java.util.List;

/**Given a string s, partition s such that every substring of the partition is a palindrome.
 Return all possible palindrome partitioning of s.
 For example, given s = "aab",
 Return [ ["aa","b"], ["a","a","b"] ]
 * Created by eugene on 16/2/19.
 */
public class PalindromePartitioning {

    /**
     * http://www.programcreek.com/2013/03/leetcode-palindrome-partitioning-java/
     * 回溯法(dfs),当然DP也可以(可参考Palindrome Partitioning II).
     * @param s
     * @return
     */
    public List<List<String>> partition(String s) {
        List<List<String>> res = new ArrayList<>();
        dfs(res, s, 0, new ArrayList<>());
        return res;
    }
    private void dfs(List<List<String>> res, String s, int start, List<String> sol){
        if(start==s.length()){
            res.add(new ArrayList<>(sol));
            return;
        }
        for(int i=start; i<s.length(); i++){
            String str = s.substring(start, i+1);
            if(isPalindrome(str)){
                sol.add(str);
                dfs(res, s, i+1, sol);
                sol.remove(sol.size()-1);
            }
        }
    }
    private boolean isPalindrome(String s){
        int l = 0, r = s.length()-1;
        while(l<r){
            if(s.charAt(l++)!=s.charAt(r--)) return false;
        }
        return true;
    }

}
