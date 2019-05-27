package leetcode341_350;

/**Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
 Example:
 Given num = 16, return true. Given num = 5, return false.
 Follow up: Could you solve it without loops/recursion?
 * Created by eugene on 16/6/22.
 */
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num>0) while(num%4==0) num /= 4;
        return num==1;
    }
};
//public class PowerOfFour {
//
//    /**https://leetcode.com/discuss/98011/1-line-c-solution-without-confusing-bit-manipulations
//     * 这里还要检测2的幂
//     * @param num
//     * @return
//     */
//    public boolean isPowerOfFour(int num) {
//        //TODO return num>0 && 1073741824%num==0 无法排除2的情况
//        return num>0 && (num&(num-1))==0 && (num-1)%3==0;
//    }
//
//    public boolean isPowerOfFour1(int num) {
//        if (num>1) while (num%4==0) num /= 4;
//        return num==1;
//    }
//
//}
