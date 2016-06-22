package leetcode21_30;

/**
 * Given a sorted array, remove the duplicates in place such that each element appear only once
 and return the new length.
 Do not allocate extra space for another array, you must do this in place with constant memory.
 For example,
 Given input array nums = [1,1,2],
 Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
 It doesn't matter what you leave beyond the new length.
 * Created by DCLab on 11/9/2015.
 */
public class RemoveDuplicatesFromSortedArray {

    public int removeDuplicates(int[] nums) {
        int i = 0;
        for(int n : nums)
            if(i<1 || n!=nums[i-1])
                nums[i++] = n;
        return i;
    }

    public int removeDuplicates1(int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        int index = 1;
        for (int i = 1; i < nums.length; i++){
            if (nums[i] != nums[i - 1])
                nums[index++] = nums[i];
        }
        return index;
    }

}
