package leetcode71_80;

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
public class RemoveDuplicatesFromSortedArrayII {


    public static void main(String[] args) {
        int[] nums = {-2, -1, 0, 0, 1, 2, 2, 4, 6};
//        int[] nums = {1};
        System.out.println("************************");
        int count = new RemoveDuplicatesFromSortedArrayII().removeDuplicates(nums);
        System.out.println(count);
        for (int i : nums) System.out.print(i + " ");
    }


    /**
     * 用index存不同数字的个数(可以含两次重复的数字)，遍历数组判断当前值是否和前一个值不一样。
     如果不一样，就是一个新的值，更新数组并对index加1。
     * @param nums
     * @return
     */
    public int removeDuplicates(int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        int index = 1;
        int count = 0;
        for (int i=1; i<nums.length; i++){
            if (nums[i] != nums[i-1]){
                nums[index++] = nums[i];    //其实 index++; 即可
                count = 0;
            } else {
                count++;
                if (count < 2){
                    nums[index++] = nums[i];    //其实 index++; 即可
                }
            }
        }
        return index;
    }

}
