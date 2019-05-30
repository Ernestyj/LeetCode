package leetcode1_10;

/**Implement atoi to convert a string to an integer.
 Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
 Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
 * Created by eugene on 16/4/20.
 */
class Solution {
public:
    int myAtoi(string str) {

    }
};
//public class StringToInteger {
//
//    /**TODO 此题用例极易出错,注意各种条件
//     * https://leetcode.com/discuss/32813/java-solution-with-4-steps-explanations
//     * @param str
//     * @return
//     */
//    public int myAtoi(String str) {
//        int i = 0, sign = 1;
//        long total = 0; //TODO 使用long
//        if(str.length()==0) return 0;
//        while(str.charAt(i)==' ' && i<str.length()) i++;    //1. Remove Spaces
//        if(str.charAt(i)=='+' || str.charAt(i)=='-'){   //2. Handle signs
//            sign = str.charAt(i)=='+' ? 1 : -1;
//            i++;
//        }
//        while(i<str.length()){  //3. Convert number and avoid overflow
//            int digit = str.charAt(i)-'0';
//            if(digit<0 || digit>9) break;
//            total = 10*total + digit;
//            if (total*sign>=Integer.MAX_VALUE) return Integer.MAX_VALUE;    //4. Check
//            else if (total*sign<=Integer.MIN_VALUE) return Integer.MIN_VALUE;
//            i++;
//        }
//        return (int)total*sign;
//    }
//
//    //TODO 此法失败用例:9223372036854775809应返回Integer.MAX_VALUE,而不是0
//    public int myAtoi1(String str) {
//        if (str.length()==0) return 0;
//        StringBuilder builder = new StringBuilder();
//        boolean ignoreBlank = true;
//        for (int i=0; i<str.length(); i++){
//            while (ignoreBlank && str.charAt(i)==' '){
//                i++;
//            }
//            ignoreBlank = false;
//            char c = str.charAt(i);
//            if (Character.isDigit(c) || c=='-' || c=='+') builder.append(c);
//            else break;  //TODO "  -0012a42"返回-12
//        }
//        String s = builder.toString();
//        double d;
//        try {
//            d = Long.valueOf(s);
//        } catch (NumberFormatException ex){
//            return 0;
//        }
//        if (d>Integer.MAX_VALUE) return Integer.MAX_VALUE;
//        else if (d<Integer.MIN_VALUE) return Integer.MIN_VALUE;
//        else return (int)d;
//    }
//
//}
