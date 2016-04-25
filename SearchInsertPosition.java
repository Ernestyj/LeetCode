package leetcode31_40;

/**
 * Given a sorted array and a target value, return the index if the target is found.
 * If not, return the index where it would be if it were inserted in order.
 You may assume no duplicates in the array.

 Here are few examples.
 [1,3,5,6], 5 → 2
 [1,3,5,6], 2 → 1
 [1,3,5,6], 7 → 4
 [1,3,5,6], 0 → 0
 *
 * Created by DCLab on 11/18/2015.
 */
public class SearchInsertPosition {

    public static void main(String[] args) {

        int[] nums = {1,3,5,6};
        int index = new SearchInsertPosition().searchInsert(nums, 2);

        System.out.println("*****RESULT*****");
        System.out.println(index);
    }


    public int searchInsert(int[] nums, int target) {
        if (nums == null || nums.length == 0) return -1;
        int l = 0, r = nums.length - 1;
        int m = 0;
        while (l <= r){
            m = (l + r) / 2;
            if (target < nums[m]){
                r = m - 1;
            }
            else if (nums[m] < target){
                l = m + 1;
            }
            else {
                return m;
            }
        }
        // 如果没有找到目标元素，那么l一定停在恰好比target大的index上
        // r一定停在恰好比target小的index上
        return l;
    }

}
