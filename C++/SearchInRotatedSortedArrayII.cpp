
/**
 * Follow up for "Search in Rotated Sorted Array":
 What if duplicates are allowed?
 Would this affect the run-time complexity? How and why?
 Write a function to determine if a given target is in the array.
 * Created by DCLab on 1/2/2016.
 */
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size()<=0) return false;
        int l = 0, r = nums.size()-1, m = 0;
        while (l<=r){
            m = l+(r-l)/2;
            if(target==nums[m]) return true;
            else if(nums[m]<nums[r]){   //m~r有序
                if(nums[m]<target && target<=nums[r]) l = m+1;
                else r = m-1;
            }else if(nums[m]>nums[r]){  //l~m有序
                if(nums[l]<=target && target<nums[m]) r = m-1;
                else l = m+1;
            }else{  //nums[m] == nums[r]时
                --r;
            }
        }
        return false;
    }
};
//public class SearchInRotatedSortedArrayII {
//
//    /**
//     * 当有重复数字，会存在A[m] = A[r]的情况。此时右半序列可能是sorted，也可能并没有sorted，如下例子。
//     3 1 2 3 3 3 3
//     3 3 3 3 1 2 3
//     所以当A[m] = A[r] != target时，无法排除一半的序列，而只能排除掉A[r]，此时只能搜寻A[l : r-1]
//     正因为这个变化，在最坏情况下，算法的复杂度从O(logn)退化成了O(n)：例如序列 2 2 2 2 2 2 2 中寻找target = 1。
//     参考：http://bangbingsyb.blogspot.com/2014/11/leetcode-search-in-rotated-sorted-array.html
//     * @param nums
//     * @param target
//     * @return
//     */
//    public boolean search(int[] nums, int target) {
//        if (nums == null || nums.length == 0) return false;
//        int l = 0, r = nums.length-1;
//        int m = 0;
//        while (l<=r){
//            m = l+(r-l)/2;
//            if (target==nums[m]) return true;
//            if (nums[m]<nums[r]) {    //m~r有序
//                if (nums[m]<target && target<=nums[r]) l = m+1;
//                else r = m-1;
//            } else if (nums[m] > nums[r]){  //l~m有序
//                if (nums[l]<=target && target<nums[m]) r = m-1;
//                else l = m+1;
//            } else {    //nums[m] == nums[r]时
//                r--;
//            }
//        }
//
//        return false;
//    }
//
//}
