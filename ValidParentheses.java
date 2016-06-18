package leetcode11_20;


import java.util.Stack;

/**
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
 * determine if the input string is valid.

 The brackets must close in the correct order, "()" and "()[]{}" are all valid
 but "(]" and "([)]" are not.
 *
 * Created by DCLab on 11/3/2015.
 */
public class ValidParentheses {

    //巧妙法,但速度很慢
    public boolean isValid(String s) {
        int preLen = -1;
        while (preLen!=s.length()){
            preLen = s.length();
            s = s.replace("()", "").replace("{}", "").replace("[]", "");
        }
        return s.length()==0;
    }

    public boolean isValid1(String s) {
        Stack<Character> stack = new Stack<>();
        char c;
        for (int i = 0; i < s.length(); i++){
            c = s.charAt(i);
            switch (c){
                case '(':
                case '[':
                case '{':
                    stack.push(c);
                    break;
                case ')':   //TODO 判空易漏（短路求值）
                    if (stack.isEmpty() || stack.pop() != '(') return false;
                    break;
                case ']':
                    if (stack.isEmpty() || stack.pop() != '[') return false;
                    break;
                case '}':
                    if (stack.isEmpty() || stack.pop() != '{') return false;
                    break;
                default:
                    break;
            }
        }
        return stack.isEmpty(); //TODO 易漏 如"("这种情况应排除
    }

}
