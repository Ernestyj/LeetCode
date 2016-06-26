package leetcode1_10;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

/**
 * Given an array of integers, find two numbers such that they add up to a specific target number.

 The function twoSum should return indices of the two numbers such that they add up to
 the target, where index1 must be less than index2.
 Please note that your returned answers (both index1 and index2) are not zero-based.
 You may assume that each input would have exactly one solution.

 Input: numbers={2, 7, 11, 15}, target=9
 Output: index1 = 0, index2 = 1
 *
 * Created by DCLab on 11/2/2015.
 */
public class TwoSum {

    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for(int i=0; i<nums.length; i++){
            if(!map.containsKey(nums[i])) map.put(target-nums[i], i);
            else return new int[]{map.get(nums[i]), i};
        }
        return new int[2];
    }

}
