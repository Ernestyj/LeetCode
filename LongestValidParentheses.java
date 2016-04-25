package leetcode31_40;

import java.util.Stack;

/**
 * Given a string containing just the characters '(' and ')', find the length of
 the longest valid (well-formed) parentheses substring.
 For "(()", the longest valid parentheses substring is "()", which has length = 2.
 Another example is ")()())", where the longest valid parentheses substring is "()()",
 which has length = 4.
 * Created by Eugene on 11/16/2015.
 */
public class LongestValidParentheses {

    public static void main(String[] args){
        int index = new LongestValidParentheses()
                .longestValidParentheses(")))))(((()(");

        System.out.println("*****RESULT*****");
        System.out.println(index);
    }


    /**TODO 重温理解及记忆,尤其是代码最后一个else部分
     * http://www.cnblogs.com/lichen782/p/leetcode_Longest_Valid_Parentheses.html
     * DP可解,但是大数据超时.
     * 用栈来存左括号的index，遍历s，遇到'('就放入lefts栈。
     如果遇到')'，如果lefts是空，说明这是一个无法匹配的')'，记录下last。
     last里面存放的其实是最后一个无法匹配的')',主要是为了计算后面完整的表达式的长度。
     可以这样理解：所有无法匹配的')'的index其实都是各个group的分界点。
     * @param s
     * @return
     */
    public int longestValidParentheses(String s) {
        int maxLen = 0, last = -1;
        Stack<Integer> lefts = new Stack<>();
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i)=='(') {
                lefts.push(i);
            } else {
                if (lefts.isEmpty()) {
                    // no matching left
                    last = i;
                } else {
                    // find a matching pair
                    lefts.pop();
                    if (lefts.isEmpty()) {//有一个完整的valid的group。计算该group的长度
                        maxLen = Math.max(maxLen, i - last);
                    } else {
                        //栈内还有‘(',一个最外层完整的group还没有匹配完成，
                        //但是通过查询下一个即将匹配还未匹配的"("的index来更新maxLen。
                        int k = lefts.peek();
                        maxLen = Math.max(maxLen, i - k);
                    }
                }
            }
        }
        return maxLen;
    }


    /**
     * TODO 用例"()(()" 失败
     * @param s
     * @return
     */
    public int longestValidParentheses1(String s) {
        if (s == null || s.length() == 0 || s.length() == 1) return 0;
        char[] chars = s.toCharArray();
        boolean canAddRight = false;
        int len = 0;
        int tempLen = 0;
        int leftCount = 0;  //TODO 提速（用例："(((((((((((((..."）
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < chars.length && leftCount <= chars.length - i + 1; i++){
            if (chars[i] == '('){
                stack.push(chars[i]);
                leftCount++;
                canAddRight = true;
            }else if (chars[i] == ')' && canAddRight){
                if (!stack.isEmpty() && stack.pop() == '('){
                    leftCount--;
                    tempLen += 2;
                }
                else {
                    canAddRight = false;
                    if (tempLen > len){
                        len = tempLen;
                        tempLen = 0;
                        leftCount = 0;
                    }
                }
            }
        }
        if (tempLen > len){
            len = tempLen;
        }
        return len;
    }


}
