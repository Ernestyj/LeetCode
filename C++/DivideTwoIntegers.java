package leetcode21_30;

/**Divide two integers without using multiplication, division and mod operator.
 If it is overflow, return MAX_INT.
 Integer.MIN_VALUE = -2147483648
 Integer.MAX_VALUE = 2147483647
 * Created by DCLab on 11/12/2015.
 */
public class DivideTwoIntegers {

    //简洁
    public int divide(int dividend, int divisor) {
        if(divisor==0 || dividend==Integer.MIN_VALUE && divisor==-1) return Integer.MAX_VALUE;
        int res = 0;
        int sign = (dividend<0)^(divisor<0)? -1 : 1;
        long a = Math.abs((long)dividend), b = Math.abs((long)divisor);
        while(b<=a){
            long sum = b, multiple = 1;
            while(sum<<1 <= a){
                sum <<= 1;
                multiple <<= 1;//moving with stride 1, 2, 4, 8, 16...2^n for performance reason.
            }
            a -= sum;
            res += multiple;
        }
        return sign==1? res : -res;
    }

    //上面解法的递归版本
    public int divide0(int dividend, int divisor) {
        int sign = 1;
        if ((dividend^divisor)>0) sign = -1;
        long a = Math.abs((long) dividend), b = Math.abs((long) divisor);
        if (b == 0) return Integer.MAX_VALUE;//Take care the edge cases.
        if ((a == 0) || (a < b)) return 0;
        long ans = ldivide(a, b);
        int res;
        if (ans>Integer.MAX_VALUE) res = (sign==1)?Integer.MAX_VALUE : Integer.MIN_VALUE;
        else res = (int)(sign==1? ans : -ans);
        return res;
    }
    private long ldivide(long a, long b) {//  Think this as a binary search.
        if (a < b) return 0;
        long sum = b;
        long multiple = 1;
        while (sum+sum<=a) {
            sum += sum;
            multiple += multiple;//moving with stride 1, 2, 4, 8, 16...2^n for performance reason.
        }
        return multiple + ldivide(a - sum, b);
    }

    /**http://www.programcreek.com/2014/05/leetcode-divide-two-integers-java/
     * 任何一个整数可以表示成以2的幂为底的一组基的线性组合，即num=a0*2^0+a1*2^1+a2*2^2+...+an*2^n。
     * 基于以上这个公式以及左移一位相当于乘以2，我们先让除数左移直到大于被除数之前得到一个最大的基。
     * 然后接下来我们每次尝试减去这个基，如果可以则结果增加2^k,然后基继续右移迭代，直到基为0为止。
     * 因为这个方法的迭代次数是按2的幂直到超过结果，所以时间复杂度为O(logn)。
     */
    public int divide1(int dividend, int divisor) {
        //handle special cases
        if(divisor==0) return Integer.MAX_VALUE;
        if(divisor==-1 && dividend == Integer.MIN_VALUE) return Integer.MAX_VALUE;
        //get positive values
        long a = Math.abs((long)dividend);
        long b = Math.abs((long)divisor);

        int result = 0;
        while(a>=b){
            //calculate number of left shifts
            int numShift = 0;
            while(a>=(b<<numShift)){
                numShift++;
            }
            //dividend minus the largest shifted divisor
            result += 1<<(numShift-1);
            a -= (b<<(numShift-1));
        }
        if((dividend>0 && divisor>0) || (dividend<0 && divisor<0)) return result;
        else return -result;
    }

}
