
/**
 * Given a string containing just the characters '(' and ')', find the length of
 the longest valid (well-formed) parentheses substring.
 For "(()", the longest valid parentheses substring is "()", which has length = 2.
 Another example is ")()())", where the longest valid parentheses substring is "()()",
 which has length = 4.
 * Created by Eugene on 11/16/2015.
 */
class Solution {
public:
    // 定义个start变量来记录合法括号串的起始位置，我们遍历字符串，1. 如果遇到左括号，则将当前下标压入栈，
    // 2. 如果遇到右括号，2.1如果当前栈为空，则将下一个坐标位置记录到start，
    // 2.2 如果栈不为空，则将栈顶元素取出，此时若栈为空，则更新为结果和i - start + 1中的较大值，否则更新为结果和i - 栈顶元素中的较大值
    int longestValidParentheses(string s) {
        int maxLen = 0, start = 0;
        stack<int> stk;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') stk.push(i);
            else if (s[i] == ')') {
                if (stk.empty()) start = i + 1;
                else {
                    stk.pop();
                    maxLen = stk.empty() ? max(maxLen, i - start + 1) : max(maxLen, i - stk.top());
                }
            }
        }
        return maxLen;
    }
};
//public class LongestValidParentheses {
//
//    /**https://leetcode.com/discuss/7609/my-o-n-solution-using-a-stack
//     * V[i] represents number of valid parentheses matches from S[j to i] (j<i)
//     V[i] = V[i-1]+2+previous matches V[i-(V[i-1]+2)], if S[i]==')' and open'('count > 0
//     */
//    public int longestValidParentheses(String s) {
//        char[] chars = s.toCharArray();
//        int[] dp = new int[chars.length];
//        int open = 0;
//        int max = 0;
//        for (int i=0; i<chars.length; i++) {
//            if (chars[i]=='(') open++;
//            if (chars[i]==')' && open>0) {
//                dp[i] = 2+dp[i-1];  // matches found
//                if(i-dp[i]>0)   // add matches from previous
//                    dp[i] += dp[i-dp[i]];
//                open--;
//            }
//            if (dp[i]>max) max = dp[i];
//        }
//        return max;
//    }
//
//    /**TODO 难记; 重温理解及记忆,尤其是代码最后一个else部分
//     * http://www.cnblogs.com/lichen782/p/leetcode_Longest_Valid_Parentheses.html
//     * DP可解,但是大数据超时.
//     * 用栈来存左括号的index，遍历s，遇到'('就放入lefts栈。
//     如果遇到')'，如果lefts是空，说明这是一个无法匹配的')'，记录下last。
//     注意:last里面存放的其实是最后一个无法匹配的')',主要是为了计算后面完整的表达式的长度。
//     可以这样理解：所有无法匹配的')'的index其实都是各个group的分界点。
//     * @param s
//     * @return
//     */
//    public int longestValidParentheses1(String s) {
//        int maxLen = 0, lastNoMatchRight = -1;  //TODO 注意赋值为-1的巧妙处
//        Stack<Integer> lefts = new Stack<>();
//        for (int i = 0; i < s.length(); ++i) {
//            if (s.charAt(i)=='(') lefts.push(i);
//            else {
//                if (lefts.isEmpty()) { // no matching left
//                    lastNoMatchRight = i;
//                } else {  // find a matching pair
//                    lefts.pop();
//                    if (lefts.isEmpty()) { //匹配完一个完整的group,计算该group的长度
//                        maxLen = Math.max(maxLen, i-lastNoMatchRight);
//                    } else { //栈内还有‘(', 通过查询下一个还未匹配的"("的index获取当前长度,并更新maxLen TODO 用例"()(()"
//                        maxLen = Math.max(maxLen, i-lefts.peek());
//                    }
//                }
//            }
//        }
//        return maxLen;
//    }
//
//}
