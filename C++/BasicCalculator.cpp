
/**Implement a basic calculator to evaluate a simple expression string.
 The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .
 You may assume that the given expression is always valid.
 Some examples:
 "1 + 1" = 2
 " 2-1 + 2 " = 3
 "(1+(4+5+2)-3)+(6+8)" = 23
 Note: Do not use the eval built-in library function.
 * Created by eugene on 16/4/18.
 */
class Solution {
public:
    int calculate(string s) {
        int res = 0, sign = 1, n = s.size();
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c >= '0') {
                int num = 0;
                while (i < n && s[i] >= '0') {
                    num = 10 * num + (s[i++] - '0');
                }
                res += sign * num;
                --i;
            } else if (c == '+') {
                sign = 1;
            } else if (c == '-') {
                sign = -1;
            } else if (c == '(') {
                stk.push(res);
                stk.push(sign);
                res = 0;
                sign = 1;
            } else if (c == ')') {
                res *= stk.top(); stk.pop();//sign
                res += stk.top(); stk.pop();//res
            }
        }
        return res;
    }
};
//public class BasicCalculator {
//
//    /**
//     * https://leetcode.com/discuss/39553/iterative-java-solution-with-stack
//     * 遇到"+"或"-"改变符号,遇到数字则读完数字并利用符号进行运算,遇到"("压栈结果与符号并重置结果与符号,遇到")"弹栈并计算结果.
//     */
//    public static int calculate(String s) {
//        int sign = 1, result = 0;
//        Stack<Integer> stack = new Stack<>();
//        for (int i=0; i<s.length(); i++) {
//            if (Character.isDigit(s.charAt(i))) {
//                int sum = s.charAt(i)-'0';
//                while (i+1<s.length() && Character.isDigit(s.charAt(i+1))) {
//                    sum = sum*10 + s.charAt(i+1)-'0';
//                    i++;
//                }
//                result += sum*sign;
//            } else if (s.charAt(i) == '+')
//                sign = 1;
//            else if (s.charAt(i) == '-')
//                sign = -1;
//            else if (s.charAt(i) == '(') {
//                stack.push(result);
//                stack.push(sign);
//                result = 0;
//                sign = 1;
//            } else if (s.charAt(i) == ')') {
//                result = result*stack.pop() + stack.pop();
//            }
//        }
//        return result;
//    }
//
//}
