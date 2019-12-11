
/**Follow up for "Find Minimum in Rotated Sorted Array":
 What if duplicates are allowed?
 Would this affect the run-time complexity? How and why?
 * Created by eugene on 16/3/12.
 */
class Solution {
public:
    ////当nums[m] = nums[r]时，无法排除一半的序列，而只能排除掉nums[r],此时只能搜寻nums[l:r-1]
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l+1<r){
            int m = l+(r-l)/2;
            if(nums[m]>nums[r]) l = m;
            else if (nums[m]<nums[r]) r = m;
            else r--;
        }
        return min(nums[l], nums[r]);
    }
};
//public class FindMinimumInRotatedSortedArrayII {
//
//    //当nums[m] = nums[r]时，无法排除一半的序列，而只能排除掉nums[r],此时只能搜寻nums[l:r-1]
//    public int findMin(int[] nums) {
//        int l = 0, r = nums.length-1;
//        while(l<r){
//            int m = l+(r-l)/2;
//            if(nums[m]>nums[r]) l = m+1;
//            else if (nums[m]<nums[r]) r = m; //TODO 此处不是r = m+1
//            else r--;
//        }
//        return nums[l];
//    }
//
//    //当nums[m] = nums[r]时，无法排除一半的序列，而只能排除掉nums[r],此时只能搜寻nums[l:r-1]
//    public int findMin1(int[] nums) {
//        int l = 0, r = nums.length - 1;
//        int m = 0;
//        int min = Integer.MAX_VALUE;
//        while (l <= r){
//            m = (l+r)/2;
//            if (min>nums[m]) min = nums[m];
//            if (nums[m]<nums[r]) {
//                r = m-1;
//            } else if (nums[m]>nums[r]){
//                if (min>nums[r]) min = nums[r];
//                l = m+1;
//            } else {    //nums[m] == nums[r]时
//                r--;
//            }
//        }
//        return min;
//    }
//
//}
