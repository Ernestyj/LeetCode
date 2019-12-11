
/**Given a string s, partition s such that every substring of the partition is a palindrome.
 Return all possible palindrome partitioning of s.
 For example, given s = "aab",
 Return [ ["aa","b"], ["a","a","b"] ]
 * Created by eugene on 16/2/19.
 */
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> sol;
        dfs(s, res, sol, 0);
        return res;
    }
    void dfs(string s, vector<vector<string>>& res, vector<string>& sol, int start){
        if(start==s.size()){
            res.push_back(sol);
        }else{
            for (int i = start; i < s.size(); ++i) {
                string temp(s, start, i+1-start);
                if(isPalindrome(temp)){
                    sol.push_back(temp);
                    dfs(s, res, sol, i+1);
                    sol.pop_back();
                }
            }
        }
    }
    bool isPalindrome(string s){
        int l = 0, r = s.size()-1;
        while(l<r){
            if(s[l++]!=s[r--]) return false;
        }
        return true;
    }
};
//public class PalindromePartitioning {
//    /**
//     * http://www.programcreek.com/2013/03/leetcode-palindrome-partitioning-java/
//     * 回溯法(dfs),当然DP也可以(可参考Palindrome Partitioning II).
//     */
//    public List<List<String>> partition(String s) {
//        List<List<String>> res = new ArrayList<>();
//        dfs(res, s, 0, new ArrayList<>());
//        return res;
//    }
//    private void dfs(List<List<String>> res, String s, int start, List<String> sol){
//        if(start==s.length()){
//            res.add(new ArrayList<>(sol));
//            return;
//        }
//        for(int i=start; i<s.length(); i++){
//            String str = s.substring(start, i+1);
//            if(isPalindrome(str)){
//                sol.add(str);
//                dfs(res, s, i+1, sol);
//                sol.remove(sol.size()-1);
//            }
//        }
//    }
//    private boolean isPalindrome(String s){
//        int l = 0, r = s.length()-1;
//        while(l<r){
//            if(s.charAt(l++)!=s.charAt(r--)) return false;
//        }
//        return true;
//    }
//
//}
