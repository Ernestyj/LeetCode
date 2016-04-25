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

    public static void main(String[] args) {
        List<List<String>> result = new PalindromePartitioning().partition("amanaplanacanalpanama");
        for (List<String> list : result){
            for (String s : list){
                System.out.print(s + " ");
            }
            System.out.println();
        }
    }

    /**
     * http://www.programcreek.com/2013/03/leetcode-palindrome-partitioning-java/
     * 回溯法(DFS),当然DP也可以(可参考Palindrome Partitioning II).
     * @param s
     * @return
     */
    public List<List<String>> partition(String s) {
        List<List<String>> result = new ArrayList<>();
        if (s==null || s.length()==0) return result;
        List<String> partitionList = new ArrayList<>();
        partitionHepler(s, 0, partitionList, result);
        return result;
    }
    private void partitionHepler(String s, int start, List<String> partitionList, List<List<String>> result){
        if (start==s.length()){
            result.add(new ArrayList<>(partitionList));
            return;
        }
        for (int i=start+1; i<=s.length(); i++){
            String str = s.substring(start, i);
            if (isPalindrome(str)){
                partitionList.add(str);
                partitionHepler(s, i, partitionList, result);
                partitionList.remove(partitionList.size()-1);
            }
        }
    }
    private boolean isPalindrome(String str){
        int l=0, r=str.length()-1;
        while (l<r){
            if (str.charAt(l++)!=str.charAt(r--)) return false;
        }
        return true;
    }

}
