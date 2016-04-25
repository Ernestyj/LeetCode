package leetcode41_50;

/**
 * Given an unsorted integer array, find the first missing positive integer.
 For example,
 Given [1,2,0] return 3,
 and [3,4,-1,1] return 2.
 Your algorithm should run in O(n) time and uses constant space.
 * Created by DCLab on 11/24/2015.
 */
public class FirstMissingPositive {

    public static void main(String[] args) {
        int[] nums = {3,-1,23,7,21,12,8,9,18,21,-1,16,1,13,-3,22,23,13,7,14,3,6,4,-3};
        System.out.println("*****RESULT*****");
        int result = new FirstMissingPositive().firstMissingPositive(nums);
        System.out.println(result);
    }


    /**
     * 交换数组元素，使得数组中第i位存放数值(i+1)。最后遍历数组，寻找第一个不符合此要求的元素，
     * 返回这个元素。整个过程需要遍历两次数组，复杂度为O(n)。
     * 参考图：http://www.cnblogs.com/AnnieKim/archive/2013/04/21/3034631.html
     * @param nums
     * @return
     */
    public int firstMissingPositive(int[] nums) {
        if (nums == null || nums.length == 0) return 1;
        int i = 0;
        while (i < nums.length){    //这里不使用for循环
            if (nums[i] > 0 && nums[i] < nums.length && nums[i] != i + 1 &&
                    nums[nums[i] - 1] != nums[i]){ //TODO 此条件易漏，否则进入无限循环
                swap(nums, i, nums[i] - 1);
            } else i++;
        }
        for (i = 0; i < nums.length; i++){
            if (nums[i] != i + 1) return i + 1;
        }
        return i + 1;
    }
    private void swap(int[] nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

}
