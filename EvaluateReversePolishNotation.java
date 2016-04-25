package leetcode141_150;

import java.util.Stack;

/**Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 Some examples:
 ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 * Created by eugene on 16/3/9.
 */
public class EvaluateReversePolishNotation {

    public int evalRPN(String[] tokens) {
        Stack<String> stack = new Stack<>();
        stack.push(tokens[0]);
        for (int i=1; i<tokens.length; i++){
            if (!isOperator(tokens[i])) stack.push(tokens[i]);
            else {
                char c = tokens[i].charAt(0);
                int y = Integer.valueOf(stack.pop());
                int x = Integer.valueOf(stack.pop());
                stack.push(String.valueOf(calculate(x, y, c)));
            }
        }
        return Integer.valueOf(stack.pop());
    }
    private boolean isOperator(String s){
        if (s.length()>1) return false;
        char c = s.charAt(0);
        if ('0'<=c && c<='9') return false;
        else return true;
    }
    private int calculate(int x, int y, char c){
        switch (c){
            case '+': return x+y;
            case '-': return x-y;
            case '*': return x*y;
            case '/': return x/y;
            default: return 0;
        }
    }

}
