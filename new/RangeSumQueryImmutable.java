package leetcode301_310;

/**Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

 Example:
 Given nums = [-2, 0, 3, -5, 2, -1]
 sumRange(0, 2) -> 1
 sumRange(2, 5) -> -1
 sumRange(0, 5) -> -3
 Note:
 You may assume that the array does not change.
 There are many calls to sumRange function.
 * Created by eugene on 16/6/3.
 */
public class RangeSumQueryImmutable {

    public class NumArray {
        private int[] sums;
        public NumArray(int[] nums) {
            this.sums = new int[nums.length];
            if (nums==null || nums.length==0) return;
            sums[0] = nums[0];
            for (int i=1; i<nums.length; i++){
                sums[i] = sums[i-1]+nums[i];
            }
        }

        public int sumRange(int i, int j) {
            if (i==0) return sums[j];
            return sums[j]-sums[i-1];
        }
    }

// Your NumArray object will be instantiated and called as such:
// NumArray numArray = new NumArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
}
