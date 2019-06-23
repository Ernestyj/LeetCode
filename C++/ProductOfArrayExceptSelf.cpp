
/**Given an array of n integers where n > 1, nums, return an array output such that output[i]
 is equal to the product of all the elements of nums except nums[i].
 Solve it without division and in O(n).
 For example, given [1,2,3,4], return [24,12,8,6].
 Follow up: Could you solve it with constant space complexity?
 (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
 * Created by eugene on 16/5/2.
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {  //先从左往右求积,再从右往左求积.
        vector<int> res(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            res[i] = res[i-1]*nums[i-1];
        }
        int rProduct = 1;
        for (int i = nums.size()-1; i >= 0; --i) {
            res[i] *= rProduct;
            rProduct = rProduct*nums[i];
        }
        return res;
    }
};
//public class ProductOfArrayExceptSelf {
//    /**
//     * https://leetcode.com/discuss/46104/simple-java-solution-in-o-n-without-extra-space
//     * 先从左往右求积,再从右往左求积.
//     */
//    public int[] productExceptSelf(int[] nums) {
//        int len = nums.length;
//        int[] res = new int[len];
//        res[0] = 1;
//        for (int i=1; i<len; i++) {
//            res[i] = res[i-1] * nums[i-1];
//        }
//        int right = 1;
//        for (int i = len-1; i>=0; i--) {
//            res[i] *= right;
//            right *= nums[i];
//        }
//        return res;
//    }
//
//}
