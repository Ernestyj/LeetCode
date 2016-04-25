package leetcode151_160;

/**Follow up for "Find Minimum in Rotated Sorted Array":
 What if duplicates are allowed?
 Would this affect the run-time complexity? How and why?
 * Created by eugene on 16/3/12.
 */
public class FindMinimumInRotatedSortedArrayII {

    //当nums[m] = nums[r]时，无法排除一半的序列，而只能排除掉nums[r],此时只能搜寻nums[l:r-1]
    public int findMin(int[] nums) {
        int l = 0, r = nums.length - 1;
        int m = 0;
        int min = Integer.MAX_VALUE;
        while (l <= r){
            m = (l+r)/2;
            if (min>nums[m]) min = nums[m];
            if (nums[m]<nums[r]) {
                r = m-1;
            } else if (nums[m]>nums[r]){
                if (min>nums[r]) min = nums[r];
                l = m+1;
            } else {    //nums[m] == nums[r]时
                r--;
            }
        }
        return min;
    }

}
