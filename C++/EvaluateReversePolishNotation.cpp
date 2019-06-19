
/**Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 Some examples:
 ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 * Created by eugene on 16/3/9.
 */
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(auto s: tokens){
            if(!(s=="+" || s=="-" || s=="*" || s=="/")){
                stk.push(stoi(s));
            }else{
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                if(s=="+") stk.push(a+b);
                else if(s=="-") stk.push(-a+b);
                else if(s=="*") stk.push(a*b);
                else if(s=="/") stk.push(b/a);
            }
        }
        return stk.top();
    }
};
//public class EvaluateReversePolishNotation {
//
//    public int evalRPN(String[] tokens) {
//        LinkedList<Integer> stack = new LinkedList<>();
//        for(String s: tokens){
//            if(s.equals("+")) stack.push(stack.pop()+stack.pop());
//            else if(s.equals("-")) stack.push(-stack.pop()+stack.pop());
//            else if(s.equals("*")) stack.push(stack.pop()*stack.pop());
//            else if(s.equals("/")) {
//                int x = stack.pop();
//                stack.push(stack.pop()/x);
//            }
//            else stack.push(Integer.valueOf(s));
//        }
//        return stack.pop();
//    }
//
//}
