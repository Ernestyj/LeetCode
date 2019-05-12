
/**
 * Given two binary strings, return their sum (also a binary string).
 For example,
 a = "11"
 b = "1"
 Return "100".
 * Created by DCLab on 12/19/2015.
 */
class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int i = a.size()-1, j = b.size()-1, carry = 0;
        while(i>=0 || j>=0){
            int sum = carry;
            if(i>=0) sum += a[i--] - '0';
            if(j>=0) sum += b[j--] - '0';
            result = to_string(sum%2) + result;//TODO 注意类型转换
            carry = sum/2;
        }
        return carry!=0 ? "1"+result : result;
    }
};

//public class AddBinary {
//
//    //简洁代码, Computation from string usually can be simplified by using a carry as such
//    public String addBinary(String a, String b) {
//        StringBuilder sb = new StringBuilder();
//        int i = a.length()-1, j = b.length()-1, carry = 0;
//        while (i>=0 || j>=0) {
//            int sum = carry;
//            if (i>=0) sum += a.charAt(i--)-'0';
//            if (j>=0) sum += b.charAt(j--)-'0';
//            sb.append(sum % 2);
//            carry = sum / 2;
//        }
//        if (carry!=0) sb.append(carry);
//        return sb.reverse().toString();
//    }
//
//}
