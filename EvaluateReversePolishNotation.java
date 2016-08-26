package leetcode141_150;

import java.util.LinkedList;
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
        LinkedList<Integer> stack = new LinkedList<>();
        for(String s: tokens){
            if(s.equals("+")) stack.push(stack.pop()+stack.pop());
            else if(s.equals("-")) stack.push(-stack.pop()+stack.pop());
            else if(s.equals("*")) stack.push(stack.pop()*stack.pop());
            else if(s.equals("/")) {
                int x = stack.pop();
                stack.push(stack.pop()/x);
            }
            else stack.push(Integer.valueOf(s));
        }
        return stack.pop();
    }

}
