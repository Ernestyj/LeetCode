package leetcode231_240;

import java.util.*;

/**Given an array nums, there is a sliding window of size k which is moving from the very left of
 the array to the very right. You can only see the k numbers in the window.
 Each time the sliding window moves right by one position.
 For example, Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
 Window position                Max
 ---------------               -----
 [1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 Therefore, return the max sliding window as [3,3,5,5,6,7].
 Note: You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.
 Follow up: Could you solve it in linear time?
 * Created by eugene on 16/5/3.
 */
public class SlidingWindowMaximum {

    /**https://segmentfault.com/a/1190000003903509
     * 双端队列维护窗口(存下标). 时间O(N) 空间O(K)
     * @param nums
     * @param k
     * @return
     */
    public int[] maxSlidingWindow(int[] nums, int k) {
        if(nums == null || nums.length == 0) return new int[0];
        int len = nums.length;
        int[] res = new int[len-k+1];
        ArrayDeque<Integer> deque = new ArrayDeque<>();
        for(int i = 0; i<len; i++){
            // 每当新数进来时，如果发现队列头部的数的下标，是窗口最左边数的下标，则扔掉
            if(!deque.isEmpty() && deque.peekFirst() == i-k) deque.poll();
            // 把队列尾部所有比新数小的都扔掉，保证队列是降序的
            while(!deque.isEmpty() && nums[deque.peekLast()]<nums[i]) deque.removeLast();
            // 加入新数
            deque.offerLast(i);
            // 队列头部就是该窗口内第一大的
            if(i+1>=k) res[i-k+1] = nums[deque.peek()];
        }
        return res;
    }

    //优先队列(堆)维护窗口. 时间O(NlogK) 空间O(K)
    public int[] maxSlidingWindow1(int[] nums, int k) {
        int len = nums.length;
        if (len==0 || k==0) return new int[0];
        int[] result = new int[len-k+1];
        PriorityQueue<Integer> queue = new PriorityQueue<>(Collections.reverseOrder());
        for (int i=0; i<k; i++){
            queue.offer(nums[i]);
        }
        result[0] = queue.peek();
        for (int i=k; i<len; i++){
            queue.remove(nums[i-k]);
            queue.offer(nums[i]);
            result[i-k+1] = queue.peek();
        }
        return result;
    }

}
