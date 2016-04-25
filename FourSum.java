package leetcode11_20;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * 4Sum:
 * Given an array S of n integers, are there elements a, b, c, and d in S
 * such that a + b + c + d = target?
 * Find all unique quadruplets in the array which gives the sum of target.
 *
 * For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
 * A solution set is:
     (-1,  0, 0, 1)
     (-2, -1, 1, 2)
     (-2,  0, 0, 2)
 *
 * Created by DCLab on 10/31/2015.
 */
public class FourSum {

    private Integer[] tempTakes;    //0不取，1取
    private List<Integer[]> takesList;
    private int[] numbers;
    private int maxDepth;


    public static void main(String[] args) {
        int[] nums = {1, 0, -1, 0, -2, 2};  //排序后是 -2 -1 0 0 1 2
        int target = 0;
//        List<List<Integer>> result = new FourSum().fourSumBacktrack(nums, 0);
        List<List<Integer>> result = new FourSum().fourSum(nums, 0);

        System.out.println("************************");
        for (List<Integer> list : result){
            for (Integer i : list){
                System.out.print(i + " ");
            }
            System.out.println();
        }
    }

    /**
     * 回溯法 TODO 测试失败
     * @param nums
     * @param target
     * @return
     */
//    public List<List<Integer>> fourSumBacktrack(int[] nums, int target) {
//        Arrays.sort(nums);
//
//        maxDepth = nums.length;
//        numbers = new int[maxDepth + 1];
//        for (int i = 1; i < numbers.length; i++) numbers[i] = nums[i - 1];
//        tempTakes = new Integer[maxDepth + 1];
//        for (int i = 1; i < tempTakes.length; i++) tempTakes[i] = 0;
//        takesList = new ArrayList<>();
//
//        backtrack(1, 0, target);
//
//        System.out.println("************************");
//        System.out.println("item" + "\t" + "value" + "\t" + "take");
//        for (Integer[] ints : takesList){
//            for (int n = 1; n < maxDepth + 1; n++) {
//                System.out.println(n + "\t" + numbers[n] + "\t" + ints[n]);
//            }
//            System.out.println("----------------");
//        }
//
//        List<List<Integer>> answers = new ArrayList<>();
//        return answers;
//    }
//    private void backtrack(int i, int sum, int target){
//        if (i > maxDepth){
//            if (sum == target && getTakeCount(tempTakes) == 4){
//                takesList.add(tempTakes);
//                //重新分配
//                tempTakes = new Integer[maxDepth + 1];
//                for (int x = 1; x < tempTakes.length; x++) tempTakes[x] = 0;
//            }
//        } else {
//            for (int isTake = 0; isTake <= 1; isTake++){
//                tempTakes[i] = isTake;
//                int tookCount = getTakeCount(tempTakes);
//                if (i < 4 ||
//                        tookCount < 4 ||
//                        sum + numbers[i] * isTake != target ||
//                        (maxDepth - i + 1 + tookCount) >= 4){
//                    sum += numbers[i] * isTake;
//                    backtrack(i + 1, sum, target);
//                    sum -= numbers[i] * isTake;
//                }
//            }
//        }
//
//    }
//    private int getTakeCount(Integer[] takes){
//        int count = 0;
//        for (int i = 1; i < takes.length; i++){
//            if (takes[i] == 1) count++;
//        }
//        return count;
//    }

    /**
     * 时间复杂度 n^3 （nlogn + n^2 * n）
     * 先快排，再枚举第一个、第二个数，然后对余下数的求2sum(注意去重，去重易出错)
     * @param nums
     * @param target
     * @return
     */
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        List<List<Integer>> lists = new ArrayList<>();
        for (int i = 0; i < nums.length - 3; i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;  //去重
            for (int j = i + 1; j < nums.length - 2; j++){
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;  //去重
                int twoSumTarget = target - nums[i] - nums[j];
                int left = j + 1;
                int right = nums.length - 1;
                while (left < right){
                    int twoSum = nums[left] + nums[right];
                    if (twoSumTarget == twoSum){
                        lists.add(new ArrayList<>(Arrays.asList(nums[i], nums[j], nums[left], nums[right])));
                        //去重
                        int k = left + 1;
                        while (k < right && nums[k] == nums[left]) k++;
                        left = k;
                        //去重
                        k = right - 1;
                        while (k > left && nums[k] == nums[right]) k--;
                        right = k;
                    } else if (twoSum < twoSumTarget){
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return lists;
    }

}
