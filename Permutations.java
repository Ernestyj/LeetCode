package leetcode41_50;

import java.util.ArrayList;
import java.util.List;

/**
 * Given a collection of numbers, return all possible permutations.
 For example,
 [1,2,3] have the following permutations:
 [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 * Created by DCLab on 11/29/2015.
 */
public class Permutations {

    public static void main(String[] args) {
        int nums[] = { 1,2,3 };
        List<List<Integer>> result = new Permutations().permute(nums);
        for (List<Integer> integers : result){
            for (Integer i : integers){
                System.out.print(i);
            }
            System.out.print(" ");
        }
    }


    private List<List<Integer>> result = new ArrayList<>();
    private List<Integer> temp;
    /**
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
    public List<List<Integer>> permute(int[] nums) {
        permutation(nums, 0, nums.length);
        return result;
    }
    private void permutation(int[] nums, int start, int len) {
        if (start == len - 1) {
            temp = new ArrayList<>();
            for (int i = 0; i < len; i ++) {
                temp.add(nums[i]);
            }
            result.add(temp);
        }
        else {
            for (int i = start; i < len; i ++) {
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
