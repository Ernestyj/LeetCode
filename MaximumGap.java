package leetcode161_170;

/**Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
 Try to solve it in linear time/space.
 Return 0 if the array contains less than 2 elements.
 You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
 * Created by eugene on 16/3/16.
 */
public class MaximumGap {

    class Bucket{
        int low;
        int high;
        public Bucket(){
            low = -1;
            high = -1;
        }
    }

    /**http://www.programcreek.com/2014/03/leetcode-maximum-gap-java/
     * 桶排序:区间计算interval = num.length / (max - min),桶索引0~n.
     索引计算index = (int) ((nums[i] - min) * interval)
     * @param nums
     * @return
     */
    public int maximumGap(int[] nums) {
        if(nums == null || nums.length < 2) return 0;
        int min = nums[0], max = nums[0];
        for(int i=1; i<nums.length; i++){
            max = Math.max(max, nums[i]);
            min = Math.min(min, nums[i]);
        }
        Bucket[] buckets = new Bucket[nums.length+1]; //project to (0 - n)
        for(int i=0; i<buckets.length; i++){
            buckets[i] = new Bucket();
        }
        double interval = (double)nums.length / (max - min);
        for(int i=0; i<nums.length; i++){
            int index = (int) ((nums[i] - min) * interval);
            if(buckets[index].low == -1){
                buckets[index].low = nums[i];
                buckets[index].high = nums[i];
            }else{
                buckets[index].low = Math.min(buckets[index].low, nums[i]);
                buckets[index].high = Math.max(buckets[index].high, nums[i]);
            }
        }
        int maxGap = 0;
        int prev = buckets[0].high;
        for(int i=1; i<buckets.length; i++){
            if(buckets[i].low != -1){
                maxGap = Math.max(maxGap, buckets[i].low-prev);
                prev = buckets[i].high;
            }

        }
        return maxGap;
    }
}
