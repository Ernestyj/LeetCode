
/**Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
 If the fractional part is repeating, enclose the repeating part in parentheses.
 For example,
 Given numerator = 1, denominator = 2, return "0.5".
 Given numerator = 2, denominator = 1, return "2".
 Given numerator = 2, denominator = 3, return "0.(6)".
 * Created by eugene on 16/3/18.
 */
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0) return "0";
        long long num = abs((long long)numerator), den = abs((long long)denominator);
        long long integral = num/den, remain = num%den;
        string res = to_string(integral);
        if((numerator<0)^(denominator<0)) res = "-"+res;
        if(remain==0) return res;
        // fractional part
        res += ".";
        string frac = "";
        unordered_map<long long, int> m;
        int pos = 0;
        while (remain){
            if(m.find(remain) != m.end()){  // find reoccurring
                frac.insert(m[remain], "(");
                frac += ")";
                return res+frac;
            }else{
                m[remain] = pos++;
            }
            frac += to_string((remain*10)/den);
            remain = (remain*10)%den;
        }
        return res+frac;
    }
};
//public class FractionToRecurringDecimal {
//
//    //https://leetcode.com/discuss/23079/my-clean-java-solution
//    public String fractionToDecimal(int numerator, int denominator) {
//        if (numerator == 0) return "0";
//        if (denominator == 0) return "";
//        StringBuilder res = new StringBuilder();
//        if ((numerator<0) ^ (denominator<0)) res.append("-");
//        long num = numerator, den = denominator;    //TODO 使用long防止溢出
//        num = Math.abs(num);
//        den = Math.abs(den);
//        // integral part
//        res.append(num/den);
//        num %= den;
//        if (num==0) return res.toString();
//        // fractional part
//        res.append(".");
//        HashMap<Long, Integer> numToPos = new HashMap<>();
//        numToPos.put(num, res.length());
//        while (num!=0) {
//            num *= 10;  //TODO 注意要乘以10
//            res.append(num/den);
//            num %= den;
//            if (numToPos.containsKey(num)) {
//                int index = numToPos.get(num);
//                res.insert(index, "(");
//                res.append(")");
//                break;
//            } else {
//                numToPos.put(num, res.length());
//            }
//        }
//        return res.toString();
//    }
//
//}
