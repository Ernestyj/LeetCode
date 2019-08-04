
/**Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.
 For example, given the array [2,3,1,2,4,3] and s = 7,
 the subarray [4,3] has the minimal length under the problem constraint.
 * Created by eugene on 16/4/5.
 */
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {//滑动窗口法:双指针,r指针++, 当sum>=s时l指针++直到sum<s，再r指针++
        if(nums.empty()) return 0;
        int l = 0, r = 0, sum = 0, minLen = INT_MAX;
        for (int r = 0; r < nums.size(); ++r) {
            sum += nums[r];
            while (sum>=s){
                minLen = min(minLen, r-l+1);
                sum -= nums[l++];
            }
        }
        return minLen==INT_MAX? 0:minLen;
    }
};
//public class MinimumSizeSubarraySum {
//    //简洁 https://leetcode.com/discuss/45449/accepted-clean-java-o-n-solution-two-pointers
//    //滑动窗口法:双指针,r指针++, 当sum>=s时l指针++直到sum<s，再r指针++.
//    public int minSubArrayLen(int s, int[] nums) {
//        if (nums == null || nums.length == 0) return 0;
//        int i = 0, j = 0;
//        int sum = 0;
//        int minLen = Integer.MAX_VALUE;
//        while (j<nums.length) {
//            sum += nums[j++];
//            while (sum>=s) {
//                minLen = Math.min(minLen, j-i);
//                sum -= nums[i++];
//            }
//        }
//        return minLen==Integer.MAX_VALUE? 0 : minLen;
//    }
//
//    /**
//     * 滑动窗口法:双指针,当sum>=s,移动左指针;当sum<s,移动右指针.
//     * http://www.programcreek.com/2014/05/leetcode-minimum-size-subarray-sum-java/
//     * @param s
//     * @param nums
//     * @return
//     */
//    public int minSubArrayLen1(int s, int[] nums) {
//        if(nums == null || nums.length == 0) return 0;
//        int i = 0, j = 0;
//        int minLen = nums.length;
//        int winSum = nums[0];
//        while (j<nums.length){
//            if (i==j){
//                if (nums[i]>=s) return 1;
//                else {
//                    j++;
//                    if (j<nums.length) winSum += nums[j];
//                    else return minLen;
//                }
//            } else {
//                if (winSum>=s) {
//                    minLen = Math.min(minLen, j-i+1);
//                    winSum -= nums[i];
//                    i++;
//                } else {
//                    j++;
//                    if (j<nums.length) winSum += nums[j];
//                    else return i==0 ? 0 : minLen;
//                }
//            }
//        }
//        return minLen;
//    }
//
//}
