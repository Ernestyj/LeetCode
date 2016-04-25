package leetcode31_40;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 *
 * Given a set of candidate numbers (C) and a target number (T), find all unique combinations
 * in C where the candidate numbers sums to T.
 The same repeated number may be chosen from C unlimited number of times.
 Note:
 1. All numbers (including target) will be positive temp.
 2. Elements in a combination (a1, a2, … , ak) must be in non-descending order.
    (ie, a1 ≤ a2 ≤ … ≤ ak).
 3. The solution set must not contain duplicate combinations.
 For example, given candidate set 2,3,6,7 and target 7,
 A solution set is:
 [7]
 [2, 2, 3]
 * Created by DCLab on 11/22/2015.
 */
public class CombinationSum {

    public static void main(String[] args) {
        int[] nums = {2,3,6,7};
        System.out.println("*****RESULT*****");
        CombinationSum instance = new CombinationSum();
        instance.combinationSum(nums, 7);
        for (List<Integer> ints : instance.result){
            for (Integer i : ints) System.out.print(i + " ");
            System.out.println();
        }
    }

    private List<List<Integer>> result = new ArrayList<>();
    private List<Integer> temp = new ArrayList<>();
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        if(candidates == null || candidates.length == 0) return result;
        Arrays.sort(candidates);
        backTrack(candidates, target, 0);
        return result;
    }
    //入参candidates增序
    private void backTrack(int[] nums, int target, int k){
        if (target == 0){
            result.add(new ArrayList<>(temp));
            return;
        }
        for (int i = k; i < nums.length; i++){
            if (target < nums[i]) return;
            temp.add(nums[i]);
            backTrack(nums, target - nums[i], i);   //传入i而非i + 1表明可以重复
            temp.remove(temp.size() - 1);
        }
    }

}
