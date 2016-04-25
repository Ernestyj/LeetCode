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

    public static void main(String[] args) {
        int[] nums = {0, 4, 3, 0};
//        int[] indexes = new TwoSum().twoSumBruteForce(nums, 9);
        int[] indexes = new TwoSum().twoSum(nums, 0);
        System.out.print("index1: " + indexes[0] + ", index2: " + indexes[1]);
    }

    /**O(n)
     * http://www.programcreek.com/2012/12/leetcode-solution-of-two-sum-in-java/
     * @param numbers
     * @param target
     * @return
     */
    public int[] twoSum(int[] numbers, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        int[] result = new int[2];
        for (int i = 0; i < numbers.length; i++) {
            if (map.containsKey(numbers[i])) {
                int index = map.get(numbers[i]);
                result[0] = index;
                result[1] = i;
                break;
            } else {
                map.put(target - numbers[i], i);
            }
        }
        return result;
    }

    /**
     * bruteforce, 时间复杂度 n^2
     * @param nums
     * @param target
     * @return
     */
    public int[] twoSum1(int[] nums, int target) {
        int[] indexes = new int[2];

        for (int i = 0; i < nums.length; i++){
            for (int j = i + 1; j < nums.length; j++){
                int sum = nums[i] + nums[j];
                if (sum == target){
                    indexes[0] = i;
                    indexes[1] = j;
                    return indexes;
                }
            }
        }
        return null;
    }

}
