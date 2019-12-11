
/**
 * Given n pairs of parentheses, write a function to generate all combinations of
 * well-formed parentheses.

 For example, given n = 3, a solution set is:
 "((()))", "(()())", "(())()", "()(())", "()()()"
 *
 * Created by DCLab on 11/5/2015.
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res, "", 0, 0, n);
        return res;
    }
    void backtrack(vector<string>& res, string s, int open, int close, const int n){
        if(s.size() == n*2){
            res.push_back(s);
            return;
        }
        if(open<n) backtrack(res, s+"(", open+1, close, n);
        if(close<open) backtrack(res, s+")", open, close+1, n);
    }
};
//public class GenerateParentheses {
//
//    /**
//     * https://leetcode.com/discuss/25063/easy-to-understand-java-backtracking-solution
//     * 简洁,易理解与记忆
//     * 剪枝条件1，开闭括号数小于num
//     * 剪枝条件2，开括号数>=闭括号数
//     * @param n
//     * @return
//     */
//    public List<String> generateParenthesis(int n) {
//        List<String> list = new ArrayList<>();
//        backtrack(list, "", 0, 0, n);
//        return list;
//    }
//    public void backtrack(List<String> list, String str, int open, int close, int n){
//        if(str.length() == n*2){
//            list.add(str);
//            return;
//        }
//        if(open < n)
//            backtrack(list, str+"(", open+1, close, n);
//        if(close < open)
//            backtrack(list, str+")", open, close+1, n);
//    }
//
//
//
//    private int num = 0;
//    private StringBuilder builder = new StringBuilder();
//    private List<String> list = new ArrayList<>();
//    public List<String> generateParenthesis1(int n) {
//        num = n;
//        backtrack1(1, builder, 0);
//        return list;
//    }
//    /**
//     * 剪枝条件1，左右括号数小于num
//     * 剪枝条件2，左括号数>=右括号数
//     *
//     * @param i
//     * @param builder
//     * @param rightCount
//     */
//    private void backtrack1(int i, StringBuilder builder, int rightCount){
//        if (i > num * 2){
//            list.add(builder.toString());
//        } else {
//            for (int isTake = 0; isTake <= 1; isTake++){    //0:( 1:)
//                char c = isTake == 0 ? '(' : ')';
//                int tempRightCount = rightCount + isTake * 1;
//                if (i - tempRightCount <= num &&    //剪枝条件1，左右括号数小于num
//                        i - tempRightCount >= tempRightCount){  //剪枝条件2，左括号数>=右括号数
//                    builder.append(c);
//                    rightCount = tempRightCount;
//                    backtrack1(i + 1, builder, rightCount);
//                    rightCount -= isTake * 1;
//                    builder.deleteCharAt(builder.length() - 1);
//                }
//            }
//        }
//
//    }
//
//}
