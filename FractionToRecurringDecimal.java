package leetcode161_170;

import java.util.HashMap;
import java.util.Map;

/**Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
 If the fractional part is repeating, enclose the repeating part in parentheses.
 For example,
 Given numerator = 1, denominator = 2, return "0.5".
 Given numerator = 2, denominator = 1, return "2".
 Given numerator = 2, denominator = 3, return "0.(6)".
 * Created by eugene on 16/3/18.
 */
public class FractionToRecurringDecimal {

    public static void main(String[] args) {
        System.out.println(new FractionToRecurringDecimal().fractionToDecimal(13,97));
    }

    //http://www.programcreek.com/2014/03/leetcode-fraction-to-recurring-decimal-java/
    public String fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        if (denominator == 0) return "";
        StringBuilder builder = new StringBuilder();
        if ((numerator < 0) ^ (denominator < 0)) {
            builder.append("-");
        }
        long num = numerator, den = denominator;
        num = Math.abs(num);
        den = Math.abs(den);
        long quitient = num / den;   //商
        builder.append(String.valueOf(quitient));
        long remainder = (num % den) * 10;  //余数
        if (remainder == 0) return builder.toString();
        Map<Long, Integer> remainderToPos = new HashMap<>();
        builder.append(".");
        while (remainder!=0){
            if (remainderToPos.containsKey(remainder)){
                int beg = remainderToPos.get(remainder);
                String part1 = builder.substring(0, beg);
                String part2 = builder.substring(beg, builder.length());
                return part1 + "(" + part2 + ")";
            }
            remainderToPos.put(remainder, builder.length());
            quitient = remainder/den;
            builder.append(String.valueOf(quitient));
            remainder = (remainder%den)*10; //TODO 注意要乘以10
        }
        return builder.toString();
    }

}
