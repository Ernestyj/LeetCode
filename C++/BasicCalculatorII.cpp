
/**Implement a basic calculator to evaluate a simple expression string.
 The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.
 You may assume that the given expression is always valid.
 Some examples:
 "3+2*2" = 7
 " 3/2 " = 1
 " 3+5 / 2 " = 5
 * Created by eugene on 16/4/22.
 */
class Solution {
public:
    int calculate(string s) {
        if(s.empty()) return 0;
        stack<int> stk;
        long long num = 0, res = 0; //注意要用long long防止溢出
        int lastSign = '+';
        for (int i = 0; i < s.size(); ++i) {
            if(isdigit(s[i])) num = num*10 + s[i]-'0';
            if((!isdigit(s[i])&&s[i]!=' ') || i==s.size()-1){//注意别漏了到末尾的情况, TODO 注意这里不能用else if，否则末尾情况会被跳过
                if(lastSign=='-') stk.push(-num);
                else if(lastSign=='+') stk.push(num);
                else if(lastSign=='*' || lastSign=='/') {
                    int temp = lastSign=='*'? stk.top()*num : stk.top()/num;
                    stk.pop();
                    stk.push(temp);
                }
                lastSign = s[i];
                num = 0;
            }
        }
        while(!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};
//public class BasicCalculatorII {
//    /**
//     *https://leetcode.com/discuss/41902/share-my-java-solution
//     *遇到数字则读完数字,遇到符号或到了末尾则检视上一次符号lastSign:lastSign为'-''+'则相应压栈;
//     lastSign为'*''/'则弹栈与当前数计算后压栈;此外更新lastSign,当前值清零.
//     最后,求栈中元素和返回.
//     */
//    public int calculate(String s) {
//        if (s==null) return 0;
//        int len = s.length();
//        if(len==0) return 0;
//        Stack<Integer> stack = new Stack<>();
//        int num = 0;    //初始值
//        char lastSign = '+';    //初始符号
//        for(int i=0;i<len;i++){
//            char c = s.charAt(i);
//            if(Character.isDigit(c)) num = num*10+c-'0';
//            if((!Character.isDigit(c) && ' '!=c) || i==len-1){  //TODO 注意到了末尾的情况
//                if(lastSign=='-') stack.push(-num);
//                if(lastSign=='+') stack.push(num);
//                if(lastSign=='*') stack.push(stack.pop()*num);
//                if(lastSign=='/') stack.push(stack.pop()/num);
//                lastSign = c;
//                num = 0;
//            }
//        }
//        int res = 0;
//        for(int i: stack) res += i;
//        return res;
//    }
//
//}
