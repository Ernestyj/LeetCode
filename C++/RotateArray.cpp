

/**Rotate an array of n elements to the right by k steps.
 For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
 Note: Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
 Hint: Could you do it in-place with O(1) extra space?
 * Created by eugene on 16/3/26.
 */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k %= len;
        if(nums.empty() || k%len == 0) return;
        reverse(nums.begin(), nums.begin()+len-k);
        reverse(nums.begin()+len-k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

//public class RotateArray {
//
//    /**
//     * O(1) space and in O(n) time.
//     Assuming we are given {1,2,3,4,5,6} and order 2. The basic idea is:
//     1. Divide the array two parts: 1,2,3,4 and 5, 6
//     2. Rotate first part: 4,3,2,1,5,6
//     3. Rotate second part: 4,3,2,1,6,5
//     4. Rotate the whole array: 5,6,1,2,3,4
//     或者 6,5,4,3,2,1 -> 5,6|1,2,3,4 (代码简洁)
//     http://www.programcreek.com/2015/03/rotate-array-in-java/
//     * @param nums
//     * @param k
//     */
//    public void rotate(int[] nums, int k) {
//        k = k%nums.length;
//        if (k==0) return;
//        reverse(nums, 0, nums.length - 1);
//        reverse(nums, 0, k - 1);
//        reverse(nums, k, nums.length - 1);
//    }
//    private void reverse(int[] nums, int start, int end){
//        while (start < end) {
//            int temp = nums[start];
//            nums[start] = nums[end];
//            nums[end] = temp;
//            start++;
//            end--;
//        }
//    }
//
//}
