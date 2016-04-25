package leetcode191_200;

/**You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
 Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
 * Created by eugene on 16/3/28.
 */
public class HouseRobber {

    //DP, s(i)=max{s(i-1), s(i-2)+nums(i)}
    public int rob(int[] nums) {
        if (nums.length==0) return 0;
        if (nums.length==1) return nums[0];
        int[] s = new int[nums.length];
        s[0] = nums[0];
        s[1] = Math.max(s[0], nums[1]);
        if (nums.length==2) return s[1];
        for (int i=2; i<nums.length; i++){
            s[i] = Math.max(s[i-1], s[i-2]+nums[i]);
        }
        return s[nums.length-1];
    }

}
