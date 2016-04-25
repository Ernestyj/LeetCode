package leetcode41_50;

/**
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 Each element in the array represents your maximum jump length at that position.
 Your goal is to reach the last index in the minimum number of jumps.
 For example:
 Given array A = [2,3,1,1,4]
 The minimum number of jumps to reach the last index is 2.
 (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
 * Created by DCLab on 11/28/2015.
 */
public class JumpGameII {

    public static void main(String[] args) {
        int[] nums = { 0, 2 ,3 };//2,3,1,1,4
        System.out.println("*****RESULT*****");
        System.out.println(new JumpGameII().jump(nums));
    }


    /**
     * 首先明白，这个题只要我们求跳数，怎么跳、最后距离是多少都没让求，不要做无必要的计算。
     * 如果采用DP，大数据测试用例将无法通过。
     * 分析图：http://www.cnblogs.com/lichen782/p/leetcode_Jump_Game_II.html
     * 贪心思路：
     * last:用最小跳数jumps可达的最大距离；
     * curr:用jumps + 1跳可达的最大距离；（贪心值）
     * 有curr = max(i+nums[i]), 0 <= i <= last
     * @param nums
     * @return
     */
    public int jump(int[] nums) {
        int jumps = 0;
        int last = 0;
        int curr = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (i > last) {
                ++jumps;
                last = curr;
            }
            curr = Math.max(curr, i + nums[i]);
        }
        return jumps;
    }
}
