package leetcode151_160;

/**Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 Find the minimum element.
 You may assume no duplicate exists in the array.
 * Created by eugene on 16/3/12.
 */
public class FindMinimumInRotatedSortedArray {

    public int findMin(int[] nums) {
        int l = 0, r = nums.length - 1;
        int m = 0;
        int min = Integer.MAX_VALUE;
        while (l <= r){
            m = (l+r)/2;
            if (min>nums[m]) min = nums[m];
            if (nums[m]<nums[r]) {
                r = m-1;
            } else {
                if (min>nums[r]) min = nums[r];
                l = m+1;
            }
        }
        return min;
    }

}
