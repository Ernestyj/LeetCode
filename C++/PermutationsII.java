package leetcode41_50;

import java.util.*;

/**
 * Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 For example,
 [1,1,2] have the following unique permutations:
 [1,1,2], [1,2,1], and [2,1,1].
 * Created by DCLab on 11/30/2015.
 */
public class PermutationsII {

    /**TODO 含重复
     * 回溯法：从集合依次选出每一个元素，作为排列的第一个元素，然后对剩余的元素进行全排列，如此递归处理。
     * 时间复杂度：n! 空间复杂度：（in place置换）
     * 以abc为例子：
     1. a和a交换(固定a), 求后面bc的全排列： abc, acb。 求完后，a 和 b交换； 得到bac,开始第二轮
     2. b和b交换(固定b), 求后面ac的全排列： bac, bca。 求完后，b 和 c交换； 得到cab,开始第三轮
     3. c和c交换(固定c), 求后面ba的全排列： cab, cba.
     * http://blog.csdn.net/randyjiawenjie/article/details/6313729
     * 分析图：http://segmentfault.com/a/1190000002710424
     * @param nums
     */
    public List<List<Integer>> permuteUnique(int[] nums) {
        Arrays.sort(nums);  //TODO 先排序可提速
        Set<List<Integer>> res = new HashSet<>();   //TODO 一定要用集合
        dfs(nums, res, 0);
        return new LinkedList<>(res);
    }
    private void dfs(int[] nums, Set<List<Integer>> res, int start){
        if(start==nums.length){
            LinkedList<Integer> sol = new LinkedList<>();
            for(int n: nums) sol.add(n);
            res.add(sol);
        }
        for(int i=start; i<nums.length; i++){
            if(i>start && nums[i]==nums[i-1]) continue; //TODO 跳过重复元素
            swap(nums, start, i);
            dfs(nums, res, start+1);
            swap(nums, start, i);
        }
    }
    private void swap(int[] s, int i, int j) {
        int temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }

}
