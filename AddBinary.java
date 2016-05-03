package leetcode61_70;

import java.util.Arrays;

/**
 * Given two binary strings, return their sum (also a binary string).
 For example,
 a = "11"
 b = "1"
 Return "100".
 * Created by DCLab on 12/19/2015.
 */
public class AddBinary {

    public static void main(String[] args) {
        System.out.println("*****RESULT*****");
        System.out.println(new AddBinary().addBinary("11", "1"));
    }

    //简洁代码, Computation from string usually can be simplified by using a carry as such
    public String addBinary(String a, String b) {
        StringBuilder sb = new StringBuilder();
        int i = a.length()-1, j = b.length()-1, carry = 0;
        while (i>=0 || j>=0) {
            int sum = carry;
            if (j>=0) sum += b.charAt(j--) - '0';
            if (i>=0) sum += a.charAt(i--) - '0';
            sb.append(sum % 2);
            carry = sum / 2;
        }
        if (carry != 0) sb.append(carry);
        return sb.reverse().toString();
    }

    //TODO int与char转换过程易出错
    public String addBinary1(String a, String b) {
        int aLen = a.length(), bLen = b.length();
        int len = aLen > bLen ? aLen : bLen;
        char[] aChars, bChars;
        char[] res = new char[len + 1];
        if (len == aLen){
            aChars = a.toCharArray();
            bChars = new char[len];
            int diff = len-bLen;
            for (int i=0; i<len; i++){
                if (i<diff) bChars[i] = '0';
                else bChars[i] = b.charAt(i-diff);
            }
        } else {
            aChars = new char[len];
            int diff = len-aLen;
            for (int i = 0; i<len; i++){
                if (i<diff) aChars[i] = '0';
                else aChars[i] = a.charAt(i-diff);
            }
            bChars = b.toCharArray();
        }
        int temp = 0, extra = 0;
        for (int i = len-1; i>=0; i--){
            temp = getInt(aChars[i]) + getInt(bChars[i]) + extra;
            res[i+1] = getChar(temp%2); //TODO i+1易出错
            extra = temp/2;
            if (temp>1 && i-1 == -1) { //超出长度
                res[0] = '1';
                return new String(res);
            }
        }
        return new String(Arrays.copyOfRange(res, 1, len+1));   //TODO i+1易出错
    }
    private int getInt(char c){
        if (c == '0') return 0;
        else return 1;
    }
    private char getChar(int i){
        if (i == 0) return '0';
        else return '1';
    }

}
