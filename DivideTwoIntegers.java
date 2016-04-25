package leetcode21_30;

/**
 * Divide two integers without using multiplication, division and mod operator.

 If it is overflow, return MAX_INT.

 Integer.MIN_VALUE = -2147483648
 Integer.MAX_VALUE = 2147483647
 *
 * Created by DCLab on 11/12/2015.
 */
public class DivideTwoIntegers {

    public static void main(String[] args) {
        int l = Integer.MIN_VALUE;
        int r = 1;

        System.out.println("*****RESULT*****");
        int x = new DivideTwoIntegers().divide1(l, r);
        System.out.println(x);

    }

    /**TODO 记忆此方法
     * http://www.programcreek.com/2014/05/leetcode-divide-two-integers-java/
     * 任何一个整数可以表示成以2的幂为底的一组基的线性组合，即num=a0*2^0+a1*2^1+a2*2^2+...+an*2^n。
     * 基于以上这个公式以及左移一位相当于乘以2，我们先让除数左移直到大于被除数之前得到一个最大的基。
     * 然后接下来我们每次尝试减去这个基，如果可以则结果增加2^k,然后基继续右移迭代，直到基为0为止。
     *
     * 因为这个方法的迭代次数是按2的幂直到超过结果，所以时间复杂度为O(logn)。
     *
     * @param dividend
     * @param divisor
     * @return
     */
    public int divide(int dividend, int divisor) {
        //handle special cases
        if(divisor==0) return Integer.MAX_VALUE;
        if(divisor==-1 && dividend == Integer.MIN_VALUE) return Integer.MAX_VALUE;
        //get positive values
        long pDividend = Math.abs((long)dividend);
        long pDivisor = Math.abs((long)divisor);

        int result = 0;
        while(pDividend>=pDivisor){
            //calculate number of left shifts
            int numShift = 0;
            while(pDividend>=(pDivisor<<numShift)){
                numShift++;
            }
            //dividend minus the largest shifted divisor
            result += 1<<(numShift-1);
            pDividend -= (pDivisor<<(numShift-1));
        }
        if((dividend>0 && divisor>0) || (dividend<0 && divisor<0)) return result;
        else return -result;
    }


    // 转化为减法，为防止超时采用批量减 TODO 注意采用普通减法会超时
    public int divide1(int dividend, int divisor) {
        //handle special cases
        if(divisor == 0) return Integer.MAX_VALUE;
        //TODO （入参不可能溢出）只有结果才可能溢出，且只有Integer.MIN_VALUE / -1这一种情况会溢出
        if(divisor == -1 && dividend == Integer.MIN_VALUE) return Integer.MAX_VALUE;
        //get sign
        boolean isPositive = false;
        if (dividend < 0 && divisor < 0 || dividend > 0 && divisor > 0) isPositive = true;
        //get positive values
        long l = Math.abs((long)dividend);
        long r = Math.abs((long)divisor);
        int tempResult = positiveDivide1(l, r);
        return isPositive == true ? tempResult : -tempResult;
    }
    //入参有l > r > 0
    private int positiveDivide1(long l, long r){
        int count = 0;
        int times = 1;
        while (l >= times * r){
            l -= times * r;
            count += times;
            times++;
        }
        while (l >= r){
            l -= r;
            count++;
        }
        return count;
    }


    //笔算法 TODO BUG调试失败
    public int divide2(int dividend, int divisor) {
        if (divisor == 0) return Integer.MAX_VALUE;
        if (Math.abs(divisor) < 0) return 0;    //TODO divisor < Integer.MIN_VALUE溢出处理
        if (dividend == 0 || Math.abs(dividend) < Math.abs(divisor)) return 0;
        boolean isPositive = false;
        if (dividend < 0 && divisor < 0 || dividend > 0 && divisor > 0) isPositive = true;
        String l = String.valueOf(Math.abs(dividend));
        String r = String.valueOf(Math.abs(divisor));
        if (Integer.valueOf(l) == Integer.valueOf(r)) return isPositive == true ? 1 : -1;//TODO
        int tempResult = positiveDivide2(l, r);
        return isPositive == true ? tempResult : -tempResult;
    }
    //入参有l > r > 0
    private int positiveDivide2(String l, String r){
        StringBuilder result = new StringBuilder();
        int index = r.length() - 1;    //indice从左数高位往低位移
        String tempL = l.substring(0, r.length());
        int curCount;
        int temp;
        if (index == 0){    //TODO r为单位数的特殊处理
            //开始做减法，直到不可相减
            for (curCount = 0; (temp = Integer.valueOf(tempL) - Integer.valueOf(r)) >= 0; curCount++){
                tempL = String.valueOf(temp);   //更新
            }
            result.append(curCount);
        }
        while (index < l.length() - 1){ //直到从最高位移到最低位 TODO 条件易错
            while(Integer.valueOf(tempL) < Integer.valueOf(r)){ //往低位移，直到找到可以相减的位
                index++;
                if (index < l.length()) tempL += l.charAt(index);
            }
            //开始做减法，直到不可相减
            for (curCount = 0; (temp = Integer.valueOf(tempL) - Integer.valueOf(r)) >= 0; curCount++){
                tempL = String.valueOf(temp);   //更新
            }
            result.append(curCount);
        }
        return Integer.valueOf(result.toString());
    }

}
