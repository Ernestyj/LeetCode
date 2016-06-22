package leetcode261_270;

/**Write a program to check whether a given number is an ugly number.
 Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
 For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
 Note that 1 is typically treated as an ugly number.
 * Created by eugene on 16/5/14.
 */
public class UglyNumber {

    /**简洁
     * Just divide by 2, 3 and 5 as often as possible and then check whether we arrived at 1.
     Also try divisor 4 if that makes the code simpler / less repetitive.
     * @param num
     * @return
     */
    public boolean isUgly1(int num) {
        if (num<=0) return false;
        for (int i=2; i<6; i++){    //2,3,4,5
            while (num%i==0) num /= i;
        }
        return num==1;
    }

    //易于理解:尽可能将num依次被2,3,5除尽,检测结果是否为1.
    public boolean isUgly(int num) {
        if(num==1) return true;
        if(num==0) return false;
        while(num%2==0) num /= 2;
        while(num%3==0) num /= 3;
        while(num%5==0) num /= 5;
        return num==1;
    }

}
