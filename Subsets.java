package leetcode71_80;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Given a set of distinct integers, nums, return all possible subsets.
 Note: Elements in a subset must be in non-descending order.
 The solution set must not contain duplicate subsets.
 For example,
 If nums = [1,2,3], a solution is:
 [ [3], [1], [2], [1,2,3], [1,3], [2,3], [1,2], [] ]
 * Created by DCLab on 12/31/2015.
 */
public class Subsets {

    //回溯
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        result.add(new ArrayList<>());
        dfs(nums, result, new ArrayList<>(), 0);
        return result;
    }
    private void dfs(int[] nums, List<List<Integer>> result, List<Integer> sol, int start){
        for (int i=start; i<nums.length; i++){
            sol.add(nums[i]);
            result.add(new ArrayList<>(sol));
            dfs(nums, result, sol, i+1);
            sol.remove(sol.size()-1);
        }
    }

    /**
     * 位图法：判断数i第k位是否为1：i&(1 << k-1) != 0则为1
     * 回溯法、添加数字法参考“全组合算法”
     * @param nums
     * @return
     */
    public List<List<Integer>> subsets1(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> sol;
        Arrays.sort(nums);
        int len = nums.length;
        int n = 1 << len;   //2^len
        for (int i=0; i<n; i++){
            sol = new ArrayList<>();
            //查看第一层循环任意一种取值中哪一位是1；如果是1，对应的字符就存在
            for (int k=1; k<=len; k++){
                if ( (i&(1 << k-1)) != 0 ) sol.add(nums[k-1]);
            }
            result.add(new ArrayList<>(sol));
        }
        return result;
    }

}
