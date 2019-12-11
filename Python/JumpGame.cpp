
/**
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 Each element in the array represents your maximum jump length at that position.
 Determine if you are able to reach the last index.
 For example:
 A = [2,3,1,1,4], return true.
 A = [3,2,1,0,4], return false.
 * Created by DCLab on 12/8/2015.
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if(i>maxReach) return false;
            maxReach = max(maxReach, nums[i]+i);
        }
        return true;
    }
};
//public class JumpGame {
//
//    /**https://leetcode.com/discuss/11422/simplest-o-n-solution-with-constant-space
//     * 注意与Jump Game II的区别。
//     * 如果采用DP（复杂度为O(n^2)，大数据测试用例将无法通过。
//     * 贪心思路：（复杂度O(n)）
//     * @param nums
//     * @return
//     */
//    public boolean canJump(int[] nums) {
//        int maxReach = 0;
//        for(int i=0; i<nums.length; i++){
//            if(i>maxReach) return false;
//            maxReach = Math.max(nums[i]+i, maxReach);//每次都更新当前最大可达值
//        }
//        return true;
//    }
//
//
//}
