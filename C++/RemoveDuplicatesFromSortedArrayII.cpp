
/**
 * Follow up for "Remove Duplicates":
 What if duplicates are allowed at most twice?
 Note: Do not allocate extra space for another array, you must do this in place with constant memory.
 For example,
 Given sorted array nums = [1,1,1,2,2,3],
 Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3.
 It doesn't matter what you leave beyond the new length.
 * Created by DCLab on 1/1/2016.
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if(index<2 || nums[i]!=nums[index-2]) nums[index++] = nums[i];
        }
        return index;
    }
};
//public class RemoveDuplicatesFromSortedArrayII {
//
//    //简洁 tricky
//    public int removeDuplicates(int[] nums) {
//        int i = 0;
//        for (int n: nums)
//            if (i<2 || n!=nums[i-2])
//                nums[i++] = n;
//        return i;
//    }
//
//    //TODO at most K 通用解法
//    int removeDuplicates(int nums[], int n, int k) {
//        if (n <= k) return n;
//        int i = 1, j = 1;
//        int count = 1;
//        while (j < n) {
//            if (nums[j] != nums[j-1]) {
//                count = 1;
//                nums[i++] = nums[j];
//            } else {
//                if (count < k) {
//                    nums[i++] = nums[j];
//                    count++;
//                }
//            }
//            ++j;
//        }
//        return i;
//    }
//
//    /**
//     * 用index存不同数字的个数(可以含两次重复的数字)，遍历数组判断当前值是否和前一个值不一样。
//     如果不一样，就是一个新的值，更新数组并对index加1。
//     * @param nums
//     * @return
//     */
//    public int removeDuplicates1(int[] nums) {
//        if (nums == null || nums.length == 0) return 0;
//        int index = 1;
//        int count = 0;
//        for (int i=1; i<nums.length; i++){
//            if (nums[i] != nums[i-1]){
//                nums[index++] = nums[i];    //其实 index++; 即可
//                count = 0;
//            } else {
//                count++;
//                if (count < 2){
//                    nums[index++] = nums[i];    //其实 index++; 即可
//                }
//            }
//        }
//        return index;
//    }
//
//}
