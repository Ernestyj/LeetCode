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

    //快速
    public int removeElement1(int[] nums, int val) {
        int i = 0, j = nums.length-1;
        while(i<=j){
            if(nums[i]==val) {
                swap(nums, i, j);
                j--;
            }else{
                i++;
            }
        }
        return j+1;
    }
    private static void swap(int[] a, int i, int j) {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }

}
