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

    /**
     * 首先明白，这个题只要我们求跳数，怎么跳、最后距离是多少都没让求，不要做无必要的计算。
     * 如果采用DP，大数据测试用例将无法通过。
     * 分析图：http://www.cnblogs.com/lichen782/p/leetcode_Jump_Game_II.html
     * 贪心思路：
     * lastMax:用最小跳数jumps可达的最大距离；
     * maxReach:用jumps + 1跳可达的最大距离；（贪心值）
     * maxReach = max(i+nums[i], maxReach), 0 <= i <= lastMax
     * @param nums
     * @return
     */
    public int jump(int[] nums) {
        int minJumps = 0;
        int lastMax = 0;
        int maxReach = 0;
        for (int i=0; i<nums.length; ++i) {
            if (i>lastMax) {   //TODO 注意此处的巧妙
                minJumps++;
                lastMax = maxReach;     //更新
            }
            maxReach = Math.max(maxReach, i+nums[i]);   //更新
        }
        return minJumps;
    }
}
