
/**Divide two integers without using multiplication, division and mod operator.
 If it is overflow, return MAX_INT.
 Integer.MIN_VALUE = -2147483648
 Integer.MAX_VALUE = 2147483647
 Note:
Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1].
For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.
 * Created by DCLab on 11/12/2015.
 */
class Solution {
public:
    int divide(int dividend, int divisor) { //TODO 此题极其注意overflow
        if(divisor==0 || dividend==INT_MIN && divisor==-1) return INT_MAX;
        int sign = (dividend>0)^(divisor>0)? -1 : 1;
        long long res = 0, a = abs((long long)dividend), b = abs((long long)divisor);//TODO long和int在某些编译器下大小一样
        while (b<=a){
            long sumup = b, stride = 1;
            while (sumup<<1 <=a){
                sumup <<= 1;
                stride <<= 1;
            }
            a -= sumup;
            res += stride;
        }
        return sign==1? res : -res;
    }
};
class Solution {
public:
    int divide(int dividend, int divisor) { //TODO 此题极其注意overflow
        if(divisor==0 || dividend==INT_MIN && divisor==-1) return INT_MAX;  //TODO 后面这种情况勿漏
        int sign = (dividend>0)^(divisor>0)==1? -1:1;
        long result = 0, a = abs((long)dividend), b = abs((long)divisor), stride = 1, sumup = b; //TODO abs里面强转成long
        while(a>=b){
            stride = 1;
            sumup = b;
            while(sumup<<1 <=a){
                sumup <<= 1;
                stride <<= 1;
            }
            result += stride;   //TODO 注意+=的是stride而不是sumup
            a -= sumup;
        }
        return sign==1? result:-result;
    }
};
//public class DivideTwoIntegers {
//
//    //简洁
//    public int divide(int dividend, int divisor) {
//        if(divisor==0 || dividend==Integer.MIN_VALUE && divisor==-1) return Integer.MAX_VALUE;
//        int res = 0;
//        int sign = (dividend<0)^(divisor<0)? -1 : 1;
//        long a = Math.abs((long)dividend), b = Math.abs((long)divisor);
//        while(b<=a){
//            long sum = b, multiple = 1;
//            while(sum<<1 <= a){
//                sum <<= 1;
//                multiple <<= 1;//moving with stride 1, 2, 4, 8, 16...2^n for performance reason.
//            }
//            a -= sum;
//            res += multiple;
//        }
//        return sign==1? res : -res;
//    }
//
//    //上面解法的递归版本
//    public int divide0(int dividend, int divisor) {
//        int sign = 1;
//        if ((dividend^divisor)>0) sign = -1;
//        long a = Math.abs((long) dividend), b = Math.abs((long) divisor);
//        if (b == 0) return Integer.MAX_VALUE;//Take care the edge cases.
//        if ((a == 0) || (a < b)) return 0;
//        long ans = ldivide(a, b);
//        int res;
//        if (ans>Integer.MAX_VALUE) res = (sign==1)?Integer.MAX_VALUE : Integer.MIN_VALUE;
//        else res = (int)(sign==1? ans : -ans);
//        return res;
//    }
//    private long ldivide(long a, long b) {//  Think this as a binary search.
//        if (a < b) return 0;
//        long sum = b;
//        long multiple = 1;
//        while (sum+sum<=a) {
//            sum += sum;
//            multiple += multiple;//moving with stride 1, 2, 4, 8, 16...2^n for performance reason.
//        }
//        return multiple + ldivide(a - sum, b);
//    }
//
//    /**http://www.programcreek.com/2014/05/leetcode-divide-two-integers-java/
//     * 任何一个整数可以表示成以2的幂为底的一组基的线性组合，即num=a0*2^0+a1*2^1+a2*2^2+...+an*2^n。
//     * 基于以上这个公式以及左移一位相当于乘以2，我们先让除数左移直到大于被除数之前得到一个最大的基。
//     * 然后接下来我们每次尝试减去这个基，如果可以则结果增加2^k,然后基继续右移迭代，直到基为0为止。
//     * 因为这个方法的迭代次数是按2的幂直到超过结果，所以时间复杂度为O(logn)。
//     */
//    public int divide1(int dividend, int divisor) {
//        //handle special cases
//        if(divisor==0) return Integer.MAX_VALUE;
//        if(divisor==-1 && dividend == Integer.MIN_VALUE) return Integer.MAX_VALUE;
//        //get positive values
//        long a = Math.abs((long)dividend);
//        long b = Math.abs((long)divisor);
//
//        int result = 0;
//        while(a>=b){
//            //calculate number of left shifts
//            int numShift = 0;
//            while(a>=(b<<numShift)){
//                numShift++;
//            }
//            //dividend minus the largest shifted divisor
//            result += 1<<(numShift-1);
//            a -= (b<<(numShift-1));
//        }
//        if((dividend>0 && divisor>0) || (dividend<0 && divisor<0)) return result;
//        else return -result;
//    }
//
//}
