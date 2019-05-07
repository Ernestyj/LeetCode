package leetcode151_160;

/**Find the contiguous subarray within an array (containing at least one number) which has the largest product.
 For example, given the array [2,3,-2,4],
 the contiguous subarray [2,3] has the largest product = 6.
 * Created by eugene on 16/3/11.
 */
public class MaximumProductSubarray {

    // 一维动态规划，考虑到乘积符号问题，同时记录最大值（正）与最小值（负），
    // 采用局部和全局变量追踪局部与最终结果。
    public int maxProduct(int[] nums) {
        if(nums==null || nums.length==0) return 0;
        int max = nums[0], min = nums[0], globalM = nums[0];
        for(int i=1; i<nums.length; i++){
            int t1 = max*nums[i], t2 = min*nums[i];
            max = Math.max(nums[i], Math.max(t1, t2));
            min = Math.min(nums[i], Math.min(t1, t2));
            globalM = Math.max(globalM, max);
        }
        return globalM;
    }

}
