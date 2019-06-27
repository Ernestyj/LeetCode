
/**
 * Additive number is a string whose digits can form additive sequence.
A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.
Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.
Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.
Example 1:
Input: "112358"
Output: true
Explanation: The digits can form an additive sequence: 1, 1, 2, 3, 5, 8.
             1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
Example 2:
 Input: "199100199"
Output: true
Explanation: The additive sequence is: 1, 99, 100, 199.
             1 + 99 = 100, 99 + 100 = 199
Follow up:
How would you handle overflow for very large input integers?
 */
class Solution {
public:
    bool isAdditiveNumber(string num) {//Brute Force 确定了头部相加情况，后面的相加情况就确定了
        for (int i = 1; i < num.size(); ++i) {    //i表示s1末尾后一位，j表示s2末尾后一位
            string s1 = num.substr(0, i);
            if(s1.size()>1 && s1[0]=='0') break;
            for (int j = i+1; j < num.size(); ++j) {
                string s2 = num.substr(i, j-i);
                if(s2.size()>1 && s2[0]=='0') break;
                long long d1 = stoll(s1), d2 = stoll(s2), next = d1+d2;
                string nextStr = to_string(next);
                if(nextStr!=num.substr(j, nextStr.size())) continue; //优化
                string allStr = s1+s2+nextStr;
                while (allStr.size()<num.size()){
                    d1 = d2;
                    d2 = next;
                    next = d1+d2;
                    nextStr = to_string(next);
                    allStr += nextStr;
                }
                if(allStr==num) return true;
            }
        }
        return false;
    }
};
//public class Solution {
//public boolean isAdditiveNumber(String num) {
//        int len = num.length();
//        for (int i=1; i<=len/2; ++i)    //TODO i,j表示长度
//            for (int j=1; Math.max(j, i) <= len-i-j; ++j)   //TODO 和的长度限制tricky
//                if (isValid(i, j, num)) return true;
//        return false;
//    }
//private boolean isValid(int i, int j, String num) {
//        if (num.charAt(0)=='0' && i>1) return false;
//        if (num.charAt(i)=='0' && j>1) return false;
//        String sum;
//        Long x1 = Long.parseLong(num.substring(0, i));
//        Long x2 = Long.parseLong(num.substring(i, i+j));
//        for (int start = i+j; start!=num.length(); start += sum.length()) {
//            x2 = x2+x1;
//            x1 = x2-x1;
//            sum = x2.toString();
//            if (!num.startsWith(sum, start)) return false;
//        }
//        return true;
//    }
//}