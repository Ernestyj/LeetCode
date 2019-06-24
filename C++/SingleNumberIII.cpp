
/**Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
 For example: Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
 Note: The order of the result is not important. So in the above example, [5, 3] is also correct.
 Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
 * Created by eugene on 16/5/12.
 */
class Solution {
public:
    //如果两个相同的数字 '异或' ，每位都会是0，而不同的数字 '异或' ，一定会有对应位不同，一个0一个1，这样 '异或' 是1
    vector<int> singleNumber(vector<int>& nums) {
        int xy = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        xy = xy & -xy;  //取出最右端为 ‘1’ 的位就可以将原数组分为两个数组了(负数采用补码的形式，而补码就是反码 +1)，也可以写成 xy = xy & ~(xy-1)
        vector<int> res(2, 0);
        for(auto& a: nums){
            if(a&xy) res[0] ^= a;
            else res[1] ^= a;
        }
        return res;
    }
};
//public class SingleNumberIII {
//    /**
//     * http://www.kancloud.cn/kancloud/data-structure-and-algorithm-notes/72983
//     * 先将所有的数异或，得到的将是x和y以后之后的值xy。
//     找到xy为1的某一位（为了方便就取最右边为1的一位，取法为xy & ~(xy-1)，
//     再将这一位为1的所有数异或得到x，剩下的所有数异或得到y。
//     */
//    public int[] singleNumber(int[] nums) {
//        int[] result = new int[2];
//        if (nums==null || nums.length==0) return result;
//        int xy = 0;
//        for (int i: nums)  xy ^= i;
//        // get the last 1 bit of xXORy, e.g. 1010 ==> 0010
//        int last1Bit = xy & ~(xy-1);
//        int x = 0, y = 0;
//        for (int i: nums) {
//            if ((last1Bit & i) == 0) x ^= i;
//            else y ^= i;
//        }
//        result[0] = x;
//        result[1] = y;
//        return result;
//    }
//
//}
