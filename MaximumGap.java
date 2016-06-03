package leetcode161_170;

/**Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
 Try to solve it in linear time/space.
 Return 0 if the array contains less than 2 elements.
 You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
 * Created by eugene on 16/3/16.
 */
public class MaximumGap {

    //用例[5,9,8,3,15] 排序后为：[3,5,8,9,15]  TODO 注意桶大小和索引计算方法,变体
    /**https://leetcode.com/discuss/94724/beat-99-81%25-java-coder
     * 假设有N个元素A到B, 那么最大差值不会小于ceiling[(B-A) / (N-1)]
     令bucket的大小gap = ceiling[(B-A) / (N-1)]，则最多会有(B-A)/gap + 1个桶
     对于数组中的任意整数K，很容易通过算式index = (K-A)/gap找出其桶的位置，然后维护每一个桶的最大值和最小值.
     由于同一个桶内的元素之间的差值至多为gap-1，因此最终答案不会从同一个桶中选择。
     对于每一个非空的桶p，找出下一个非空的桶q，则q.min - p.max可能就是备选答案, 返回所有这些可能值中的最大值。
     * @param nums
     * @return
     */
    public int maximumGap(int[] nums) {
        int N = nums.length;
        if(N < 2) return 0;
        int min = nums[0];
        int max = nums[0];
        for(int i=1; i<N; i++){
            if(min>nums[i]) min = nums[i];
            if(max<nums[i]) max = nums[i];
        }
        int gap = (max-min)/(N-1);
        if(gap==0) gap++; //TODO 注意
        int bucketN = (max-min)/gap+1;
        int[] bucketMax = new int [bucketN];
        int[] bucketMin = new int [bucketN];
        for(int i=0; i<N; i++){
            int index = (nums[i]-min)/gap;
            if(nums[i]>bucketMax[index]) bucketMax[index] = nums[i];
            if(bucketMin[index]==0 || nums[i]<bucketMin[index]) bucketMin[index] = nums[i];
        }
        int maxGap = 0;
        int pre = min;
        for(int i=0; i<bucketN; i++){
            if(maxGap < bucketMin[i]-pre) maxGap = bucketMin[i]-pre;
            if(bucketMax[i]!=0) pre = bucketMax[i];     //非空条件
        }
        return maxGap;
    }


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
    public int maximumGap1(int[] nums) {
        if(nums == null || nums.length < 2) return 0;
        int len = nums.length;
        int min = nums[0], max = nums[0];
        for(int i=1; i<len; i++){
            max = Math.max(max, nums[i]);
            min = Math.min(min, nums[i]);
        }
        Bucket[] buckets = new Bucket[len+1]; //project to (0 - n)
        for(int i=0; i<buckets.length; i++){
            buckets[i] = new Bucket();
        }
        double interval = (double)len / (max - min);
        for(int i=0; i<len; i++){
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
