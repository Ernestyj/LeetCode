
/**
 * Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.
Formally the function should:
Return true if there exists i, j, k
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.
Example 1:
Input: [1,2,3,4,5]
Output: true
Example 2:
Input: [5,4,3,2,1]
Output: false
 */

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {//巧妙思想
        int m1 = INT_MAX, m2 = INT_MAX; //建立两个卡点
        for(auto& a: nums){
            if(a<=m1) m1 = a;   //如果a<=m1，则将当前数字赋给m1
            else if(a<=m2) m2 = a;  //如果m1<a<=m2，那么将当前数字赋给m2，一旦m2被更新了则一定会有一个数小于m2，即成功的组成了一个长度为2的递增子序列
            else return true;   //一旦遍历到比m2还大的数，我们直接返回true
        }
        return false;
    }
    bool increasingTriplet(vector<int>& nums) {//Brute force 与Longest Increasing Subsequence几乎一样
        //dp[i]为以nums[i]结尾的LIS，dp[j]=max(dp[j], dp[i]+1), i<j and nums[i]<nums[j]. 再找出dp中的最大值.
        vector<int> dp(nums.size(), 1);
        for (int j = 0; j < nums.size(); ++j) {
            for (int i = 0; i < j; ++i) {   //TODO 注意遍历方法，i<j，这样j之前的dp都被遍历赋值过
                if(nums[i]<nums[j]) {
                    dp[j] = max(dp[j], dp[i]+1);
                    if(dp[j]>=3) return true;
                }
            }
        }
        return false;
    }
};

