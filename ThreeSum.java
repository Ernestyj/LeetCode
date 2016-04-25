package leetcode11_20;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
 * Find all unique triplets in the array which gives the sum of zero.

 Note:
 Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 The solution set must not contain duplicate triplets.

 For example, given array S = {-1 0 1 2 -1 -4},
 A solution set is:
 (-1, 0, 1)
 (-1, -1, 2)
 *
 * Created by DCLab on 11/4/2015.
 */
public class ThreeSum {

    public static void main(String[] args) {
        int[] nums = {-1, 0, 1, 2, -1, -4};  //排序后是 -4 -1 -1 0 1 2

        List<List<Integer>> result = new ThreeSum().threeSum(nums);

        System.out.println("************************");
        for (List<Integer> list : result){
            for (Integer i : list){
                System.out.print(i + " ");
            }
            System.out.println();
        }
    }

    /**
     * 时间复杂度 n^2 （nlogn + n * n） ???
     * 先快排，再枚举第一个数，然后对余下数的求2sum(注意去重，去重易出错)
     *
     * @param nums
     * @return
     */
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> lists = new ArrayList<>();
        int target = 0;
        for (int i = 0; i < nums.length - 2; i++){
            // 去重 TODO 注意1.条件不是nums[i] == nums[i + 1]，理解含义
            // TODO 注意2.循环体不是i++
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int twoSumTarget = target - nums[i];
            int m = i + 1;
            int n = nums.length - 1;
            while (m < n){
                if (twoSumTarget == nums[m] + nums[n]){
                    lists.add(Arrays.asList(nums[i], nums[m], nums[n]));
                    //去重
                    int k = m + 1;
                    while (k < n && nums[k] == nums[m]) k++;
                    m = k;
                    //去重
                    k = n - 1;
                    while (k > m && nums[k] == nums[n]) k--;
                    n = k;
                } else if (nums[m] + nums[n] > twoSumTarget) n--;
                else m++;
            }

        }
        return lists;
    }


}
