package leetcode11_20;


import java.util.LinkedList;
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
        LinkedList<Character> stack = new LinkedList<>();
        for(char c: s.toCharArray()){
            switch(c){
                case '(': case '[': case '{': stack.push(c); break;
                case ')': if(stack.isEmpty() || stack.pop()!='(') return false; break; //TODO 判空易漏（短路求值）
                case ']': if(stack.isEmpty() || stack.pop()!='[') return false; break;
                case '}': if(stack.isEmpty() || stack.pop()!='{') return false; break;
            }
        }
        return stack.isEmpty(); //TODO 易漏 如"("这种情况应排除
    }

}
