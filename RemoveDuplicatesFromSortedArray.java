package leetcode21_30;

/**
 * Given a sorted array, remove the duplicates in place such that each element appear only once
 * and return the new length.

 Do not allocate extra space for another array, you must do this in place with constant memory.

 For example,
 Given input array nums = [1,1,2],
 Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
 It doesn't matter what you leave beyond the new length.
 *
 * Created by DCLab on 11/9/2015.
 */
public class RemoveDuplicatesFromSortedArray {

    public static void main(String[] args) {
        int[] nums = {-2, -1, 0, 0, 1, 2, 2, 4, 6};
//        int[] nums = {1};
        System.out.println("************************");
        int count = new RemoveDuplicatesFromSortedArray().removeDuplicates(nums);
        System.out.println(count);
        for (int i : nums) System.out.print(i + " ");
    }

    /**
     * 用index存不同数字的个数(种数)，遍历数组判断当前值是否和前一个值不一样。
     如果不一样，就是一个新的值，更新数组并对index加1。
     *
     * @param nums
     * @return
     */
    public int removeDuplicates(int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        int index = 1;
        for (int i = 1; i < nums.length; i++){
            if (nums[i] != nums[i - 1])
                nums[index++] = nums[i];    //其实 index++; 即可，赋值操作无影响（题目没有要求）
        }
        return index;
    }


    //TODO　超时
    public int removeDuplicates1(int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        int replace = 0;
        int replaceCount = 0;
        int totalReplaceCount = 0;
        int tempLength = nums.length;
        for (int i = 0; i < tempLength; i++){
            if (i > 0 && nums[i] == nums[i - 1]) {  //统计重复
                if (replaceCount == 0) replace = i;
                replaceCount++;
                totalReplaceCount++;
            }
            if (replaceCount != 0 && nums[i] != nums[i - 1]){   //遇到不同的数时，置换重复
                replaceCount = 0;
                int flag = replace; //标记位置
                for (int j = i; j < tempLength; j++){
                    nums[replace] = nums[j];
                    replace++;
                }
                tempLength = nums.length - totalReplaceCount;
                i = flag + 1;   //更新检测位置
            }
        }
        if (replaceCount != 0){ //TODO 重复数一直到结尾，截断
            return tempLength - replaceCount;
        }
        return tempLength;
    }

}
