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

    public static void main(String[] args) {
        int nums[] = { 2,2,-1,2,3 };
        new PermutationsII().permuteUnique(nums);
        for (List<Integer> list : result){
            for (Integer i : list) System.out.print(i);
            System.out.println();
        }


    }

    private static List<List<Integer>> result = new ArrayList<>();
    private Set<List<Integer>> resultSet = new HashSet<>();
    private List<Integer> temp;
    /**注意：用例{1,-1,1,2,-1,2,2,-1}{2,2,-1,2,3}容易超时，注意添加跳过重复的逻辑判断
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
        Arrays.sort(nums);
        permutation(nums, 0, nums.length);
        result = new ArrayList<>(resultSet);
        return result;
    }
    private void permutation(int[] nums, int start, int len) {
        if (start == len - 1) {
            temp = new ArrayList<>();
            for (int i = 0; i < len; i ++) {
                temp.add(nums[i]);
            }
            resultSet.add(temp);
        }
        else {
            for (int i = start; i < len; i ++) {
                if (i + 1 < len && nums[i] == nums[i + 1]) continue;    //跳过重复
                swap(nums, start, i);
                permutation(nums, start + 1, len);
                swap(nums, start, i);
            }
        }

    }
    private void swap(int[] s, int i, int j) {
        int temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}
