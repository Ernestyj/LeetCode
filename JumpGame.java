package leetcode51_60;

/**
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 Each element in the array represents your maximum jump length at that position.
 Determine if you are able to reach the last index.
 For example:
 A = [2,3,1,1,4], return true.
 A = [3,2,1,0,4], return false.
 * Created by DCLab on 12/8/2015.
 */
public class JumpGame {

    public static void main(String[] args) {
        int[] nums = {5,4,0,0,0,0,0};
        System.out.println("*****RESULT*****");
        System.out.println(new JumpGame().canJump(nums));
    }


    /**
     * http://blog.csdn.net/xiaozhuaixifu/article/details/13628465
     * 注意与Jump Game II的区别。
     * 如果采用DP（复杂度为O(n^2)），大数据测试用例将无法通过。
     * 贪心思路：（复杂度O(n)）
     * 用maxLen维护一个从开始位置能到达的最远距离，然后判断
     ①在当前位置是否能够到达最后一个位置：(i + nums[i]) >= nums.length - 1
     ②当前位置是否可达：maxLen >= i
     如果两个条件都满足则返回true；
     如果当前位置是0，并且最远距离不能超过当前位置，那么只能返回false；
     此外，注意更新最远距离maxLen。
     * @param nums
     * @return
     */
    public boolean canJump(int[] nums) {
        if(nums.length <= 1) return true;
        if(nums[0] >= nums.length - 1) return true;
        if(nums[0] == 0) return false;
        int maxLen = nums[0];
        for(int i = 1; i < nums.length - 1; i++)
        {
            if(maxLen >= i && (i + nums[i]) >= nums.length - 1)
                return true;
            if(maxLen <= i && nums[i] == 0)
                return false;
            maxLen = Math.max(i + nums[i], maxLen);
        }
        return false;
    }

}
