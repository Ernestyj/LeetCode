
/**Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 Find the minimum element.
 You may assume no duplicate exists in the array.
 * 6 7 0 1 2 3 4
 * 4 5 6 7 0 1 2
 * Created by eugene on 16/3/12.
 */
class Solution {
public:
    int findMin(vector<int>& nums) {    //记忆
        int l = 0, r = nums.size()-1;
        while(l<r){
            int m = l+(r-l)/2;
            if(nums[m]<nums[r]) r = m;  //m~r有序, TODO 此处不是r = m+1
            else l = m+1;   //l~m有序
        }
        return nums[l];
    }
};
//public class FindMinimumInRotatedSortedArray {
//
//    //简洁,但是非标准二分形式
//    public int findMin(int[] nums) {
//        int l = 0, r = nums.length-1;
//        while(l<r){
//            int m = l+(r-l)/2;
//            if(nums[m]>nums[r]) l = m+1;
//            else r = m; //TODO 此处不是r = m+1
//        }
//        return nums[l];
//    }
//
//    public int findMin1(int[] nums) {
//        int l = 0, r = nums.length - 1;
//        int m = 0;
//        int min = Integer.MAX_VALUE;
//        while (l <= r){
//            m = (l+r)/2;
//            if (min>nums[m]) min = nums[m];
//            if (nums[m]<nums[r]) {
//                r = m-1;
//            } else {
//                if (min>nums[r]) min = nums[r];
//                l = m+1;
//            }
//        }
//        return min;
//    }
//
//}
