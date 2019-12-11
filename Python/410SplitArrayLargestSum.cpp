
/**
 * Given an array which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.
 * Write an algorithm to minimize the largest sum among these m subarrays.
Note:
If n is the length of array, assume the following constraints are satisfied:
1 ≤ n ≤ 1000
1 ≤ m ≤ min(50, n)
Examples:
Input:
nums = [7,2,5,10,8]
m = 2
Output:
18
Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.
 */

class Solution {
public:
    /**
     * nums = [1, 2, 3, 4, 5], m = 3，我们将left设为数组中的最大值5，right设为数字之和15，然后我们算出中间数为10，
     * 我们接下来要做的是找出和最大且小于等于10的子数组的个数，[1, 2, 3, 4], [5]，可以看到我们无法分为3组，说明mid偏大，所以我们让right=mid，
     * 然后再次二分查找，算出mid=7，再次找出和最大且小于等于7的子数组的个数，[1,2,3], [4], [5]，成功的找出了三组，说明mid还可以进一步降低，让right=mid，
     * 然后再次二分查找，算出mid=6，再次找出和最大且小于等于6的子数组的个数，[1,2,3], [4], [5]，成功的找出了三组，尝试着继续降低mid，让right=mid，
     * 然后再次二分查找，算出mid=5，再次找出和最大且小于等于5的子数组的个数，[1,2], [3], [4], [5]，发现有4组，此时mid太小了，应该增大mid，让left=mid+1，
     * 此时left=6，right=5，循环退出了，返回left即可
     */
    int splitArray(vector<int>& nums, int m) {
        long long l = 0, r = 0, mid = 0;
        for(int i=0; i<nums.size(); i++){
            l = max(nums[i], (int)l);
            r += nums[i];
        }
        while(l<=r){
            mid = l+(r-l)/2;
            if(canSplit(nums, m, mid)) r = mid-1;
            else l = mid+1;
        }
        return l;
    }
    bool canSplit(vector<int>& nums, int m, long long midSum){   //找出和最大，且<=midSum的子数组的个数
        long long count = 1, sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];  //贪心
            if(sum>midSum){
                sum = nums[i];
                ++count;
                if(count>m) return false;
            }
        }
        return true;
    }
};
