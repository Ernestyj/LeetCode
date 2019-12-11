

/**You are a professional robber planning to rob houses along a street. Each house has a certain
 amount of money stashed, the only constraint stopping you from robbing each of them is that
 adjacent houses have security system connected and it will automatically contact the police
 if two adjacent houses were broken into on the same night.
 Given a list of non-negative integers representing the amount of money of each house,
 determine the maximum amount of money you can rob tonight without alerting the police.
 * Created by eugene on 16/3/28.
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()<=0) return 0;
        if(nums.size()==1) return nums[0];//TODO 不能漏
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            dp[i] = (max(dp[i-1], dp[i-2]+nums[i]));
        }
        return dp.back();//TODO 不能用dp[nums.size()-1], 否则unsigned int - 1可能会overflow
    }
};

//public class HouseRobber {
//
//    //DP, dp(i)=max{dp(i-1), dp(i-2)+nums(i)}
//    public int rob(int[] nums) {
//        if (nums.length==0) return 0;
//        if (nums.length==1) return nums[0];
//        int[] dp = new int[nums.length];
//        dp[0] = nums[0];
//        dp[1] = Math.max(dp[0], nums[1]);
//        for (int i=2; i<nums.length; i++){
//            dp[i] = Math.max(dp[i-1], dp[i-2]+nums[i]);
//        }
//        return dp[nums.length-1];
//    }
//
//}
