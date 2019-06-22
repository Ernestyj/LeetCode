
/**Note: This is an extension of House Robber.
 After robbing those houses on that street, the thief has found himself a new place 
 for his thievery so that he will not get too much attention. This time, 
 all houses at this place are arranged in a circle. That means the first house is 
 the neighbor of the last one. Meanwhile, the security system for these houses remain 
 the same as for those in the previous street.
 Given a list of non-negative integers representing the amount of money of each house, 
 determine the maximum amount of money you can rob tonight without alerting the police.
 * Created by eugene on 16/4/9.
 */
class Solution {
public:
    int rob(vector<int>& nums) {//和House Robber基本一致，多一种情况
        if(nums.size()<=0) return 0;
        if(nums.size()==1) return nums[0];//TODO 不能漏
        if(nums.size()==2) return max(nums[0], nums[1]);
        return max(helper(nums, 0, nums.size()-2), helper(nums, 1, nums.size()-1));
    }
    int helper(vector<int>& nums, int l, int r){    //DP, dp(i)=max{dp(i-1), dp(i-2)+nums(i)} 和House Robber基本一致
        //if(l>=r) return nums[l];
        vector<int> dp(r+1, 0);
        dp[l] = nums[l];
        dp[l+1] = max(nums[l], nums[l+1]);
        for (int i = l+2; i < r+1; ++i) {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp.back();
    }
};
//public class HouseRobberII {
//
//    //DP, s(i)=max{s(i-1), s(i-2)+nums(i)}
//    //分两种情况,遍历数组两次,1.包含第一个,不含最后一个;2.包含最后一个,不含第一个.
//    //http://www.programcreek.com/2014/05/leetcode-house-robber-ii-java/
//    public int rob(int[] nums) {
//        int len = nums.length;
//        if (len==0) return 0;
//        if (len==1) return nums[0];
//        if (len==2) return Math.max(nums[0], nums[1]);
//        int[] s = new int[len];
//        //剔除最后一个元素
//        s[0] = nums[0];
//        s[1] = Math.max(s[0], nums[1]); //TODO 易错
//        for (int i=2; i<len-1; i++){
//            s[i] = Math.max(s[i-1], s[i-2]+nums[i]);
//        }
//        int temp = s[len-2];
//        //剔除第一个元素
//        s[1] = nums[1];
//        s[2] = Math.max(s[1], nums[2]); //TODO 易错
//        for (int i=3; i<len; i++){
//            s[i] = Math.max(s[i-1], s[i-2]+nums[i]);
//        }
//        return Math.max(temp, s[len-1]);
//    }
//
//}
