package leetcode161_170;

/**A peak element is an element that is greater than its neighbors.
 Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
 The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
 You may imagine that num[-1] = num[n] = -∞.
 For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
 Note: Your solution should be in logarithmic complexity.
 * Created by eugene on 16/3/15.
 */
public class FindPeakElement {

    //二分法搜索
    public int findPeakElement(int[] nums) {
        if (nums.length==1) return 0;
        int l = 0, r = nums.length;
        int mid = 0;
        while (l<=r) {
            mid = (l+r)/2;
            if (mid-1<=-1) {
                if (nums[mid]>nums[mid+1]) return mid;
                else return mid+1;
            } else if (mid+1>=nums.length) {
                if (nums[mid]>nums[mid-1]) return mid;
                else return mid-1;
            }
            if (nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid;
            else if (nums[mid]<=nums[mid-1]) r = mid-1;
            else l = mid+1;
        }
        return -1;
    }

}
