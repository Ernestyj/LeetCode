
/**Given an unsorted array of integers, find the length of longest increasing subsequence.
 For example,
 Given [10, 9, 2, 5, 3, 7, 101, 18],
 The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4.
 Note that there may be more than one LIS combination, it is only necessary for you to return the length.
 Your algorithm should run in O(n2) complexity.
 Follow up: Could you improve it to O(n log n) time complexity?
 * Created by eugene on 16/6/1.
 */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {    //O(nlogn) TODO 注意理解
        vector<int> v;
        for(auto& a: nums){
            auto it = lower_bound(v.begin(), v.end(), a);
            if(it==v.end()) v.push_back(a);
            else *it = a;   //将>=a的值都置为a，这样v中只保留了增序序列
        }
        return v.size();
    }
    //O(n^2) brute force(DP): dp[i]为以nums[i]结尾的LIS，dp[j]=max(dp[j], dp[i]+1), i<j and nums[i]<nums[j]. 再找出dp中的最大值.
    int lengthOfLIS(vector<int>& nums) {//与Increasing Triplet Subsequence几乎一样
        if(nums.empty()) return 0;
        vector<int> dp(nums.size(), 1); //初始值为1
        for (int j = 0; j < nums.size(); ++j) {
            for (int i = 0; i < j; ++i) {   //TODO 注意遍历方法，i<j，这样j之前的dp都被遍历赋值过
                if(nums[i]<nums[j]) dp[j] = max(dp[j], dp[i]+1);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
//public class LongestIncreasingSubsequence {
//    //TODO 较难理解,注意Arrays.binarySearch的用法
//    /**https://leetcode.com/discuss/67609/short-java-solution-using-dp-o-n-log-n
//     * 图:http://www.programcreek.com/2014/04/leetcode-longest-increasing-subsequence-java/
//     * O(nlogn) DP与二分搜索,tricky
//     */
//    public int lengthOfLIS(int[] nums) {
//        int[] ascendings = new int[nums.length];
//        int len = 0;
//        for(int x: nums) {
//            int i = Arrays.binarySearch(ascendings, 0, len, x);
//            if(i<0) i = -(i+1); //TODO -(i+1)表示要维持原序列顺序,待插入的位置
//            ascendings[i] = x;  //更新/增加最后一个值
//            if(i==len) len++;
//        }
//        return len;
//    }
//
//    //TODO 易理解
//    /**http://www.programcreek.com/2014/04/leetcode-longest-increasing-subsequence-java/
//     * O(n^2) brute force(DP): dp[i]为以nums[i]结尾的LIS
//     dp[j]=max(dp[j], dp[i]+1), i<j and nums[i]<nums[j]. 再找出dp中的最大值.
//     */
//    public int lengthOfLIS1(int[] nums) {
//        if (nums==null || nums.length==0) return 0;
//        int len = nums.length;
//        int[] dp = new int[len];
//        Arrays.fill(dp, 1);
//        for (int j=0; j<len; j++){
//            for (int i=0; i<j; i++){
//                if (nums[i]<nums[j])
//                    dp[j] = Math.max(dp[j], dp[i]+1);
//            }
//        }
//        int max = 0;
//        for (int x: dp) max = Math.max(max, x);
//        return max;
//    }
//
//}
