package leetcode61_70;

import java.util.Arrays;
import java.util.List;

/**
 * Given a non-negative number represented as an array of digits, plus one to the number.
 The digits are stored such that the most significant digit is at the head of the list.
 大数加1
 * Created by DCLab on 12/19/2015.
 */
public class PlusOne {

    public static void main(String[] args) {
        System.out.println("*****RESULT*****");
        System.out.println();
    }

    /**https://leetcode.com/discuss/58149/my-simple-java-solution
     * 简洁, 巧妙
     * @param digits
     * @return
     */
    public int[] plusOne(int[] digits) {
        int n = digits.length;
        for(int i=n-1; i>=0; i--) {
            if(digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        int[] newRes = new int [n+1];
        newRes[0] = 1;
        return newRes;
    }


    public int[] plusOne1(int[] digits) {
        if (digits == null || digits.length == 0) return new int[0];
        int len = digits.length;
        int extra = 1, temp = 0;
        for (int i = len-1; i >= 0; i--){
            temp = digits[i] + extra;
            digits[i] = temp%10;
            extra = temp/10;
            if (temp>9 && i-1 == -1){ //超出长度
                int[] newRes = new int[len+1];
                newRes[0] = extra;  //TODO 因为只是加一操作，其余位一定是0，否则不会进最高位
                return newRes;
            }
        }
        return digits;
    }

}
