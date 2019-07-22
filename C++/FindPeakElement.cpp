
/**A peak element is an element that is greater than its neighbors.
 Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
 The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
 You may imagine that num[-1] = num[n] = -∞.
 For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
 Note: Your solution should be in logarithmic complexity. TODO 线性扫描不满足题目要求
 * Created by eugene on 16/3/15.
 */
class Solution {
public:
    // 考虑使用类似于二分查找法来缩短时间。由于只是需要找到任意一个峰值，那么我们在确定二分查找折半后中间那个元素后，和紧跟的那个元素比较下大小，
    // 如果大于，则说明峰值在前面，如果小于则在后面。这样就可以找到一个峰值了
    int findPeakElement(vector<int>& nums) {
        int len = nums.size(), l = 0, r = len-1;
        while(l+1<r){
            int m = l+(r-l)/2;
            if(nums[m]<nums[m+1]) l = m;  //峰值在后面
            else r = m; //峰值在前面
        }
        if((l-1<0 ||nums[l-1]<nums[l]) && (l+1>=len || nums[l]>nums[l+1])) return l;
        return r;   //或者l+1=r
    }

    int findPeakElement(vector<int>& nums) {    //记忆
        int l = 0, r = nums.size()-1;
        while(l<r){
            int m = l+(r-l)/2;
            if(nums[m]<nums[m+1]) l = m+1;  //峰值在后面
            else r = m; //峰值在前面 TODO 不是r = m-1
        }
        return r; //TODO 不是l
    }
};
//public class FindPeakElement {
//
//    //https://leetcode.com/discuss/68999/java-solution-and-explanation-using-invariants
//    public int findPeakElement(int[] nums) {
//        int len = nums.length;
//        if (len == 1) return 0;
//        int left = 0, right = len-1;
//        while (right-left > 1) {
//            int mid = left + (right-left)/2;
//            if (nums[mid] < nums[mid+1]) {
//                left = mid+1;
//            } else {
//                right = mid;
//            }
//        }
//        return (left==len-1 || nums[left]>nums[left+1]) ? left : right;
//    }
//
//
//    //二分法搜索
//    public int findPeakElement1(int[] nums) {
//        if (nums.length==1) return 0;
//        int l = 0, r = nums.length;
//        int m = 0;
//        while (l<=r) {
//            m = (l+r)/2;
//            if (m-1<=-1) {
//                if (nums[m]>nums[m+1]) return m;
//                else return m+1;
//            } else if (m+1>=nums.length) {
//                if (nums[m]>nums[m-1]) return m;
//                else return m-1;
//            }
//            if (nums[m]>nums[m-1] && nums[m]>nums[m+1]) return m;
//            else if (nums[m]<=nums[m-1]) r = m-1;
//            else l = m+1;
//        }
//        return -1;
//    }
//
//}
