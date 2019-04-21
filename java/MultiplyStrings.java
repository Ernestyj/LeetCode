package leetcode41_50;

import java.math.BigInteger;

/**
 * Given two numbers represented as strings, return multiplication of the numbers as a string.
 Note: The numbers can be arbitrarily large and are non-negative.
 * Created by DCLab on 11/26/2015.
 */
public class MultiplyStrings {

    /**
     * http://www.cnblogs.com/TenosDoIt/p/3735309.html
     * 从个位起,我们把每一位相乘，得到一个没有进位的临时结果，然后把临时结果从低位起依次进位。
     * 对于一个m位整数乘以n位整数的结果，最多只有m+n位。
     * @param num1
     * @param num2
     * @return
     */
    public String multiply(String num1, String num2) {
        if (num1.equals("0") || num2.equals("0")) return "0";
        char[] l = new StringBuilder(num1).reverse().toString().toCharArray();
        char[] r = new StringBuilder(num2).reverse().toString().toCharArray();
        int[] nums = new int[l.length + r.length];
        for (int i=0; i<l.length; i++){
            for (int j=0; j<r.length; j++){
                nums[i+j] += (l[i]-'0') * (r[j]-'0');
            }
        }
        StringBuilder builder = new StringBuilder();
        for (int i=0; i<nums.length; i++){
            builder.append(nums[i] % 10);
            if (i+1<nums.length) nums[i+1] += nums[i]/10;
        }
        //TODO 注意删除最后的0
        if (builder.charAt(nums.length-1)=='0') builder.deleteCharAt(nums.length-1);
        return builder.reverse().toString();
    }


    /**https://leetcode.com/discuss/71593/easiest-java-solution-with-graph-explanation
     * 简洁. TODO 此法利用i,j位两数相乘后结果位置为[i+j, i+j+1]的规律.
     * @param num1
     * @param num2
     * @return
     */
    public String multiply1(String num1, String num2) {
        int m = num1.length(), n = num2.length();
        int[] pos = new int[m+n];
        for(int i = m-1; i>=0; i--) {
            for(int j = n-1; j>=0; j--) {
                int mult = (num1.charAt(i)-'0') * (num2.charAt(j)-'0');
                int p1 = i+j, p2 = i+j+1;
                int sum = mult+pos[p2];
                pos[p1] += sum/10;
                pos[p2] = sum%10;
            }
        }
        StringBuilder sb = new StringBuilder();
        for(int p : pos) if(!(sb.length()==0 && p==0)) sb.append(p);
        return sb.length()==0? "0" : sb.toString();
    }

}
