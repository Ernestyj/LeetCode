package leetcode21_30;

/**
 * Given an array and a value, remove all instances of that value in place and return the new length.
 Do not allocate extra space for another array, you must do this in place with constant memory.
 The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 Example: Given input array nums = [3,2,2,3], val = 3
 * Created by DCLab on 11/10/2015.
 */
public class RemoveElement {

    //与RemoveDuplicatesFromSortedArray
    public int removeElement(int nums[], int val) {
        int index = 0;
        for(int i=0; i<nums.length; i++)
            if(nums[i]!=val) nums[index++] = nums[i];
        return index;
    }


    public int removeElement1(int[] nums, int val) {
        if (nums == null || nums.length == 0) return 0;
        int end = nums.length - 1;
        for (int cur = 0; cur <= end; cur++){
            if (nums[cur] == val){
                for ( ; end >= cur; end--){
                    if (nums[end] != val){
                        swap(nums, cur, end);
                        end--;
                        break;
                    }
                }
            }
        }
        return end + 1;
    }
    private void swap(int[] nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
