package leetcode71_80;

/**
 * Given an array with n objects colored red, white or blue, sort them so that objects of
 * the same color are adjacent, with the colors in the order red, white and blue.
 Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 Could you come up with an one-pass algorithm using only constant space?
 * Created by DCLab on 12/27/2015.
 */
public class SortColors {

    //https://leetcode.com/discuss/17000/share-my-one-pass-constant-space-10-line-solution
    //1-pass every elem left low pointer is 0, elem right high pointer is 2
    public void sortColors(int[] nums) {
        if(nums==null || nums.length<2) return;
        int l = 0;
        int r = nums.length-1;
        for(int i=0; i<=r; ) {
            if(nums[i]==0) { // swap nums[i] and nums[l] and i,l both ++
                swap(nums, i, l);
                i++; l++;   //TODO i也++
            }else if(nums[i]==2) { //swap nums[i] and nums[r] and r--;
                swap(nums, i, r);
                r--;    //TODO i不++
            }else {
                i++;
            }
        }
    }
    private static void swap(int[] a, int i, int j) {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }

    /**
     * http://www.programcreek.com/2014/06/leetcode-sort-colors-java/
     * Since we already get the count of each element, we can directly project them to
     * the original array, instead of creating a new one.
     * @param nums
     */
    public void sortColors1(int[] nums) {
        if(nums==null || nums.length<2) return;
        int[] counts = new int[3];
        for(int i=0; i<nums.length; i++) counts[nums[i]]++;
        int color = 0;  //0:red 1:white 2:blue
        int k = 0;
        while(color<=2){
            if(counts[color]!=0){
                nums[k++] = color;
                counts[color]--;
            }else{
                color++;
            }
        }
    }

}
