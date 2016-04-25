package leetcode21_30;

/**
 * Given an array and a value, remove all instances of that value in place and return the new length.
 *
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 *
 * Created by DCLab on 11/10/2015.
 */
public class RemoveElement {

    public static void main(String[] args) {
        int[] nums = {-2, -1, 0, 0, 1, 2, 2, 4, 6};

        System.out.println("*****RESULT*****");
        int count = new RemoveElement().removeElement(nums, 6);
        System.out.println(count);
        for (int i : nums) System.out.print(i + " ");
    }

    public int removeElement(int[] nums, int val) {
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
