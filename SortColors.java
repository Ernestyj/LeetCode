package leetcode71_80;

/**
 * Given an array with n objects colored red, white or blue, sort them so that objects of
 * the same color are adjacent, with the colors in the order red, white and blue.
 Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 Could you come up with an one-pass algorithm using only constant space?
 * Created by DCLab on 12/27/2015.
 */
public class SortColors {

    public static void main(String[] args){
        System.out.println("*****RESULT*****");
        System.out.println();
    }


    /**
     * http://www.programcreek.com/2014/06/leetcode-sort-colors-java/
     * Since we already get the count of each element, we can directly project them to
     * the original array, instead of creating a new one.
     * @param nums
     */
    public void sortColors(int[] nums) {
        if(nums==null || nums.length<2) return;
        int[] counts = new int[3];
        for(int i=0; i<nums.length; i++) counts[nums[i]]++;
        int color = 0;  //0:red 1:white 2:blue
        int k = 0;
        while(color<=2){
            if(counts[color]!=0){
                nums[k++]=color;
                counts[color] = counts[color]-1;
            }else{
                color++;
            }
        }
    }

}
