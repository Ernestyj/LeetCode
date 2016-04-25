package leetcode41_50;

import java.math.BigInteger;

/**
 * Given two numbers represented as strings, return multiplication of the numbers as a string.
 Note: The numbers can be arbitrarily large and are non-negative.
 * Created by DCLab on 11/26/2015.
 */
public class MultiplyStrings {

    public static void main(String[] args) {
        System.out.println(new MultiplyStrings().multiply("1", "1"));
    }


    /**
     * http://www.cnblogs.com/TenosDoIt/p/3735309.html
     * 首先我们把每一位相乘，得到一个没有进位的临时结果，然后把临时结果从低位起依次进位。
     * 对于一个m位整数乘以n位整数的结果，最多只有m+n位。
     * @param num1
     * @param num2
     * @return
     */
    public String multiply(String num1, String num2) {
        if (num1.equals("0") || num2.equals("0")) return "0";
        char[] l = new StringBuilder(num1).reverse().toString().toCharArray();
        char[] r = new StringBuilder(num2).reverse().toString().toCharArray();
        int[] ints = new int[num1.length() + num2.length()];
        for (int i = 0; i < num1.length(); i++){
            for (int j = 0; j < num2.length(); j++){
                ints[i + j] += (l[i] - '0') * (r[j] - '0');
            }
        }
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < ints.length; i++){
            builder.append(ints[i] % 10);
            if (i + 1 < ints.length) ints[i + 1] += ints[i] / 10;
        }
        //TODO 下面两行操作不必要(开辟m+n长度数组足以存储所有进位)
//        int temp = ints[ints.length - 1] / 10;
//        if (temp != 0) builder.append(temp);
        if (builder.charAt(ints.length - 1) == '0') builder.deleteCharAt(ints.length - 1);
        return builder.reverse().toString();
    }


    public String multiply2(String num1, String num2) {
        BigInteger i = new BigInteger(num1);
        BigInteger j = new BigInteger(num2);
        return i.multiply(j).toString();
    }


    /**笨重方法
     * 乘法：用较小数的各个位乘以（累加）较大数，同时对高位补零，再求和；
     * @param num1
     * @param num2
     * @return
     */
    public String multiply1(String num1, String num2) {
        if (num1.equals("0") || num2.equals("0")) return "0";
        if(!isGreater(num1, num2)){
            String temp = num1; num1 = num2; num2 = temp;
        }
        String result = "";
        String temp = num1;
        for (int i = num2.length() - 1; i >= 0; i--){  //从低位开始叠加
            for (int j = 0; j < num2.charAt(i) - '0'; j++)
                result = positiveAdd(result, temp);
            temp = new StringBuilder(temp).append('0').toString();  //补零
        }
        return result;
    }
    private String positiveAdd(String left, String right) {
        //字符填充
        int lengthDiff = Math.abs(left.length() - right.length());
        if(left.length() < right.length()){
            left = zeroPopulatedString(left, lengthDiff);
        }
        else if(left.length() > right.length()){
            right = zeroPopulatedString(right, lengthDiff);
        }
        StringBuilder result = new StringBuilder();
        int carryVal = 0;   //进位值
        for (int i = left.length() - 1; i >= 0; i--){   //从低位开始处理
            int temp = left.charAt(i) - '0' + right.charAt(i) - '0' + carryVal;    //对应位相加（含进位值）
            if (i == 0){    //最高位
                result.append(temp % 10)    //当前位
                        .append((temp / 10) == 0 ? "" : temp / 10); //最高位的进位值
            }else {
                result.append(temp % 10);   //当前位
                carryVal = temp / 10;   //进位值更新
            }
        }
        return trimZeroPopulatedString(result.reverse().toString());
    }
    private boolean isGreater(String left, String right){
        if(left.length() > right.length()) return true;
        else if(left.length() < right.length()) return false;
        else {
            for(int i = 0; i < left.length(); i++){
                if(left.charAt(i) > right.charAt(i)) return true;
                else if(left.charAt(i) < right.charAt(i)) return false;
            }
            return true;
        }
    }
    private String trimZeroPopulatedString(String valString){
        if ("0".equals(valString)) return "0";
        int i = 0;
        for ( ; i < valString.length() && valString.charAt(i) == '0'; i++);
        String result = valString.substring(i);
        //在除法中可能会遇到操作数为“000”的情况，此时需要统一返回“0”，而不是空串
        return  result.length() == 0 ? "0" : result;
    }
    private String zeroPopulatedString(String valString, int length){
        StringBuilder stringBuilder = new StringBuilder();
        for (int i = 0; i < length; i++) stringBuilder.append('0');
        return stringBuilder.append(valString).toString();
    }
}
