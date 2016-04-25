package leetcode201_210;

/**Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.
 For example, given the array [2,3,1,2,4,3] and s = 7,
 the subarray [4,3] has the minimal length under the problem constraint.
 * Created by eugene on 16/4/5.
 */
public class MinimumSizeSubarraySum {

    /**
     * 滑动窗口法:双指针,当sum>=s,移动左指针;当sum<s,移动右指针.
     * http://www.programcreek.com/2014/05/leetcode-minimum-size-subarray-sum-java/
     * @param s
     * @param nums
     * @return
     */
    public int minSubArrayLen(int s, int[] nums) {
        if(nums == null || nums.length == 0) return 0;
        int i = 0, j = 0;
        int minLen = nums.length;
        int winSum = nums[0];
        while (j<nums.length){
            if (i==j){
                if (nums[i]>=s) return 1;
                else {
                    j++;
                    if (j<nums.length) winSum += nums[j];
                    else return minLen;
                }
            } else {
                if (winSum>=s) {
                    minLen = Math.min(minLen, j-i+1);
                    winSum -= nums[i];
                    i++;
                } else {
                    j++;
                    if (j<nums.length) winSum += nums[j];
                    else return i==0 ? 0 : minLen;
                }
            }
        }
        return minLen;
    }

}
