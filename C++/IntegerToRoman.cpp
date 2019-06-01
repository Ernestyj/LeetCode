
/**Given an integer, convert it to a roman numeral.
 Input is guaranteed to be within the range from 1 to 3999.
 * Created by eugene on 16/6/1.
 */
class Solution {
public:
    string intToRoman(int num) {
        vector<string> I = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        vector<string> X = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> C = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> M = {"", "M", "MM", "MMM"};
        return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
    }
};
//public class IntegerToRoman {
//
//    //https://leetcode.com/discuss/32626/simple-solution
//    public static String intToRoman(int num) {
//        String M[] = {"", "M", "MM", "MMM"};
//        String C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
//        String X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
//        String I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
//        return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
//    }
//
//    //https://leetcode.com/discuss/49870/my-java-solution-easy-to-understand
//    public String intToRoman1(int num) {
//        int[] values = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
//        String[] strs = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
//        StringBuilder sb = new StringBuilder();
//        for(int i=0;i<values.length;i++) {
//            while(num >= values[i]) {
//                num -= values[i];
//                sb.append(strs[i]);
//            }
//        }
//        return sb.toString();
//    }
//
//}
