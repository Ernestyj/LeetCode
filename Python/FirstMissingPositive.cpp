
/**Given an unsorted integer array, find the first missing positive integer.
 For example, Given [1,2,0] return 3,
 and [3,4,-1,1] return 2.
 Your algorithm should run in O(n) time and uses constant space.
 * Created by DCLab on 11/24/2015.
 */
class Solution {
public:
    //ex. 3   4  -1  1
    //    -1  4   3  1
    //    -1  1   3  4
    //     1 -1   3  4
    int firstMissingPositive(vector<int>& nums) {//交换数组元素，使得数组中第i位存放数值(i+1)。最后遍历数组，寻找第一个不符合此要求的元素
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            while (1 <= nums[i] && nums[i] <= len && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < len; ++i) {
            if (nums[i] != i + 1) return i + 1;
        }
        return len + 1;
    }
};
//public class FirstMissingPositive {
//
//    /**交换数组元素，使得数组中第i位存放数值(i+1)。最后遍历数组，寻找第一个不符合此要求的元素，
//     * 返回这个元素。整个过程需要遍历两次数组，复杂度为O(n)。
//     * 参考图：http://www.cnblogs.com/AnnieKim/archive/2013/04/21/3034631.html
//     */
//    public int firstMissingPositive(int[] nums) {
//        int n = nums.length;
//        for(int i=0; i<n; i++) {
//            while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
//                swap(nums, i, nums[i]-1);
//        }
//        for(int i=0; i<n; i++)
//            if(nums[i] != i+1) return i+1;
//        return n+1;
//    }
//    private void swap(int[] nums, int i, int j){
//        int temp = nums[i];
//        nums[i] = nums[j];
//        nums[j] = temp;
//    }
//
//}
