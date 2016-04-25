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

    public static void main(String[] args) {
        int[] nums = {1,1,1,0,0,0,0,0,0,0,0};  //{-1, 2, 1, -4}排序后是 -4 -1 1 2
        int target = -1000;
        int result = new ThreeSumClosest().threeSumClosest(nums, target);

        System.out.println("************************");
        System.out.print(result);

    }


    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int closestDiff = Integer.MAX_VALUE;
        int threeSum = 0;
        for (int i = 0; i < nums.length - 2; i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;  //去重
            int m = i + 1;
            int n = nums.length - 1;
            while (m < n){
                int tempThreeSum = nums[m] + nums[n] + nums[i];
                int tempDiff = Math.abs(tempThreeSum - target);
                if (tempThreeSum == target) return tempThreeSum;
                else if (tempThreeSum > target){
                    n--;
                } else {
                    m++;
                }
                if (tempDiff < closestDiff){
                    threeSum = tempThreeSum;
                    closestDiff = tempDiff;
                }
            }
        }
        return threeSum;
    }


}
