package leetcode11_20;

import java.util.Arrays;

/**
 * Given an array S of n integers, find three integers in S such that the sum is
 * closest to a given number, target. Return the sum of the three integers.
 * You may assume that each input would have exactly one solution.

 For example, given array S = {-1 2 1 -4}, and target = 1.
 The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 *
 * Created by DCLab on 11/4/2015.
 */
public class ThreeSumClosest {

    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int closestDiff = Integer.MAX_VALUE;
        int result = 0;
        for (int i = 0; i < nums.length - 2; i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;  //去重
            int l = i + 1, r = nums.length - 1;
            while (l < r){
                int sum = nums[l] + nums[r] + nums[i];
                if (sum == target) return sum;
                else if (sum > target) r--;
                else l++;
                int diff = Math.abs(sum - target);
                if (diff < closestDiff){
                    result = sum;
                    closestDiff = diff;
                }
            }
        }
        return result;
    }


}
